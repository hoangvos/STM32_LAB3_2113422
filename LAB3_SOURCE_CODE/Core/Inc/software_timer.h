/*
 * software_timer.h
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int counter1;
extern int transfer_flag;

extern int counter3;
extern int display_7seg_flag;

extern int counter4;
extern int led_man_flag;

void setTimer_transfer(int num);
void setTimer_display_7seg(int num);
void setTimer_led_man(int num);
void timer_run();
#endif /* INC_SOFTWARE_TIMER_H_ */
