/*
 * input_reading.c
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */

#include "input_reading.h"

int KeyReg0[NUM_BUTTONS] = {BUTTON_IS_PRESSED, BUTTON_IS_PRESSED,BUTTON_IS_PRESSED};
int KeyReg1[NUM_BUTTONS] = {BUTTON_IS_PRESSED, BUTTON_IS_PRESSED, BUTTON_IS_PRESSED};
int KeyReg2[NUM_BUTTONS] = {BUTTON_IS_PRESSED, BUTTON_IS_PRESSED, BUTTON_IS_PRESSED};
int KeyReg3[NUM_BUTTONS] = {BUTTON_IS_PRESSED, BUTTON_IS_PRESSED, BUTTON_IS_PRESSED};

uint16_t BUTTON_PIN[NUM_BUTTONS] = {BUTTON_1_PIN, BUTTON_2_PIN, BUTTON_3_PIN};

int TimeOutForKeyProcess[NUM_BUTTONS] = {200, 200, 200};
int button_flag[NUM_BUTTONS] = {0, 0, 0};

int is_button_pressed(int num){
	if(button_flag[num] == 1){
		button_flag[num] = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(int num){
	button_flag[num] = 1;
}
void getKeyInput(){
	for(int i = 0; i < NUM_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, BUTTON_PIN[i]);
		if((KeyReg2[i] == KeyReg1[i]) && (KeyReg1[i] == KeyReg0[i])){
			if(KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if(KeyReg3[i] == BUTTON_IS_RELEASED){
					TimeOutForKeyProcess[i] = 200;
					subKeyProcess(i);
				}
			}
			else{
				TimeOutForKeyProcess[i]--;
				if(TimeOutForKeyProcess[i] == 0){
					TimeOutForKeyProcess[i] = 200;
					KeyReg3[i] = BUTTON_IS_PRESSED;
				}
			}
		}

	}
}


















