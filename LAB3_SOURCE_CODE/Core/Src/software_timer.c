/*
 * software_timer.c
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */
#include<software_timer.h>

int counter1 = 0;
int transfer_flag = 0;

int counter2 = 0;
int down_flag = 0;

int counter3 = 0;
int display_7seg_flag = 0;

int counter4 = 0;
int led_man_flag = 0;

void setTimer_transfer(int num){
	counter1 = num;
	transfer_flag = 0;
}
void setTimer_down(int num){
	counter2 = num;
	down_flag = 0;
}
void setTimer_display_7seg(int num){
	counter3 = num;
	display_7seg_flag = 0;
}
void setTimer_led_man(int num){
	counter4 = num;
	led_man_flag = 0;
}

void timer_run(){
	if(counter1 > 0){
		counter1--;
		if(counter1 <= 0){
			transfer_flag = 1;
		}
	}
	if(counter2 > 0){
		counter2--;
		if(counter2 <= 0){
			down_flag = 1;
		}
	}
	if(counter3 > 0){
		counter3--;
		if(counter3 <= 0){
			display_7seg_flag = 1;
		}
	}
	if(counter4 > 0){
		counter4--;
		if(counter4 <= 0){
			led_man_flag = 1;
		}
	}
}
