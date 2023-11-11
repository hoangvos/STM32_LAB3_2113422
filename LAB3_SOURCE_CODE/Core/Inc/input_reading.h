/*
 * input_reading.h
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
#include "software_timer.h"

#define NUM_BUTTONS 3
#define BUTTON_IS_PRESSED RESET
#define BUTTON_IS_RELEASED SET
// PIN
#define BUTTON_1_PIN GPIO_PIN_8
#define BUTTON_2_PIN GPIO_PIN_9
#define BUTTON_3_PIN GPIO_PIN_10



extern int button_flag[NUM_BUTTONS];
extern int TimeOutForKeyProcess[NUM_BUTTONS];


int is_button_pressed(int num);
void subKeyProcess(int num);
void getKeyInput();



#endif /* INC_INPUT_READING_H_ */
