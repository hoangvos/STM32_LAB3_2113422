/*
 * handle_FSM.h
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */

#ifndef INC_HANDLE_FSM_H_
#define INC_HANDLE_FSM_H_

#include "main.h"
#include "input_reading.h"
#include "7_seg_led.h"
#include "LED_traffic.h"
#include "software_timer.h"

// Default time duration of each led
#define GREEN_DEFAULT_TIME 3
#define RED_DEFAULT_TIME 5
#define AMBER_DEFAULT_TIME 2


extern int green_time;
extern int red_time;
extern int amber_time;

extern int green_time_increase;
extern int red_time_increase;
extern int amber_time_increase;

// display 7SEG
extern int display_7seg_road_1;
extern int display_7seg_road_2;
extern int index_7seg_led;

void handle_FSM();




#endif /* INC_HANDLE_FSM_H_ */
