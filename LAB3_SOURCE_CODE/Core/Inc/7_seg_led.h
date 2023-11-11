/*
 * 7_seg_led.h
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */

#ifndef INC_7_SEG_LED_H_
#define INC_7_SEG_LED_H_

#include<main.h>
#include<stdint.h>
#include<stm32f103x6.h>
#include<string.h>
#include<stdlib.h>

extern int led_buffer[4];

void off_all_7seg();
void update_buffer_7seg(int num1, int num2);
void display_7segled(int num);


#endif /* INC_7_SEG_LED_H_ */
