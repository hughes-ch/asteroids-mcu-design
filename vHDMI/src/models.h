/*
 * models.h
 *
 *  Created on: Apr 2, 2016
 *      Author: Chris
 */

#ifndef MODELS_H_
#define MODELS_H_

#define MAX_MODEL_SIZE 100

#define TYPE_LARGE_ASTEROID  0
#define TYPE_MEDIUM_ASTEROID 1
#define TYPE_SMALL_ASTEROID  2
#define TYPE_MISSILE         3
#define TYPE_SHIP            4
#define TYPE_MAIN_MENU       5
#define TYPE_END_GAME_MENU   6
#define TYPE_PAUSE_GAME_MENU 7
#define TYPE_PLAYING         8
#define TYPE_LABEL_LIVES     9
#define TYPE_LABEL_SCORE     10
#define TYPE_CHARACTER_0     11
#define TYPE_CHARACTER_1     12
#define TYPE_CHARACTER_2     13
#define TYPE_CHARACTER_3     14
#define TYPE_CHARACTER_4     15
#define TYPE_CHARACTER_5     16
#define TYPE_CHARACTER_6     17
#define TYPE_CHARACTER_7     18
#define TYPE_CHARACTER_8     19
#define TYPE_CHARACTER_9     20

//Stores one x, y position
typedef struct position_t {
  int x;
  int y;
} Position_t;

//Stores information about the object's display on screen
typedef struct model_t {
  int num;
  Position_t positions[MAX_MODEL_SIZE];
} Object_Model_t;

#define LARGE_ASTEROID_NUM_POSITIONS 13
static Position_t large_asteroid_model[LARGE_ASTEROID_NUM_POSITIONS] = {(Position_t){6, -5},
																		(Position_t){10, -7},
																		(Position_t){7, -9},
																		(Position_t){0, -7},
																		(Position_t){-7, -9},
																		(Position_t){-10, -7},
																		(Position_t){-8, 0},
																		(Position_t){-10, 3},
																		(Position_t){-7, 9},
																		(Position_t){-6, 7},
																		(Position_t){6, 9},
																		(Position_t){10, 3},
																		(Position_t){6, -5}};

#define MEDIUM_ASTEROID_NUM_POSITIONS 1
static Position_t medium_asteroid_model[MEDIUM_ASTEROID_NUM_POSITIONS] = {(Position_t){0, 0}};

#define SMALL_ASTEROID_NUM_POSITIONS 1
static Position_t small_asteroid_model[SMALL_ASTEROID_NUM_POSITIONS] = {(Position_t){0, 0}};

#define MISSILE_NUM_POSITIONS 1
static Position_t missile_model[MISSILE_NUM_POSITIONS] = {(Position_t){0, 0}};

#define SHIP_NUM_POSITIONS 4
static Position_t ship_model[SHIP_NUM_POSITIONS] = {(Position_t){-5, 5},
												(Position_t){5, 5},
												(Position_t){0, -5},
												(Position_t){-5, 5}};

#define MAIN_MENU_NUM_POSITIONS 1
static Position_t main_menu_model[MAIN_MENU_NUM_POSITIONS] = {(Position_t){0, 0}};

#define END_GAME_MENU_NUM_POSITIONS 1
static Position_t end_game_menu_model[END_GAME_MENU_NUM_POSITIONS] = {(Position_t){0, 0}};

#define PAUSE_GAME_MENU_NUM_POSITIONS 1
static Position_t pause_game_menu_model[PAUSE_GAME_MENU_NUM_POSITIONS] = {(Position_t){0, 0}};

#define PLAYING_NUM_POSITIONS 1
static Position_t playing_model[PLAYING_NUM_POSITIONS] = {(Position_t){0, 0}};

#define LABEL_LIVES_NUM_POSITIONS 1
static Position_t label_lives_model[LABEL_LIVES_NUM_POSITIONS] = {(Position_t){0, 0}};

#define LABEL_SCORE_NUM_POSITIONS 1
static Position_t label_score_model[LABEL_SCORE_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_0_NUM_POSITIONS 1
static Position_t character_0_model[CHARACTER_0_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_1_NUM_POSITIONS 1
static Position_t character_1_model[CHARACTER_1_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_2_NUM_POSITIONS 1
static Position_t character_2_model[CHARACTER_2_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_3_NUM_POSITIONS 1
static Position_t character_3_model[CHARACTER_3_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_4_NUM_POSITIONS 1
static Position_t character_4_model[CHARACTER_4_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_5_NUM_POSITIONS 1
static Position_t character_5_model[CHARACTER_5_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_6_NUM_POSITIONS 1
static Position_t character_6_model[CHARACTER_6_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_7_NUM_POSITIONS 1
static Position_t character_7_model[CHARACTER_7_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_8_NUM_POSITIONS 1
static Position_t character_8_model[CHARACTER_8_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_9_NUM_POSITIONS 1
static Position_t character_9_model[CHARACTER_9_NUM_POSITIONS] = {(Position_t){0, 0}};

#endif /* MODELS_H_ */
