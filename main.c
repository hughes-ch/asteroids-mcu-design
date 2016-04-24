/***************************************************************************//**
 *   @file   main.c
********************************************************************************
 * Copyright 2013(c) Analog Devices, Inc.
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  - Neither the name of Analog Devices, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *  - The use of this software may or may not infringe the patent rights
 *    of one or more patent holders.  This license does not release you
 *    from the requirement that you obtain separate licenses from these
 *    patent holders to use this software.
 *  - Use of the software either in source or binary form, must be run
 *    on or directly connected to an Analog Devices Inc. component.
 *
 * THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
********************************************************************************
 *   SVN Revision: $WCREV$
*******************************************************************************/

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/
#include <stdio.h>

#include "asteroids.h"
#include "xil_cache.h"
#include "xbasic_types.h"
#include "xil_io.h"
#include "cf_hdmi.h"
#include "atv_platform.h"
#include "transmitter.h"
#include "xil_exception.h"
#include "xuartps.h"

extern void delay_ms(u32 ms_count);
extern char inbyte(void);

/******************************************************************************/
/************************** Macros Definitions ********************************/
/******************************************************************************/
#define HDMI_CALL_INTERVAL_MS	10			/* Interval between two         */
											/* iterations of the main loop  */
#define DBG_MSG                 xil_printf

/******************************************************************************/
/************************ Variables Definitions *******************************/
/******************************************************************************/
static BOOL     DriverEnable;
static BOOL     LastEnable;

/***************************************************************************//**
 * @brief Enables the driver.
 *
 * @return Returns ATVERR_OK.
*******************************************************************************/
void APP_EnableDriver (BOOL Enable)
{
    DriverEnable = Enable;
}

/***************************************************************************//**
 * @brief Returns the driver enable status.
 *
 * @return Returns the driver enable status.
*******************************************************************************/
static BOOL APP_DriverEnabled (void)
{
    if ((DriverEnable && HAL_GetMBSwitchState()) != LastEnable)
    {
        LastEnable = DriverEnable && HAL_GetMBSwitchState();
        DBG_MSG ("APP: Driver %s\n\r", LastEnable? "Enabled": "Disabled");
    }
    return (LastEnable);
}

/***************************************************************************//**
 * @brief Changes the video resolution.
 *
 * @return None.
*******************************************************************************/
static void APP_ChangeResolution (void)
{
	char receivedChar    = 0;

	if(XUartPs_IsReceiveData(UART_BASEADDR))
	{
		receivedChar = inbyte();

		SetVideoResolution(RESOLUTION_800x600);
		DBG_MSG("Refreshing screen. Resolution set to 800x600\r\n");
	}
}

/*******************************************************************************
 * Calculates the next frame buffer location in memory
 *******************************************************************************/
u32 get_frame_addr() {
	static u32 addr = FRAME_BUFFER_1;

	if (addr == FRAME_BUFFER_1) {
		addr = FRAME_BUFFER_2;
	} else {
		addr = FRAME_BUFFER_1;
	}

	return addr;
}

void display_sub_objects(Object_Model_t* model, int screensize, u32 start_addr) {
	int i, x, y;
	Object_Model_t* sub_model;
	for (i = 0; i < model->num_sub_objects; i++) {
		sub_model = model->sub_objects[i];
		display_sub_objects(sub_model, screensize, start_addr);
	}

	for (i = 0; i < model->num_positions; i++) {
		x = (model->positions[i]).x;
		y = (model->positions[i]).y;
		Xil_Out32((start_addr + (x*4) + (y*4*screensize)), 0xffffff);
	}
}

/*******************************************************************************
 * @brief Displays one HDMI frame
********************************************************************************/
void display_frame(Game_Model_t* model) {
	//Determine which frame buffer to write
	u32 addr = get_frame_addr();
	int line, pixel, i, j, x, y, x_pos, y_pos;
	Object_Model_t o_model;

	//Create black background
	for(line = 0; line < model->y; line++) {
		for(pixel = 0; pixel < model->x; pixel++) {
			Xil_Out32((addr + (pixel*4)+(line * 4 * model->x)), (0));
		}
	}

	//Create view of game. Only display game objects when playing
	if (model->state == STATE_PLAYING) {
		//Display asteroids on screen
		for (i = 0; i < MAX_ASTEROIDS; i++) {
			if ((model->asteroids[i]).empty) {
				continue;
			}
			o_model = *((model->asteroids[i]).model);
			x_pos = (model->asteroids[i]).x_pos;
			y_pos = (model->asteroids[i]).y_pos;

			for (j = 0; j < o_model.num_positions; j++) {
				x = (o_model.positions[j].x) + x_pos;
				y = (o_model.positions[j].y) + y_pos;
				if (x > 0 && x < model->x && y > 0 && y < model->y) {
					Xil_Out32((addr + (x*4) + (y*4*model->x)), 0xffffff);
				}
			}
		}

		//Display missiles on screen
		for (i = 0; i < MAX_MISSILES; i++) {
			if ((model->missiles[i]).empty) {
				continue;
			}

			o_model = *((model->missiles[i]).model);
			x_pos = (model->missiles[i]).x_pos;
			y_pos = (model->missiles[i]).y_pos;

			for (j = 0; j < o_model.num_positions; j++) {
				x = (o_model.positions[j]).x + x_pos;
				y = (o_model.positions[j]).y + y_pos;
				if (x > 0 && x < model->x && y > 0 && y < model->y) {
					Xil_Out32((addr + (x*4) + (y*4*model->x)), 0xffffff);
				}
			}
		}

		//Display ship on screen
		o_model = *(model->ship.model);
		x_pos = model->ship.x_pos;
		y_pos = model->ship.y_pos;

		for (j = 0; j < o_model.num_positions; j++) {
			x = (o_model.positions[j]).x + x_pos;
			y = (o_model.positions[j]).y + y_pos;
			if (x > 0 && x < model->x && y > 0 && y < model->y) {
				Xil_Out32((addr + (x*4) + (y*4*model->x)), 0xffffff);
			}
		}
	}

	//Tell the view what the score is
	update_score_model(model->score);

	//Display HUD (or menus)
	o_model = *(model->model);
	display_sub_objects(&o_model, model->x, addr);

	//Start VDMA with the desired starting address
	if (addr == FRAME_BUFFER_1) {
		Xil_Out32((VDMA_BASEADDR + AXI_VDMA_PARK_PTR_REG), 0);
	} else {
		Xil_Out32((VDMA_BASEADDR + AXI_VDMA_PARK_PTR_REG), 1);
	}

	Xil_DCacheFlush();
}

/********************************************************************************
 * Initializes hardware and software for HDMI to operate properly
 ********************************************************************************/
void hdmi_init(int* resx, int* resy) {
	DriverEnable = TRUE;
	LastEnable = FALSE;

	HAL_PlatformInit(XPAR_AXI_IIC_MAIN_BASEADDR,	/* Perform any required platform init */
						 XPAR_SCUTIMER_DEVICE_ID,	/* including hardware reset to HDMI devices */
						 XPAR_SCUGIC_SINGLE_DEVICE_ID,
						 XPAR_SCUTIMER_INTR);

	Xil_ExceptionEnable();

	SetVideoResolution(RESOLUTION_800x600);
	*resx = 800;
	*resy = 600;

	InitHdmiAudioPcore();

	ADIAPI_TransmitterInit();
	ADIAPI_TransmitterSetPowerMode(REP_POWER_UP);
}

#define GPIO_DATA (*((volatile unsigned int*)(0xE000A000 + 0x00000048)))
#define BUTTONL (1 << 3)
#define BUTTONC (1 << 0)
#define BUTTOND (1 << 1)
#define BUTTONR (1 << 2)
#define BUTTONU (1 << 4)

void gpio_init() {
	GPIO_DATA = 0;
}

/********************************************************************************
 * Stores the value of the controller from the controller task
 ********************************************************************************/
void get_controller_value(Controller_t* controller) {
	printf("GPIO_DATA: %d\n", GPIO_DATA);
	controller->aux_button = GPIO_DATA & BUTTOND;
	controller->trigger_button = GPIO_DATA & BUTTONC;
	controller->pitch = GPIO_DATA & BUTTONU ? 45 : 0;
	if (GPIO_DATA & BUTTONR) {
		controller->roll = 45;
	} else if (GPIO_DATA & BUTTONL) {
		controller->roll = -45;
	} else {
		controller->roll = 0;
	}
}

/***************************************************************************//**
 * @brief Main function.
 *
 * @return Returns 0.
*******************************************************************************/
int main()
{
	UINT32 StartCount;
	int resx, resy;
	Game_Model_t model;
	Controller_t controller;

	Xil_ICacheEnable();
	Xil_DCacheEnable();

	hdmi_init(&resx, &resy);
	asteroids_init(&model, resx, resy);
	gpio_init();

	StartCount = HAL_GetCurrentMsCount();

	while(1)
	{
		if (ATV_GetElapsedMs (StartCount, NULL) >= HDMI_CALL_INTERVAL_MS)
		{
			StartCount = HAL_GetCurrentMsCount();
			if (APP_DriverEnabled())
			{
				ADIAPI_TransmitterMain();
			}
		}

		APP_ChangeResolution();

		get_controller_value(&controller);
		asteroids_main(&model, &controller);
		display_frame(&model);
	}

	Xil_DCacheDisable();
	Xil_ICacheDisable();

	return(0);
}
