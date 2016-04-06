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

#define LARGE_ASTEROID_POSITIONS {(Position_t){0, 0}}
#define MEDIUM_ASTEROID_POSITIONS {(Position_t){0, 0}}
#define SMALL_ASTEROID_POSITIONS {(Position_t){0, 0}}
#define MISSILE_POSITIONS {(Position_t){0, 0}}
#define SHIP_POSITIONS {(Position_t){0, 0}}
#define MAIN_MENU_POSITIONS {(Position_t){0, 0}}
#define END_GAME_MENU_POSITIONS {(Position_t){0, 0}}
#define PAUSE_GAME_MENU_POSITIONS {(Position_t){0, 0}}
#define PLAYING_POSITIONS {(Position_t){0, 0}}
#define LABEL_LIVES_POSITIONS {(Position_t){0, 0}}
#define LABEL_SCORE_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_0_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_1_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_2_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_3_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_4_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_5_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_6_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_7_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_8_POSITIONS {(Position_t){0, 0}}
#define CHARACTER_9_POSITIONS {(Position_t){0, 0}}

#define LARGE_ASTEROID_MODEL  (Object_Model_t){1, LARGE_ASTEROID_POSITIONS}
#define MEDIUM_ASTEROID_MODEL (Object_Model_t){1, MEDIUM_ASTEROID_POSITIONS}
#define SMALL_ASTEROID_MODEL  (Object_Model_t){1, SMALL_ASTEROID_POSITIONS}

#define MISSILE_MODEL (Object_Model_t){1, MISSILE_POSITIONS}
#define SHIP_MODEL    (Object_Model_t){1, SHIP_POSITIONS}

#define MAIN_MENU_MODEL       (Object_Model_t){1, MAIN_MENU_POSITIONS}
#define END_GAME_MENU_MODEL   (Object_Model_t){1, END_GAME_MENU_POSITIONS}
#define PAUSE_GAME_MENU_MODEL (Object_Model_t){1, PAUSE_GAME_POSITIONS}
#define PLAYING_MODEL         (Object_Model_t){1, PLAYING_POSITIONS}

#define LABEL_LIVES_MODEL (Object_Model_t){1, LABEL_LIVES_POSITIONS}
#define LABLE_SCORE_MODEL (Object_Model_t){1, LABLE_SCORE_POSITIONS}

#define CHARACTER_0_MODEL (Object_Model_t){1, CHARACTER_0_POSITIONS}
#define CHARACTER_1_MODEL (Object_Model_t){1, CHARACTER_1_POSITIONS}
#define CHARACTER_2_MODEL (Object_Model_t){1, CHARACTER_2_POSITIONS}
#define CHARACTER_3_MODEL (Object_Model_t){1, CHARACTER_3_POSITIONS}
#define CHARACTER_4_MODEL (Object_Model_t){1, CHARACTER_4_POSITIONS}
#define CHARACTER_5_MODEL (Object_Model_t){1, CHARACTER_5_POSITIONS}
#define CHARACTER_6_MODEL (Object_Model_t){1, CHARACTER_6_POSITIONS}
#define CHARACTER_7_MODEL (Object_Model_t){1, CHARACTER_7_POSITIONS}
#define CHARACTER_8_MODEL (Object_Model_t){1, CHARACTER_8_POSITIONS}
#define CHARACTER_9_MODEL (Object_Model_t){1, CHARACTER_9_POSITIONS}

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

#endif /* MODELS_H_ */
