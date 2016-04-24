#ifndef ASTEROIDS_H
#define ASTEROIDS_H

#include <stdbool.h>
#include "models.h"

//Software constants - don't change
#define SIDE_RIGHT 0
#define SIDE_LEFT 1
#define SIDE_TOP 2
#define SIDE_BOTTOM 3

#define STATE_MAIN_MENU 0
#define STATE_PLAYING 1
#define STATE_PAUSE_MENU 2
#define STATE_END_GAME_MENU 3

//Game constants - feel free to change
#define MAX_ASTEROIDS 50
#define MIN_ASTEROIDS 4
#define MAX_MISSILES 50

#define LARGE_ASTEROID_RADIUS 5
#define MEDIUM_ASTEROID_RADIUS 3
#define SMALL_ASTEROID_RADIUS 2
#define MAX_ASTEROID_SPEED 3
#define ASTEROID_ANGLE 15

#define MISSILE_SPEED 3
#define MISSILE_RADIUS 1
#define MISSILE_LIFE 150

#define SHIP_START_ROTATION 0
#define SHIP_RADIUS 3
#define SHIP_ACCEL_CONSTANT 10
#define SHIP_ROLL_CONSTANT 10
#define SHIP_DECCEL_CONSTANT 1 //Larger number = less decceleration (not zero)
#define SHIP_INVINCIBILITY_LENGTH 5

#define NUM_LIVES 3
#define BREAK_ASTEROID_SCORE 100

//Populated by the control task and used to modify the game model
typedef struct controller_t {
  int roll;
  int pitch;
  bool trigger_button;
  bool aux_button;
} Controller_t;

//Stores the information defining a single asteroid
typedef struct asteroid_t {
  bool empty;
  float x_pos;
  float y_pos;
  float x_speed;
  float y_speed;
  int radius;
  Object_Model_t* model;
} Asteroid_t;

//Stores the information defining a single missile
typedef struct missile_t {
  bool empty;
  double x_pos;
  double y_pos;
  double x_speed;
  double y_speed;
  int radius;
  int life;
  Object_Model_t* model;
} Missile_t;

//Stores the information defining the player's ship
typedef struct ship_t {
  double x_pos;
  double y_pos;
  double x_speed;
  double y_speed;
  int radius;
  int rotation;
  bool accelerating;
  int invincible;
  Object_Model_t* model;
} Ship_t;

//Populated by the game task and used to modify the view
typedef struct game_model_t {
  int state;
  Asteroid_t asteroids[MAX_ASTEROIDS];
  Missile_t missiles[MAX_MISSILES];
  Ship_t ship;
  int lives;
  int score;
  int level;
  int x;
  int y;
  Object_Model_t* model;
} Game_Model_t;

//Starts the asteroids task. Takes the same Controller_t instance as
//the controller task
void asteroids_init(Game_Model_t* model, int x, int y);
void asteroids_main(Game_Model_t* model, Controller_t* controller);

#endif
