#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "asteroids.h"
#include "models.h"

//Resets the game model
static void reset_game(Game_Model_t* model) {
  int i;
  for (i = 0; i < MAX_ASTEROIDS; i++) {
    (model->asteroids[i]).empty = true;
  }
  
  for (i = 0; i < MAX_MISSILES; i++) {
    (model->missiles[i]).empty = true;
  }

  (model->ship).x_pos = (model->x) / 2;
  (model->ship).y_pos = (model->y) / 2;
  (model->ship).x_speed = 0;
  (model->ship).y_speed = 0;
  (model->ship).radius = SHIP_RADIUS;
  (model->ship).rotation = SHIP_START_ROTATION;
  (model->ship).invincible = 0;

  model->lives = NUM_LIVES;
  model->score = 0;
  model->level = 0;
}

//Returns a Controller_t structure from the control queue
static void get_from_control_queue(Controller_t* controller) {
  int roll;
  int pitch;
  int aux_button;
  int trigger_button;

  printf("Roll: ");
  scanf("%d", &roll);

  printf("Pitch: ");
  scanf("%d", &pitch);

  printf("trigger_button: ");
  scanf("%d", &trigger_button);

  printf("aux_button: ");
  scanf("%d", &aux_button);

  controller->roll = roll;
  controller->pitch = pitch;
  controller->trigger_button = trigger_button;
  controller->aux_button = aux_button;
}

//Creates a single asteroid in the game model
//
//Parameters:
//  m - a pointer to the game model
//  radius - the radius of the asteroid. Use the defined macros
//  x - x position
//  y - y position
//  x_s - x speed
//  y_s - y speed
//
//Returns true if the asteroid was created successfully and false 
//otherwise
int create_asteroid(Game_Model_t* m, int radius, double x, double y, double x_s, double y_s) {

  //Find open asteroid slot in data structure
  int i; 
  for (i = 1; i <= MAX_ASTEROIDS; i++) {
    if ((m->asteroids[i-1]).empty) {
      (m->asteroids[i-1]).empty = false;
      (m->asteroids[i-1]).x_pos = x;
      (m->asteroids[i-1]).y_pos = y;
      (m->asteroids[i-1]).x_speed = x_s;
      (m->asteroids[i-1]).y_speed = y_s;
      (m->asteroids[i-1]).radius = radius;

      if (radius == LARGE_ASTEROID_RADIUS) {
    	set_object_model(&(m->asteroids[i-1].model), TYPE_LARGE_ASTEROID);
      } else if (radius == MEDIUM_ASTEROID_RADIUS) {
    	set_object_model(&(m->asteroids[i-1].model), TYPE_MEDIUM_ASTEROID);
      } else {
    	set_object_model(&(m->asteroids[i-1].model), TYPE_SMALL_ASTEROID);
      }

      return i;
    }
  }

  return 0;
}

//Resets the asteroid field after a player has destroyed all asteroids 
//on the screen. The number of asteroids is directly related to the level.
//Assume there are no more asteroids in the model.
static void level_up(Game_Model_t* model) {
  int i, angle, side, speed;
  double x, y, x_s, y_s;

  model->level++;
  int num_asteroids = MIN_ASTEROIDS + (model->level / 2);

  for (i = 0; i < num_asteroids; i++) {
    //Generate number 0 through 3 (associated with side of screen)
    side = rand() % 4;

    //Determine the x (or y) position based on the side
    switch (side) {
      case SIDE_RIGHT:
        x = model->x;
        break;

      case SIDE_LEFT:
        x = 0;
        break;

      case SIDE_TOP:
        y = model->y;
        break;

      case SIDE_BOTTOM:
      default:
        y = 0;
        break;
    }

    //Generate number 1 through model->x (or model->y)
    if (side == SIDE_RIGHT || side == SIDE_LEFT) {
      y = rand() % model->y;       
    } else {
      x = rand() % model->x; 
    }

    //Generate random speed
    speed = (rand() % MAX_ASTEROID_SPEED) + 1;

    //Generate random direction
    angle = rand() % 360;
    
    //Convert random speed into x_s and y_s
    x_s = sin((double)angle * M_PI / 180.0) * (double)speed;
    y_s = -cos((double)angle * M_PI / 180.0) * (double)speed;

    create_asteroid(model, LARGE_ASTEROID_RADIUS, x, y, x_s, y_s); 
  }
}

//Creates a missile from the nose of the ship in the same direction which
//the ship is oriented. The speed is defined in the associated header file
static int create_missile(Game_Model_t* model) {
  //Check if there is enough room for a new missile
  int i;
  for (i = 1; i <= MAX_MISSILES; i++) {
    if ((model->missiles[i-1]).empty) {
      Missile_t m;

      //Claim this spot in the data structure 
      m.empty = false;
      
      //Calculate x and y positions
      Ship_t s = model->ship;
      m.x_pos = s.x_pos + sin((double)s.rotation * M_PI/180.0) * s.radius;
      m.y_pos = s.y_pos + -cos((double)s.rotation * M_PI/180.0) * s.radius;

      //Calculate x and y speeds
      m.x_speed = sin((double)s.rotation * M_PI/180.0) * MISSILE_SPEED;
      m.y_speed = -cos((double)s.rotation * M_PI/180.0) * MISSILE_SPEED;

      //Fill other missile parameters
      m.radius = MISSILE_RADIUS;
      m.life = MISSILE_LIFE;

      //Set the missile model
      set_object_model(&(m.model), TYPE_MISSILE);

      (model->missiles[i-1]) = m;

      //Return true
      return i;
    }
  }

  //Return false if a new missile could not be created
  return 0;
}

//Wraps the object to the other side of the screen
static void wrap(Game_Model_t* m, double* x, double* y, int radius) {
  if (*x < 0 - radius) {
    *x = m->x;

  } else if (*x > m->x + radius) {
    *x = 0;
  } 
  
  if (*y < 0 - radius) {
    *y = m->y;

  } else if (*y > m->y + radius) {
    *y = 0;
  }
}

//Move the player ship by using the controller struct. The ship does not 
//move at a static speed. Instead, it accelerates in the direction it 
//is oriented and decelerates gradually over time when the thrusters are
//not on. 
//
//Implement a deadband in the controller so that it is possible to have 0
//acceleration
static void move_player_ship(Game_Model_t* m, Controller_t* c) {
  //Calculate the orientation of the controller
  int roll = c->roll;
  double pitch = (double)c->pitch;
  //calculate_roll_pitch(c, &roll, &pitch);

  //Change orientation based on roll
  (m->ship).rotation += (roll / SHIP_ROLL_CONSTANT);
  while ((m->ship).rotation > 360) {
	  (m->ship).rotation -= 360;
  }
  while ((m->ship).rotation < 0) {
	  (m->ship).rotation += 360;
  }

  //Change position based on speed
  (m->ship).x_pos += (m->ship).x_speed;
  (m->ship).y_pos += (m->ship).y_speed;
  wrap(m, &((m->ship).x_pos), &((m->ship).y_pos), SHIP_RADIUS);
  
  //Determine acceleration based on pitch and orientation
  double a_tot = pitch / SHIP_ACCEL_CONSTANT;
  double accel_x = sin((m->ship).rotation*M_PI/180.0)*a_tot;
  double accel_y = -cos((m->ship).rotation*M_PI/180.0)*a_tot;
  (m->ship).accelerating = (a_tot != 0);

  //Add decceleration and acceleration into speed 
  (m->ship).x_speed = ((m->ship).x_speed / SHIP_DECCEL_CONSTANT) + accel_x;
  (m->ship).y_speed = ((m->ship).y_speed / SHIP_DECCEL_CONSTANT) + accel_y;
}

//Move asteroids. Uses asteroids' speed parameter in the Asteroid_t struct
//Wraps asteroid to other side of screen if it escapes the game model
static void move_asteroids(Game_Model_t* m) {
  int i;
  for (i = 0; i < MAX_ASTEROIDS; i++) {
    if ((m->asteroids[i]).empty) {
      continue;
    }

    //Calculate new position of asteroid
    (m->asteroids[i]).x_pos += (m->asteroids[i]).x_speed;
    (m->asteroids[i]).y_pos += (m->asteroids[i]).y_speed;

    //If an asteroid is out of bounds, wrap it to other side of screen
    wrap(m, &((m->asteroids[i]).x_pos), &((m->asteroids[i]).y_pos), (m->asteroids[i]).radius);
  }
}


//Move missiles. Uses missiles' speed parameter in the Missile_t struct
//Wraps missile to other side of screen if it escapes the game screen
//Decrements life of missiles so that they are not infinite
static void move_missiles(Game_Model_t* m) {
  int i;
  for (i = 0; i < MAX_MISSILES; i++) {
    if ((m->missiles[i]).empty) {
      continue;
    }

    //Remove missiles if they have been in the game too long
    if ((m->missiles[i]).life == 0) {
      (m->missiles[i]).empty = true;

    //Calculate new positions of missiles
    } else {
      (m->missiles[i]).x_pos += (m->missiles[i]).x_speed;
      (m->missiles[i]).y_pos += (m->missiles[i]).y_speed;

      //If a missile is out of bounds, wrap it to other side of screen
      wrap(m, &((m->missiles[i]).x_pos), &((m->missiles[i]).y_pos), MISSILE_RADIUS);

      //Decrement missile lifetime
      (m->missiles[i]).life--;
    }
  }
}

//Returns true if object 1 and object 2 are colliding
static bool collision(int xpos1, int ypos1, int rad1, 
                      int xpos2, int ypos2, int rad2) {

  //Determine distance between position 1 and 2
  double dist_x = (double)xpos1 - (double)xpos2;
  double dist_y = (double)ypos1 - (double)ypos2;
  int dist = (int)sqrt(pow(dist_x, 2) + pow(dist_y, 2));

  int radsum;
  radsum = rad1 + rad2;
  if(dist < radsum) return true;
  else return false;


  //If dist is smaller than the radii, return tru
  //return dist < (rad1 + rad2);
}

//Reduces the lives variable in the model by 1, destroys the ship, and 
//checks for the end of the game. This function sets the boolean variable
//model->end_game_menu if appropriate, and then resets the game model. 
static void lose_life(Game_Model_t* model) {
  //Reduce life by 1
  model->lives--;

  //Reset ship to center
  (model->ship).x_pos = model->x / 2;
  (model->ship).y_pos = model->y / 2;
  (model->ship).x_speed = 0;
  (model->ship).y_speed = 0;
  (model->ship).rotation = 0;

  //Make ship invincible for a few moments
  (model->ship).invincible = SHIP_INVINCIBILITY_LENGTH;

  //Check if game is lost
  if (model->lives == 0) {
    model->state = STATE_END_GAME_MENU;
    set_object_model(&(model->model), TYPE_END_GAME_MENU);
  }
}

//Removes the asteroids and creates two new children asteroids in its 
//place. If there is not enough room in the model->asteroids array, only
//one child asteroid can be created.
static void break_asteroid(Game_Model_t* model, Asteroid_t* asteroid) {
  //Get important information from parent asteroid
  double parent_x = asteroid->x_pos;
  double parent_y = asteroid->y_pos;
  double parent_x_speed = asteroid->x_speed;
  double parent_y_speed = asteroid->y_speed;
  double parent_r = asteroid->radius;
  
  //Destroy parent asteroid
  asteroid->empty = true;
  
  //Determine size of new asteroids
  int child_r;
  if (parent_r == LARGE_ASTEROID_RADIUS) {
    child_r = MEDIUM_ASTEROID_RADIUS;
  } else if (parent_r == MEDIUM_ASTEROID_RADIUS) {
    child_r = SMALL_ASTEROID_RADIUS;
  } else {
    child_r = 0;
  }
  
  //Create new asteroids if needed
  if (child_r != 0) {
    //Randomly generate speeds
    double s1 = (rand() % MAX_ASTEROID_SPEED) + 1;
    double s2 = (rand() % MAX_ASTEROID_SPEED) + 1;

    //Calculate the angle of the parent's travel
    int p_angle;
    if (parent_y_speed == 0) {
      p_angle = rand() % 360;
    } else {
      p_angle = (int)(atan(parent_x_speed / parent_y_speed) * 180 / M_PI);
    }

    //Randomly generate angles within 30 degrees of parent's angle
    int theta1 = (p_angle-ASTEROID_ANGLE) + (rand() % (ASTEROID_ANGLE*2));
    int theta2 = (p_angle-ASTEROID_ANGLE) + (rand() % (ASTEROID_ANGLE*2));

    //Calculate x_speed and y_speed for both asteroids
    double x_s1 = sin((double)theta1 * M_PI / 180.0) * (double)s1;
    double y_s1 = -cos((double)theta1 * M_PI / 180.0) * (double)s1;
    double x_s2 = sin((double)theta2 * M_PI / 180.0) * (double)s2;
    double y_s2 = -cos((double)theta2 * M_PI / 180.0) * (double)s2;

    //Create the asteroids
    create_asteroid(model, child_r, parent_x, parent_y, x_s1, y_s1);
    create_asteroid(model, child_r, parent_x, parent_y, x_s2, y_s2);
  }
}

//Increments the game by one frame
void game_tick(Game_Model_t* model, Controller_t* controller) {
  //Pause game menu
  if (model->state == STATE_PAUSE_MENU) {
    if (controller->trigger_button) {
      model->state = STATE_PLAYING;
      set_object_model(&(model->model), TYPE_PLAYING);

    } else if (controller->aux_button) {
      model->state = STATE_END_GAME_MENU;
      set_object_model(&(model->model), TYPE_END_GAME_MENU);
    }

    return;
  }

  //Determine if the game needs to be paused
  if (controller->aux_button) {
    model->state = STATE_PAUSE_MENU;
    set_object_model(&(model->model), TYPE_PAUSE_GAME_MENU);
    return;
  }

  //Create asteroids if screen is empty
  int i;
  bool empty = true;
  for (i = 0; i < MAX_ASTEROIDS; i++) {
    if (!(model->asteroids[i]).empty) {
      empty = false;
      break;
    }
  }
  if (empty) {
    level_up(model);
  }

  //Move stuff
  move_player_ship(model, controller);
  move_asteroids(model);
  move_missiles(model);
  
  //Create missiles
  if (controller->trigger_button) {
    create_missile(model);
  }

  //Check for collisions
  int j;
  Asteroid_t a;
  Missile_t m;
  Ship_t s;
  bool in_collision_list = false;
  Asteroid_t* collision_list[MAX_ASTEROIDS] = { NULL };
  int collision_list_index = 0;

  //Cycle through each asteroid
  for (i = 0; i < MAX_ASTEROIDS; i++) {
    a = model->asteroids[i];
    in_collision_list = false;

    //Ignore any positions in the array that aren't initialized
    if (a.empty) {
      continue;
    }
 
    //Check if asteroids have collided with a missile
    for (j = 0; j < MAX_MISSILES; j++) {
      m = model->missiles[j];
      if (m.empty) {
        continue;
      }
      if (collision(m.x_pos, m.y_pos, m.radius, 
                    a.x_pos, a.y_pos, a.radius)) {

        collision_list[collision_list_index++] = &(model->asteroids[i]);
        in_collision_list = true; 
        (model->missiles[j]).empty = true;
        model->score += BREAK_ASTEROID_SCORE;
        continue;
      }
    }

    //Check for ship collisions
    s = model->ship;
    if (!s.invincible && collision(s.x_pos, s.y_pos, s.radius, 
      a.x_pos, a.y_pos, a.radius)) {

      if (!in_collision_list) {
        collision_list[collision_list_index++] = &(model->asteroids[i]);
        in_collision_list = true;
      }
      model->score += BREAK_ASTEROID_SCORE;
      lose_life(model);
    }
  }

  //Turn off invincibility in due time
  if ((model->ship).invincible) {
    (model->ship).invincible--; 
  }
  
  //Destroy asteroids in collision_list
  for (i = 0; i < MAX_ASTEROIDS; i++) {
    if (collision_list[i] == NULL) {
      continue;
    }
    
    break_asteroid(model, collision_list[i]);
  }
}

//Initializes a game of asteroids. Must be called before asteroids_main
void asteroids_init(Game_Model_t* model, int x, int y) {
	model->x = x;
	model->y = y;

	init_models();

	model->state = STATE_MAIN_MENU;
	set_object_model(&(model->model), TYPE_MAIN_MENU);

	set_object_model(&((model->ship).model), TYPE_SHIP);

	reset_game(model);
}

//Initializes and plays a game of asteroids
//x and y parameters are the desired dimensions of the screen
void asteroids_main(Game_Model_t* model, Controller_t* controller) {
	//Make sure that a long button click does not register multiple clicks
	static int first = 1;
	static Controller_t* last_frame_controller;

	if (!first) {
	  bool temp = controller->aux_button;
	  if (last_frame_controller->aux_button) {
		  controller->aux_button = false;
	  }
	  last_frame_controller->aux_button = temp;

	  temp = controller->trigger_button;
	  if (last_frame_controller->trigger_button) {
		  controller->trigger_button = false;
	  }
	  last_frame_controller->trigger_button = temp;
	}

	first = 0;

	//----------Main menu logic-------------------------------------
	if (model->state == STATE_MAIN_MENU) {
	  //If trigger button is pressed, start game
	  if (controller->trigger_button) {
	    //Keep booleans and memory allocated, but reset score and objects
	    reset_game(model);

	    model->state = STATE_PLAYING;
		set_object_model(&(model->model), TYPE_PLAYING);
	  }

	//----------Pause menu logic-----------------------------------
	} else if (model->state == STATE_PAUSE_MENU) {
	  //If trigger button is pressed, return to game
	  if (controller->trigger_button) {
		model->state = STATE_PLAYING;
		set_object_model(&(model->model), TYPE_PLAYING);
	  }

	  //If aux button is pressed, quit game
	  if (controller->aux_button) {
		model->state = STATE_END_GAME_MENU;
		set_object_model(&(model->model), TYPE_END_GAME_MENU);
	  }

	//----------End game menu logic--------------------------------
	} else if (model->state == STATE_END_GAME_MENU) {
	  //Continue if any button is pressed
	  if (controller->trigger_button | controller->aux_button) {
		model->state = STATE_MAIN_MENU;
		set_object_model(&(model->model), TYPE_MAIN_MENU);
	  }

	//----------Game logic------------------------------------------
	} else {
	  srand(controller->pitch);
	  game_tick(model, controller);
	}
}
