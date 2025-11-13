/*
 * fsm_auto.c
 *
 *  Created on: Oct 26, 2025
 *      Author: anh_hungg23
 */

#include "fsm_auto.h"
#include "main.h"
#include "global.h"
#include "setTrafficLed.h"
#include "set7SEG.h"
#include "button.h"
//#include "mode_control.h"

int main_status = 0;
int sub_status = 0;

int timeRed   = 5000;
int timeYel   = 2000;
int timeGreen = 3000;


void fsm_auto_run_main() {
	switch(main_status) {
	case MAIN_INIT:
		turnOffMainLeds();
		main_status = MAIN_RED;
		mainTimeRemain = timeRed/1000;

		break;

	case MAIN_RED:
		redOnMain();
		if(mainTimeRemain <= 0 ){
			main_status = MAIN_GREEN;
			mainTimeRemain = timeGreen/1000;
		}

		break;

	case MAIN_YEL:
		yellowOnMain();
		if(mainTimeRemain <= 0 ){
			main_status = MAIN_RED;
			mainTimeRemain = timeRed/1000;
		}
		break;

	case MAIN_GREEN:
		greenOnMain();
		if(mainTimeRemain <= 0 ){
			main_status = MAIN_YEL;
			mainTimeRemain = timeYel/1000;
		}
		break;

	default:
		break;
	}
}

void fsm_auto_run_sub() {
	switch(sub_status) {
	case SUB_INIT:
		turnOffSubLeds();
		sub_status = SUB_GREEN;
		subTimeRemain = timeGreen/1000;

		break;
	case SUB_RED:
		redOnSub();
		if(subTimeRemain <= 0 ){
			sub_status = SUB_GREEN;
			subTimeRemain = timeGreen/1000;
		}

		break;
	case SUB_YEL:
		yellowOnSub();
		if(subTimeRemain <= 0 ){
			sub_status = SUB_RED;
			subTimeRemain = timeRed/1000;
		}

		break;
	case SUB_GREEN:
		greenOnSub();
		if(subTimeRemain <= 0 ){
			sub_status = SUB_YEL;
			subTimeRemain = timeYel/1000;
		}

		break;
	default:
		break;
	}
}

void fsm_auto_run() {
		fsm_auto_run_main();
		fsm_auto_run_sub();
}



