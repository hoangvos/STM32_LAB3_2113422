/*
 * handle_FSM.c
 *
 *  Created on: Nov 11, 2023
 *      Author: hoang
 */

#include "handle_FSM.h"


int green_time = GREEN_DEFAULT_TIME;
int red_time = RED_DEFAULT_TIME;
int amber_time = AMBER_DEFAULT_TIME;

int green_time_increase = GREEN_DEFAULT_TIME;
int red_time_increase = RED_DEFAULT_TIME;
int amber_time_increase = AMBER_DEFAULT_TIME;

int display_7seg_road_1 = 0;
int display_7seg_road_2 = 0;
int index_7seg_led = 0;

enum State{
	INIT,
	RED_GREEN,
	RED_AMBER,
	GREEN_RED,
	AMBER_RED,
	MAN_RED,
	MAN_AMBER,
	MAN_GREEN,
	CHECK_STATE
};
enum State current_state = INIT;

void handle_FSM(){
	switch(current_state){
	case INIT:
		off_all_led();
		off_all_7seg();
		current_state = RED_GREEN;
		display_7seg_road_1 = red_time;
		display_7seg_road_2 = green_time;
		setTimer_transfer(green_time*100);
		setTimer_down(100);
		setTimer_display_7seg(1);
		update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		break;
	case RED_GREEN:
		on_red_1();
		on_green_2();
		if(transfer_flag){
			setTimer_transfer(amber_time*100);
			current_state = RED_AMBER;
		}
		if(down_flag){
			setTimer_down(100);
			display_7seg_road_1--;
			display_7seg_road_2--;
			if(display_7seg_road_2 <= 0) display_7seg_road_2 = amber_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = MAN_RED;
			green_time_increase = green_time;
			red_time_increase = red_time;
			amber_time_increase = amber_time;
			display_7seg_road_1 = 2;
			display_7seg_road_2 = red_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
			setTimer_led_man(1);
			setTimer_display_7seg(1);
		}
		break;
	case RED_AMBER:
		on_red_1();
		on_amber_2();
		if(transfer_flag){
			setTimer_transfer(green_time*100);
			current_state = GREEN_RED;
		}
		if(down_flag){
			setTimer_down(100);
			display_7seg_road_1--;
			display_7seg_road_2--;
			if(display_7seg_road_1 <= 0) display_7seg_road_1 = green_time;
			if(display_7seg_road_2 <= 0) display_7seg_road_2 = red_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = MAN_RED;
			green_time_increase = green_time;
			red_time_increase = red_time;
			amber_time_increase = amber_time;
			display_7seg_road_1 = 2;
			display_7seg_road_2 = red_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
			setTimer_led_man(1);
			setTimer_display_7seg(1);
		}
		break;
	case GREEN_RED:
		on_green_1();
		on_red_2();
		if(transfer_flag){
			setTimer_transfer(amber_time*100);
			current_state = AMBER_RED;
		}
		if(down_flag){
			setTimer_down(100);
			display_7seg_road_1--;
			display_7seg_road_2--;
			if(display_7seg_road_1 <= 0) display_7seg_road_1 = amber_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = MAN_RED;
			green_time_increase = green_time;
			red_time_increase = red_time;
			amber_time_increase = amber_time;
			display_7seg_road_1 = 2;
			display_7seg_road_2 = red_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
			setTimer_led_man(1);
			setTimer_display_7seg(1);
		}
		break;
	case AMBER_RED:
		on_amber_1();
		on_red_2();
		if(transfer_flag){
			setTimer_transfer(green_time*100);
			current_state = RED_GREEN;
		}
		if(down_flag){
			setTimer_down(100);
			display_7seg_road_1--;
			display_7seg_road_2--;
			if(display_7seg_road_1 <= 0) display_7seg_road_1 = red_time;
			if(display_7seg_road_2 <= 0) display_7seg_road_2 = green_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = MAN_RED;
			green_time_increase = green_time;
			red_time_increase = red_time;
			amber_time_increase = amber_time;
			display_7seg_road_1 = 2;
			display_7seg_road_2 = red_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
			setTimer_led_man(1);
			setTimer_display_7seg(1);
		}
		break;
	case MAN_RED:
		if(led_man_flag){
			setTimer_led_man(25);
			toggle_led_red();
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = MAN_AMBER;
			display_7seg_road_1 = 3;
			display_7seg_road_2 = amber_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
			setTimer_led_man(1);
			setTimer_display_7seg(1);
		}
		if(is_button_pressed(1)){
			red_time_increase++;
			if(red_time_increase >= 100) red_time_increase = 1;
			display_7seg_road_2 = red_time_increase;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(is_button_pressed(2)){
			red_time = red_time_increase;
		}
		break;
	case MAN_AMBER:
		if(led_man_flag){
			setTimer_led_man(25);
			toggle_led_amber();
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = MAN_GREEN;
			display_7seg_road_1 = 4;
			display_7seg_road_2 = green_time;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
			setTimer_led_man(1);
			setTimer_display_7seg(1);
		}
		if(is_button_pressed(1)){
			amber_time_increase++;
			if(amber_time_increase >= 100) amber_time_increase = 1;
			display_7seg_road_2 = amber_time_increase;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(is_button_pressed(2)){
			amber_time = amber_time_increase;
		}
		break;
	case MAN_GREEN:
		if(led_man_flag){
			setTimer_led_man(25);
			toggle_led_green();
		}
		if(display_7seg_flag){
			setTimer_display_7seg(50);
			display_7segled(index_7seg_led++);
			index_7seg_led %= 2;
		}
		if(is_button_pressed(0)){
			current_state = CHECK_STATE;
		}
		if(is_button_pressed(1)){
			green_time_increase++;
			if(green_time_increase >= 100) green_time_increase = 1;
			display_7seg_road_2 = green_time_increase;
			update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
		}
		if(is_button_pressed(2)){
			green_time = green_time_increase;
		}
		break;
	case CHECK_STATE:
		off_all_led();
		off_all_7seg();
		current_state = RED_GREEN;
		if(green_time + amber_time != red_time){
			green_time = GREEN_DEFAULT_TIME;
			red_time = RED_DEFAULT_TIME;
			amber_time = AMBER_DEFAULT_TIME;
		}
		display_7seg_road_1 = red_time;
		display_7seg_road_2 = green_time;
		setTimer_transfer(green_time*100);
		setTimer_down(100);
		setTimer_display_7seg(1);
		update_buffer_7seg(display_7seg_road_1, display_7seg_road_2);
	}
}

