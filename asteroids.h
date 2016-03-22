#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#define MAX_ASTEROIDS 50
#define MIN_ASTEROIDS 4
#define MAX_MISSILES 50

#define LARGE_ASTEROID_RADIUS 3
#define MEDIUM_ASTEROID_RADIUS 2
#define SMALL_ASTEROID_RADIUS 1
#define MAX_ASTEROID_SPEED 1

#define MISSILE_SPEED 1
#define MISSILE_RADIUS 1
#define MISSILE_LIFE 1

#define SHIP_START_X 0
#define SHIP_START_Y 0
#define SHIP_START_ROTATION 0
#define SHIP_RADIUS 1
#define SHIP_ACCEL 1

#define NUM_LIVES 3

#define SIDE_RIGHT 0
#define SIDE_LEFT 1
#define SIDE_TOP 2
#define SIDE_BOTTOM 3

//Populated by the control task and used to modify the game model
typedef struct controller_t {
  uint16_t accel_data;
  uint16_t gyro_data;
  bool trigger_button;
  bool aux_button;
} Controller_t;

//Stores the information defining a single asteroid
typedef struct asteroid_t {
  bool empty;
  int x_pos;
  int y_pos;
  int x_speed;
  int y_speed;
  int radius;
} Asteroid_t;

//Stores the information defining a single missile
typedef struct missile_t {
  bool empty;
  int x_pos;
  int y_pos;
  int x_speed;
  int y_speed;
  int radius;
  int life;
} Missile_t;

//Stores the information defining the player's ship
typedef struct ship_t {
  int x_pos;
  int y_pos;
  int x_speed;
  int y_speed;
  int radius;
  int rotation;
} Ship_t;

//Populated by the game task and used to modify the view
typedef struct game_model_t {
  bool main_menu;
  bool end_game_menu;
  bool pause_menu;
  Asteroid_t asteroids[MAX_ASTEROIDS];
  Missile_t missiles[MAX_MISSILES];
  Ship_t ship;
  int lives;
  int score;
  int x;
  int y;
} Game_Model_t;

//Starts the asteroids task. Takes the same Controller_t instance as
//the controller task
void asteroids_start(int x, int y);

#endif
