/*
 * models.h
 *
 *  Created on: Apr 2, 2016
 *      Author: Chris
 */

#ifndef MODELS_H_
#define MODELS_H_

#define MAX_MODEL_SIZE 500
#define NUM_MODELS 38

#define TYPE_LARGE_ASTEROID  (NUM_MODELS - 1)
#define TYPE_MEDIUM_ASTEROID (NUM_MODELS - 2)
#define TYPE_SMALL_ASTEROID  (NUM_MODELS - 3)
#define TYPE_MISSILE         (NUM_MODELS - 4)
#define TYPE_SHIP            (NUM_MODELS - 5)
#define TYPE_MAIN_MENU       (NUM_MODELS - 6)
#define TYPE_END_GAME_MENU   (NUM_MODELS - 7)
#define TYPE_PAUSE_GAME_MENU (NUM_MODELS - 8)
#define TYPE_PLAYING         (NUM_MODELS - 9)
#define TYPE_CHARACTER_0     (NUM_MODELS - 10)
#define TYPE_CHARACTER_1     (NUM_MODELS - 11)
#define TYPE_CHARACTER_2     (NUM_MODELS - 12)
#define TYPE_CHARACTER_3     (NUM_MODELS - 13)
#define TYPE_CHARACTER_4     (NUM_MODELS - 14)
#define TYPE_CHARACTER_5     (NUM_MODELS - 15)
#define TYPE_CHARACTER_6     (NUM_MODELS - 16)
#define TYPE_CHARACTER_7     (NUM_MODELS - 17)
#define TYPE_CHARACTER_8     (NUM_MODELS - 18)
#define TYPE_CHARACTER_9     (NUM_MODELS - 19)
#define TYPE_CHARACTER_A     (NUM_MODELS - 20)
#define TYPE_CHARACTER_B     (NUM_MODELS - 21)
#define TYPE_CHARACTER_C     (NUM_MODELS - 22)
#define TYPE_CHARACTER_D     (NUM_MODELS - 23)
#define TYPE_CHARACTER_E     (NUM_MODELS - 24)
#define TYPE_CHARACTER_G     (NUM_MODELS - 25)
#define TYPE_CHARACTER_I     (NUM_MODELS - 26)
#define TYPE_CHARACTER_L     (NUM_MODELS - 27)
#define TYPE_CHARACTER_M     (NUM_MODELS - 28)
#define TYPE_CHARACTER_N     (NUM_MODELS - 29)
#define TYPE_CHARACTER_O     (NUM_MODELS - 30)
#define TYPE_CHARACTER_P     (NUM_MODELS - 31)
#define TYPE_CHARACTER_Q     (NUM_MODELS - 32)
#define TYPE_CHARACTER_R     (NUM_MODELS - 33)
#define TYPE_CHARACTER_S     (NUM_MODELS - 34)
#define TYPE_CHARACTER_T     (NUM_MODELS - 35)
#define TYPE_CHARACTER_U     (NUM_MODELS - 36)
#define TYPE_CHARACTER_Y     (NUM_MODELS - 37)
#define TYPE_CHARACTER_Z     (NUM_MODELS - 38)

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

/**
 * Implemented game models:
 *  [x] LARGE_ASTEROID
 *  [x] MEDIUM_ASTEROID
 *  [x] SMALL_ASTEROID
 *  [x] MISSILE
 *  [x] SHIP
 *  [ ] MAIN_MENU
 *  [ ] END_GAME_MENU
 *  [ ] PAUSE_GAME_MENU
 *  [ ] PLAYING
 *  [ ] CHARACTER_0
 *  [ ] CHARACTER_1
 *  [ ] CHARACTER_2
 *  [ ] CHARACTER_3
 *  [ ] CHARACTER_4
 *  [ ] CHARACTER_5
 *  [ ] CHARACTER_6
 *  [ ] CHARACTER_7
 *  [ ] CHARACTER_8
 *  [ ] CHARACTER_9
 *  [x] CHARACTER_A
 *  [ ] CHARACTER_B
 *  [ ] CHARACTER_C
 *  [ ] CHARACTER_D
 *  [ ] CHARACTER_E
 *  [ ] CHARACTER_G
 *  [ ] CHARACTER_I
 *  [ ] CHARACTER_L
 *  [ ] CHARACTER_M
 *  [ ] CHARACTER_N
 *  [ ] CHARACTER_O
 *  [ ] CHARACTER_P
 *  [ ] CHARACTER_Q
 *  [ ] CHARACTER_R
 *  [ ] CHARACTER_S
 *  [ ] CHARACTER_T
 *  [ ] CHARACTER_U
 *  [ ] CHARACTER_Y
 *  [ ] CHARACTER_Z
 */
#define LARGE_ASTEROID_NUM_POSITIONS 13
static Position_t large_asteroid_model[LARGE_ASTEROID_NUM_POSITIONS] = {(Position_t){24, -20},
																		(Position_t){40, -28},
																		(Position_t){28, -46},
																		(Position_t){0, -37},
																		(Position_t){-28, -46},
																		(Position_t){-40, -28},
																		(Position_t){-26, 0},
																		(Position_t){-40, 12},
																		(Position_t){-28, 36},
																		(Position_t){-19, 28},
																		(Position_t){24, 36},
																		(Position_t){40, 12},
																		(Position_t){24, -20}};

#define MEDIUM_ASTEROID_NUM_POSITIONS 12
static Position_t medium_asteroid_model[MEDIUM_ASTEROID_NUM_POSITIONS] = {(Position_t){-5, 0},
																		  (Position_t){-5, 20},
																		  (Position_t){10, 20},
																		  (Position_t){20, 5},
																		  (Position_t){20, -5},
																		  (Position_t){13, -20},
																		  (Position_t){-8, -20},
																		  (Position_t){-18, -5},
																		  (Position_t){-13, -2},
																		  (Position_t){-19, 2},
																		  (Position_t){-14, 17},
																		  (Position_t){-5, 0}};

#define SMALL_ASTEROID_NUM_POSITIONS 12
static Position_t small_asteroid_model[SMALL_ASTEROID_NUM_POSITIONS] = {(Position_t){0, 0},
																		(Position_t){9, -4},
																		(Position_t){3, -7},
																		(Position_t){0, -10},
																		(Position_t){-2, -4},
																		(Position_t){-7, -7},
																		(Position_t){-9, 0},
																		(Position_t){-7, 7},
																		(Position_t){-2, 9},
																		(Position_t){3, 7},
																		(Position_t){7, 3},
																		(Position_t){0, 0}};

#define MISSILE_NUM_POSITIONS 1
static Position_t missile_model[MISSILE_NUM_POSITIONS] = {(Position_t){0, 0}};

#define SHIP_NUM_POSITIONS 6
static Position_t ship_model[SHIP_NUM_POSITIONS] = {(Position_t){0, -10},
													(Position_t){-8, 10},
													(Position_t){-3, 5},
													(Position_t){3, 5},
													(Position_t){8, 10},
													(Position_t){0, -10}};

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

#define CHARACTER_A_NUM_POSITIONS 8
static Position_t character_a_model[CHARACTER_A_NUM_POSITIONS] = {(Position_t){0, -5},
																  (Position_t){-4, -1},
																  (Position_t){-4, 5},
																  (Position_t){-4, 2},
																  (Position_t){4, 2},
																  (Position_t){4, 5},
																  (Position_t){4, -1},
																  (Position_t){0, -5}};

#define CHARACTER_B_NUM_POSITIONS 1
static Position_t character_b_model[CHARACTER_B_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_C_NUM_POSITIONS 1
static Position_t character_c_model[CHARACTER_C_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_D_NUM_POSITIONS 1
static Position_t character_d_model[CHARACTER_D_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_E_NUM_POSITIONS 1
static Position_t character_e_model[CHARACTER_E_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_G_NUM_POSITIONS 1
static Position_t character_g_model[CHARACTER_G_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_I_NUM_POSITIONS 1
static Position_t character_i_model[CHARACTER_I_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_L_NUM_POSITIONS 1
static Position_t character_l_model[CHARACTER_L_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_M_NUM_POSITIONS 1
static Position_t character_m_model[CHARACTER_M_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_N_NUM_POSITIONS 1
static Position_t character_n_model[CHARACTER_N_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_O_NUM_POSITIONS 1
static Position_t character_o_model[CHARACTER_O_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_P_NUM_POSITIONS 1
static Position_t character_p_model[CHARACTER_P_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_Q_NUM_POSITIONS 1
static Position_t character_q_model[CHARACTER_Q_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_R_NUM_POSITIONS 1
static Position_t character_r_model[CHARACTER_R_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_S_NUM_POSITIONS 1
static Position_t character_s_model[CHARACTER_S_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_T_NUM_POSITIONS 1
static Position_t character_t_model[CHARACTER_T_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_U_NUM_POSITIONS 1
static Position_t character_u_model[CHARACTER_U_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_Y_NUM_POSITIONS 1
static Position_t character_y_model[CHARACTER_Y_NUM_POSITIONS] = {(Position_t){0, 0}};

#define CHARACTER_Z_NUM_POSITIONS 1
static Position_t character_z_model[CHARACTER_Z_NUM_POSITIONS] = {(Position_t){0, 0}};

//Function Defs
void init_models(void);
void set_object_model(Object_Model_t** model, int type);

#endif /* MODELS_H_ */
