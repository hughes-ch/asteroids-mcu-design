#include "models.h"

static Object_Model_t completed_models[NUM_MODELS];
Object_Model_t model_large_score;
Object_Model_t model_small_score;

void p_array_deep_copy(Position_t* copy, Position_t* orig, int length) {
	int i;
	for (i = 0; i < length; i++) {
		copy[i].x = orig[i].x;
		copy[i].y = orig[i].y;
	}
}

void set_type(Position_t positions[MAX_MODEL_SIZE], int type, int* num) {
	switch (type) {
		case TYPE_LARGE_ASTEROID:
			p_array_deep_copy(positions, large_asteroid_model, LARGE_ASTEROID_NUM_POSITIONS);
			*num = LARGE_ASTEROID_NUM_POSITIONS;
			break;

		case TYPE_MEDIUM_ASTEROID:
			p_array_deep_copy(positions, medium_asteroid_model, MEDIUM_ASTEROID_NUM_POSITIONS);
			*num = MEDIUM_ASTEROID_NUM_POSITIONS;
			break;

		case TYPE_SMALL_ASTEROID:
			p_array_deep_copy(positions, small_asteroid_model, SMALL_ASTEROID_NUM_POSITIONS);
			*num = SMALL_ASTEROID_NUM_POSITIONS;
			break;

		case TYPE_MISSILE:
			p_array_deep_copy(positions, missile_model, MISSILE_NUM_POSITIONS);
			*num = MISSILE_NUM_POSITIONS;
			break;

		case TYPE_SHIP:
			p_array_deep_copy(positions, ship_model, SHIP_NUM_POSITIONS);
			*num = SHIP_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_0:
			p_array_deep_copy(positions, character_0_model, CHARACTER_0_NUM_POSITIONS);
			*num = CHARACTER_0_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_1:
			p_array_deep_copy(positions, character_1_model, CHARACTER_1_NUM_POSITIONS);
			*num = CHARACTER_1_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_2:
			p_array_deep_copy(positions, character_2_model, CHARACTER_2_NUM_POSITIONS);
			*num = CHARACTER_2_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_3:
			p_array_deep_copy(positions, character_3_model, CHARACTER_3_NUM_POSITIONS);
			*num = CHARACTER_3_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_4:
			p_array_deep_copy(positions, character_4_model, CHARACTER_4_NUM_POSITIONS);
			*num = CHARACTER_4_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_5:
			p_array_deep_copy(positions, character_5_model, CHARACTER_5_NUM_POSITIONS);
			*num = CHARACTER_5_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_6:
			p_array_deep_copy(positions, character_6_model, CHARACTER_6_NUM_POSITIONS);
			*num = CHARACTER_6_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_7:
			p_array_deep_copy(positions, character_7_model, CHARACTER_7_NUM_POSITIONS);
			*num = CHARACTER_7_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_8:
			p_array_deep_copy(positions, character_8_model, CHARACTER_8_NUM_POSITIONS);
			*num = CHARACTER_8_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_9:
			p_array_deep_copy(positions, character_9_model, CHARACTER_9_NUM_POSITIONS);
			*num = CHARACTER_9_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_A:
			p_array_deep_copy(positions, character_a_model, CHARACTER_A_NUM_POSITIONS);
			*num = CHARACTER_A_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_B:
			p_array_deep_copy(positions, character_b_model, CHARACTER_B_NUM_POSITIONS);
			*num = CHARACTER_B_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_C:
			p_array_deep_copy(positions, character_c_model, CHARACTER_C_NUM_POSITIONS);
			*num = CHARACTER_C_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_D:
			p_array_deep_copy(positions, character_d_model, CHARACTER_D_NUM_POSITIONS);
			*num = CHARACTER_D_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_E:
			p_array_deep_copy(positions, character_e_model, CHARACTER_E_NUM_POSITIONS);
			*num = CHARACTER_E_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_G:
			p_array_deep_copy(positions, character_g_model, CHARACTER_G_NUM_POSITIONS);
			*num = CHARACTER_G_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_I:
			p_array_deep_copy(positions, character_i_model, CHARACTER_I_NUM_POSITIONS);
			*num = CHARACTER_I_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_L:
			p_array_deep_copy(positions, character_l_model, CHARACTER_L_NUM_POSITIONS);
			*num = CHARACTER_L_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_M:
			p_array_deep_copy(positions, character_m_model, CHARACTER_M_NUM_POSITIONS);
			*num = CHARACTER_M_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_N:
			p_array_deep_copy(positions, character_n_model, CHARACTER_N_NUM_POSITIONS);
			*num = CHARACTER_N_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_O:
			p_array_deep_copy(positions, character_o_model, CHARACTER_O_NUM_POSITIONS);
			*num = CHARACTER_O_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_P:
			p_array_deep_copy(positions, character_p_model, CHARACTER_P_NUM_POSITIONS);
			*num = CHARACTER_P_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_Q:
			p_array_deep_copy(positions, character_q_model, CHARACTER_Q_NUM_POSITIONS);
			*num = CHARACTER_Q_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_R:
			p_array_deep_copy(positions, character_r_model, CHARACTER_R_NUM_POSITIONS);
			*num = CHARACTER_R_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_S:
			p_array_deep_copy(positions, character_s_model, CHARACTER_S_NUM_POSITIONS);
			*num = CHARACTER_S_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_T:
			p_array_deep_copy(positions, character_t_model, CHARACTER_T_NUM_POSITIONS);
			*num = CHARACTER_T_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_U:
			p_array_deep_copy(positions, character_u_model, CHARACTER_U_NUM_POSITIONS);
			*num = CHARACTER_U_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_V:
			p_array_deep_copy(positions, character_v_model, CHARACTER_V_NUM_POSITIONS);
			*num = CHARACTER_V_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_Y:
			p_array_deep_copy(positions, character_y_model, CHARACTER_Y_NUM_POSITIONS);
			*num = CHARACTER_Y_NUM_POSITIONS;
			break;

		case TYPE_CHARACTER_Z:
			p_array_deep_copy(positions, character_z_model, CHARACTER_Z_NUM_POSITIONS);
			*num = CHARACTER_Z_NUM_POSITIONS;
			break;

		default:
			break;
	}
}

//Adds one position to the model
void plot(Object_Model_t* model, int x, int y) {
	//Add to model (Assuming it is not full)
	if (model->num_positions < MAX_MODEL_SIZE) {
		(model->positions[model->num_positions]).x = x;
		(model->positions[model->num_positions]).y = y;
		model->num_positions++;
	}
}

//Connects two points on the screen using Bresenham's line algorithm
//https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void connect_points(Object_Model_t* model, Position_t* pos1, Position_t* pos2) {
	double deltax = pos2->x - pos1->x;
	int x = pos1->x;
	int y = pos1->y;

	//If change in x is 0, we can use a naiive approach
	if (deltax == 0) {
		while (y != pos2->y) {
			plot(model, x, y);
			y += y > pos2->y ? -1 : 1;
		}

	//Use Bresenham's algorithm otherwise
	} else {
		double deltay = pos2->y - y;
		double error = 0;
		double deltaerr = fabs(deltay / deltax);

		for (x = pos1->x; x != pos2->x; x += x > pos2->x ? -1 : 1) {
			plot(model, x, y);
			error += deltaerr;
			while (error >= 0.5) {
				plot(model, x, y);
				y += y > pos2->y ? -1 : 1;
				error -= 1;
			}
		}
	}
}

//Must declare creation of menus here, since they also call create_object_model
void create_main_menu(Object_Model_t* model);
void create_pause_menu(Object_Model_t* model);
void create_end_game_menu(Object_Model_t* model);

//Creates an object model for an object
void create_object_model(Object_Model_t* model, int type, int scale) {
	//These use different logic and must use their own functions
	if (type == TYPE_MAIN_MENU) {
		create_main_menu(model);
		return;
	}
	if (type == TYPE_PAUSE_GAME_MENU) {
		create_pause_menu(model);
		return;
	}
	if (type == TYPE_END_GAME_MENU) {
		create_end_game_menu(model);
		return;
	}

	//Find connect-dots array based on type
	Position_t positions[MAX_MODEL_SIZE];
	int num_dots;
	set_type(positions, type, &num_dots);

	//Initialize model struct
	model->num_positions = 0;
	model->num_sub_objects = 0;
	int x = positions[0].x * scale;
	int y = positions[0].y * scale;
	plot(model, x, y);

	//Connect dots
	int i;
	Position_t pos1, pos2;
	for (i = 0; i < num_dots - 1; i++) {
		pos1.x = positions[i].x * scale;
		pos1.y = positions[i].y * scale;
		pos2.x = positions[i+1].x * scale;
		pos2.y = positions[i+1].y * scale;
		connect_points(model, &pos1, &pos2);
	}
}

void init_models() {
	int i;
	for (i = 0; i < NUM_MODELS; i++) {
		create_object_model(&completed_models[i], i, 1);
	}
}

void set_object_model(Object_Model_t** model, int type) {
	*model = &completed_models[type];
}

void add_sub_object(Object_Model_t* master, Object_Model_t* sub, Position_t* translation) {
	if (master->num_sub_objects < MAX_NUM_SUB_OBJECTS) {
		master->sub_objects[master->num_sub_objects] = sub;
		master->num_sub_objects++;

		int i;
		for (i = 0; i < sub->num_positions; i++) {
			(sub->positions[i]).x += translation->x;
			(sub->positions[i]).y += translation->y;
		}
	}
}

//Displays "ASTEROIDS" in large text and "PRESS ANY BUTTON TO PLAY" under it in small text
void create_main_menu(Object_Model_t* model) {
	int i = 0;

	//Create the desired characters at the desired scales
	static Object_Model_t menu_models[MAIN_MENU_NUM_CHARACTERS];

	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_I, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_D, MAIN_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, MAIN_MENU_TITLE_SCALE);

	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_Y, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_B, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_L, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, MAIN_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_Y, MAIN_MENU_LABEL_SCALE);

	//Translate each character in the title
	i = 0;
	int title_height = 200;
	Position_t translations[MAIN_MENU_NUM_CHARACTERS];
	translations[i++] = (Position_t){100, title_height};
	translations[i++] = (Position_t){175, title_height};
	translations[i++] = (Position_t){250, title_height};
	translations[i++] = (Position_t){325, title_height};
	translations[i++] = (Position_t){400, title_height};
	translations[i++] = (Position_t){475, title_height};
	translations[i++] = (Position_t){550, title_height};
	translations[i++] = (Position_t){625, title_height};
	translations[i++] = (Position_t){700, title_height};

	//Translate each character in the text at the bottom
	int label_height = 400;
	translations[i++] = (Position_t){100, label_height};
	translations[i++] = (Position_t){126, label_height};
	translations[i++] = (Position_t){152, label_height};
	translations[i++] = (Position_t){178, label_height};
	translations[i++] = (Position_t){204, label_height};
	translations[i++] = (Position_t){256, label_height};
	translations[i++] = (Position_t){282, label_height};
	translations[i++] = (Position_t){308, label_height};
	translations[i++] = (Position_t){360, label_height};
	translations[i++] = (Position_t){386, label_height};
	translations[i++] = (Position_t){412, label_height};
	translations[i++] = (Position_t){438, label_height};
	translations[i++] = (Position_t){464, label_height};
	translations[i++] = (Position_t){490, label_height};
	translations[i++] = (Position_t){542, label_height};
	translations[i++] = (Position_t){568, label_height};
	translations[i++] = (Position_t){620, label_height};
	translations[i++] = (Position_t){646, label_height};
	translations[i++] = (Position_t){672, label_height};
	translations[i++] = (Position_t){698, label_height};

	//Append each character to the array
	model->num_positions = 0;
	for (i = 0; i < MAIN_MENU_NUM_CHARACTERS; i++) {
		add_sub_object(model, &menu_models[i], &translations[i]);
	}
}

//Display:
//	PAUSED
//	PRESS TRIGGER TO CONTINUE
//  PRESS PAUSE AGAIN TO QUIT
void create_pause_menu(Object_Model_t* model) {
	int i = 0;

	//Create the desired characters at the desired scales
	static Object_Model_t menu_models[PAUSE_MENU_NUM_CHARACTERS];

	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, PAUSE_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, PAUSE_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, PAUSE_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, PAUSE_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, PAUSE_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_D, PAUSE_MENU_TITLE_SCALE);

	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_I, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_G, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_G, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_C, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_I, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, PAUSE_MENU_LABEL_SCALE);

	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_G, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_I, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_Q, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_I, PAUSE_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, PAUSE_MENU_LABEL_SCALE);

	//Translate each character in the title
	i = 0;
	int title_height = 200;
	Position_t translations[PAUSE_MENU_NUM_CHARACTERS];
	translations[i++] = (Position_t){200, title_height};
	translations[i++] = (Position_t){280, title_height};
	translations[i++] = (Position_t){360, title_height};
	translations[i++] = (Position_t){440, title_height};
	translations[i++] = (Position_t){520, title_height};
	translations[i++] = (Position_t){600, title_height};

	//Translate each character in the text at the bottom
	int label_height_1 = 350;
	translations[i++] = (Position_t){100, label_height_1};
	translations[i++] = (Position_t){125, label_height_1};
	translations[i++] = (Position_t){150, label_height_1};
	translations[i++] = (Position_t){175, label_height_1};
	translations[i++] = (Position_t){200, label_height_1};
	translations[i++] = (Position_t){250, label_height_1};
	translations[i++] = (Position_t){275, label_height_1};
	translations[i++] = (Position_t){300, label_height_1};
	translations[i++] = (Position_t){325, label_height_1};
	translations[i++] = (Position_t){350, label_height_1};
	translations[i++] = (Position_t){375, label_height_1};
	translations[i++] = (Position_t){400, label_height_1};
	translations[i++] = (Position_t){450, label_height_1};
	translations[i++] = (Position_t){475, label_height_1};
	translations[i++] = (Position_t){525, label_height_1};
	translations[i++] = (Position_t){550, label_height_1};
	translations[i++] = (Position_t){575, label_height_1};
	translations[i++] = (Position_t){600, label_height_1};
	translations[i++] = (Position_t){625, label_height_1};
	translations[i++] = (Position_t){650, label_height_1};
	translations[i++] = (Position_t){675, label_height_1};
	translations[i++] = (Position_t){700, label_height_1};

	int label_height_2 = 400;
	translations[i++] = (Position_t){100, label_height_2};
	translations[i++] = (Position_t){125, label_height_2};
	translations[i++] = (Position_t){150, label_height_2};
	translations[i++] = (Position_t){175, label_height_2};
	translations[i++] = (Position_t){200, label_height_2};
	translations[i++] = (Position_t){250, label_height_2};
	translations[i++] = (Position_t){275, label_height_2};
	translations[i++] = (Position_t){300, label_height_2};
	translations[i++] = (Position_t){325, label_height_2};
	translations[i++] = (Position_t){350, label_height_2};
	translations[i++] = (Position_t){400, label_height_2};
	translations[i++] = (Position_t){425, label_height_2};
	translations[i++] = (Position_t){450, label_height_2};
	translations[i++] = (Position_t){475, label_height_2};
	translations[i++] = (Position_t){500, label_height_2};
	translations[i++] = (Position_t){550, label_height_2};
	translations[i++] = (Position_t){575, label_height_2};
	translations[i++] = (Position_t){625, label_height_2};
	translations[i++] = (Position_t){650, label_height_2};
	translations[i++] = (Position_t){675, label_height_2};
	translations[i++] = (Position_t){700, label_height_2};

	//Append each character to the array
	model->num_positions = 0;
	model->num_sub_objects = 0;
	for (i = 0; i < PAUSE_MENU_NUM_CHARACTERS; i++) {
		add_sub_object(model, &menu_models[i], &translations[i]);
	}
}

//Displays end game menu:
//           GAME OVER
//          SCORE: 1549
// PRESS ANY BUTTON TO CONTINUE
void create_end_game_menu(Object_Model_t* model) {
	int i = 0;

	//Create the desired characters at the desired scales
	static Object_Model_t menu_models[END_GAME_MENU_NUM_CHARACTERS];

	create_object_model(&menu_models[i++], TYPE_CHARACTER_G, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_M, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_V, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, END_GAME_MENU_TITLE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, END_GAME_MENU_TITLE_SCALE);

	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, END_GAME_MENU_SCORE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_C, END_GAME_MENU_SCORE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, END_GAME_MENU_SCORE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, END_GAME_MENU_SCORE_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, END_GAME_MENU_SCORE_SCALE);

	create_object_model(&menu_models[i++], TYPE_CHARACTER_P, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_R, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_S, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_A, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_Y, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_B, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_C, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_O, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_T, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_I, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_N, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_U, END_GAME_MENU_LABEL_SCALE);
	create_object_model(&menu_models[i++], TYPE_CHARACTER_E, END_GAME_MENU_LABEL_SCALE);

	//Translate each character in the title
	i = 0;
	int title_height = 200;
	Position_t translations[END_GAME_MENU_NUM_CHARACTERS];
	translations[i++] = (Position_t){200, title_height};
	translations[i++] = (Position_t){250, title_height};
	translations[i++] = (Position_t){300, title_height};
	translations[i++] = (Position_t){350, title_height};
	translations[i++] = (Position_t){450, title_height};
	translations[i++] = (Position_t){500, title_height};
	translations[i++] = (Position_t){550, title_height};
	translations[i++] = (Position_t){600, title_height};

	int score_height = 300;
	translations[i++] = (Position_t){200, score_height};
	translations[i++] = (Position_t){240, score_height};
	translations[i++] = (Position_t){280, score_height};
	translations[i++] = (Position_t){320, score_height};
	translations[i++] = (Position_t){360, score_height};

	int label_height = 450;
	translations[i++] = (Position_t){100, label_height};
	translations[i++] = (Position_t){122, label_height};
	translations[i++] = (Position_t){144, label_height};
	translations[i++] = (Position_t){166, label_height};
	translations[i++] = (Position_t){188, label_height};
	translations[i++] = (Position_t){232, label_height};
	translations[i++] = (Position_t){254, label_height};
	translations[i++] = (Position_t){276, label_height};
	translations[i++] = (Position_t){320, label_height};
	translations[i++] = (Position_t){342, label_height};
	translations[i++] = (Position_t){364, label_height};
	translations[i++] = (Position_t){386, label_height};
	translations[i++] = (Position_t){408, label_height};
	translations[i++] = (Position_t){430, label_height};
	translations[i++] = (Position_t){474, label_height};
	translations[i++] = (Position_t){496, label_height};
	translations[i++] = (Position_t){540, label_height};
	translations[i++] = (Position_t){562, label_height};
	translations[i++] = (Position_t){584, label_height};
	translations[i++] = (Position_t){606, label_height};
	translations[i++] = (Position_t){628, label_height};
	translations[i++] = (Position_t){650, label_height};
	translations[i++] = (Position_t){672, label_height};
	translations[i++] = (Position_t){694, label_height};

	//Append each character to the array
	model->num_positions = 0;
	for (i = 0; i < END_GAME_MENU_NUM_CHARACTERS; i++) {
		add_sub_object(model, &menu_models[i], &translations[i]);
	}

	//Add the score object
	add_sub_object(model, &model_large_score, &((Position_t){440, score_height}));
}

void get_digits(int* digits, int score, int* num_digits) {
	digits[0] = (score % 10) + TYPE_CHARACTER_0;
	digits[1] = ((score/10) % 10) + TYPE_CHARACTER_0;
	digits[2] = ((score/100) % 10) + TYPE_CHARACTER_0;
	digits[3] = ((score/1000) % 10) + TYPE_CHARACTER_0;
	digits[4] = ((score/10000) % 10) + TYPE_CHARACTER_0;

	for (*num_digits = SCORE_MAX_CHARACTERS; *num_digits > 1; (*num_digits)--) {
		if (digits[*num_digits-1] != TYPE_CHARACTER_0) {
			return;
		}
	}
}

void update_score_model(int score) {
	//Do math to see which digits we need
	int digits[SCORE_MAX_CHARACTERS];
	int num_digits, i;
	get_digits(digits, score, &num_digits);

	//Create the digits
	static Object_Model_t large_digit_models[SCORE_MAX_CHARACTERS];
	static Object_Model_t small_digit_models[SCORE_MAX_CHARACTERS];
	for (i = 0; i < num_digits; i++) {
		create_object_model(&large_digit_models[i], digits[num_digits - i - 1], LARGE_SCORE_SCALE);
		create_object_model(&small_digit_models[i], digits[num_digits - i - 1], SMALL_SCORE_SCALE);
	}

	//Add digits to the score models
	model_large_score.num_sub_objects = 0;
	model_small_score.num_sub_objects = 0;
	for (i = 0; i < num_digits; i++) {
		add_sub_object(&model_large_score, &large_digit_models[i], &((Position_t){(i * LARGE_SCORE_SPACING) + 440, 300}));
		add_sub_object(&model_small_score, &small_digit_models[i], &((Position_t){(i * SMALL_SCORE_SPACING) + 440, 300}));
	}
}
