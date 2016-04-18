#include "models.h"

static Object_Model_t completed_models[NUM_MODELS];

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
	if (model->num < MAX_MODEL_SIZE) {
		(model->positions[model->num]).x = x;
		(model->positions[model->num]).y = y;
		model->num++;
	}
}

//Must declare creation of menus here, since they also call create_object_model
void create_main_menu(Object_Model_t* model);

//Creates an object model for an object
void create_object_model(Object_Model_t* model, int type) {
	//Menus use different logic and must use their own functions
	if (type == TYPE_MAIN_MENU) {
		create_main_menu(model);
		return;
	}

	//Find connect-dots array based on type
	Position_t positions[MAX_MODEL_SIZE];
	int num_dots;
	set_type(positions, type, &num_dots);

	//Initialize model struct
	model->num = 0;
	int x = positions[0].x;
	int y = positions[0].y;
	plot(model, x, y);

	//Connect dots using bresenham's line algorithm
	//https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
	int i, j, length;
	for (i = 0; i < num_dots - 1; i++) {
		double deltax = positions[i+1].x - x;

		//If change in x is 0, we can use a naiive approach
		if (deltax == 0) {
			while (y != positions[i+1].y) {
				plot(model, x, y);
				y += y > positions[i+1].y ? -1 : 1;
			}

		//Use Bresenham's algorithm otherwise
		} else {
			double deltay = positions[i+1].y - y;
			double error = 0;
			double deltaerr = fabs(deltay / deltax);

			for (x = positions[i].x; x != positions[i+1].x; x += x > positions[i+1].x ? -1 : 1) {
				plot(model, x, y);
				error += deltaerr;
				while (error >= 0.5) {
					plot(model, x, y);
					y += y > positions[i+1].y ? -1 : 1;
					error -= 1;
				}
			}
		}
	}
}

void init_models() {
	int i;
	for (i = 0; i < NUM_MODELS; i++) {
		create_object_model(&completed_models[i], i);
	}
}

void set_object_model(Object_Model_t** model, int type) {
	*model = &completed_models[type];
}

void add_sub_object(Object_Model_t* master, Object_Model_t* sub, Position_t* translation, int scale) {
	int i;
	for (i = 0; i < sub->num; i++) {
		if (master->num < MAX_MODEL_SIZE) {
			(master->positions[master->num]).x = ((sub->positions[i]).x * scale) + translation->x;
			(master->positions[master->num]).y = ((sub->positions[i]).y * scale) + translation->y;
			master->num++;

		} else {
			return;
		}
	}
}

//Displays "ASTEROIDS" in large text and "PRESS ANY BUTTON TO PLAY" under it in small text
void create_main_menu(Object_Model_t* model) {
	//Complete each character that is needed
	//Even if these have been initialized once, guarantee that they are initialized
	int i;
	for (i = TYPE_CHARACTER_Z; i < TYPE_CHARACTER_A; i++) {
		create_object_model(&completed_models[i], i);
	}

	//Translate each character in the title
	int title_height = 200;
	Position_t a_ti_pos_1 = {100, title_height};
	Position_t s_ti_pos_1 = {175, title_height};
	Position_t t_ti_pos_1 = {250, title_height};
	Position_t e_ti_pos_1 = {325, title_height};
	Position_t r_ti_pos_1 = {400, title_height};
	Position_t o_ti_pos_1 = {475, title_height};
	Position_t i_ti_pos_1 = {550, title_height};
	Position_t d_ti_pos_1 = {625, title_height};
	Position_t s_ti_pos_2 = {700, title_height};

	//Translate each character in the text at the bottom
	int label_height = 400;
	Position_t p_la_pos_1 = {100, label_height};
	Position_t r_la_pos_1 = {126, label_height};
	Position_t e_la_pos_1 = {152, label_height};
	Position_t s_la_pos_1 = {178, label_height};
	Position_t s_la_pos_2 = {204, label_height};
	Position_t a_la_pos_1 = {256, label_height};
	Position_t n_la_pos_1 = {282, label_height};
	Position_t y_la_pos_1 = {308, label_height};
	Position_t b_la_pos_1 = {360, label_height};
	Position_t u_la_pos_1 = {386, label_height};
	Position_t t_la_pos_1 = {412, label_height};
	Position_t t_la_pos_2 = {438, label_height};
	Position_t o_la_pos_1 = {464, label_height};
	Position_t n_la_pos_2 = {490, label_height};
	Position_t t_la_pos_3 = {542, label_height};
	Position_t o_la_pos_2 = {568, label_height};
	Position_t p_la_pos_2 = {620, label_height};
	Position_t l_la_pos_1 = {646, label_height};
	Position_t a_la_pos_2 = {672, label_height};
	Position_t y_la_pos_2 = {698, label_height};

	//Determine scale of title and label
	int title_scale = 1;
	int label_scale = 1;

	//Append each character to the array
	model->num = 0;

	add_sub_object(model, &completed_models[TYPE_CHARACTER_A], &a_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_S], &s_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_T], &t_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_E], &e_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_R], &r_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_O], &o_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_I], &i_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_D], &d_ti_pos_1, title_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_S], &s_ti_pos_2, title_scale);

	add_sub_object(model, &completed_models[TYPE_CHARACTER_P], &p_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_R], &r_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_E], &e_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_S], &s_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_S], &s_la_pos_2, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_A], &a_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_N], &n_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_Y], &y_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_B], &b_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_U], &u_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_T], &t_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_T], &t_la_pos_2, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_O], &o_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_N], &n_la_pos_2, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_T], &t_la_pos_3, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_O], &o_la_pos_2, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_P], &p_la_pos_2, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_L], &l_la_pos_1, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_A], &a_la_pos_2, label_scale);
	add_sub_object(model, &completed_models[TYPE_CHARACTER_Y], &y_la_pos_2, label_scale);
}
