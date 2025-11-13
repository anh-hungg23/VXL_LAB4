/*
 * taskList.c
 *
 *  Created on: Nov 13, 2025
 *      Author: anh_hungg23
 */
#include "main.h"
#include "taskList.h"
#include "global.h"
void task_blinkToggle() {
	blinkyMainFlag = !blinkyMainFlag;
	blinkySubFlag  = !blinkySubFlag;
}

void task_fsmAutoRun() {
	if(mode == MODE_AUTO ){
		fsm_auto_run();
	}
}

void task_fsmManualRun() {
	if(mode == MODE_MANUAL) {
		fsm_manual_run();
	}
}

void task_readButton() {
	getKeyInput(&button1);
	getKeyInput(&button2);
	getKeyInput(&button3);;
}
void task_checkMode() {
	checkMode();
}
void task_display7SEG(){
	showTime(led_idx++);
	if(led_idx >=6) led_idx = 0;
}

void task_updateCountdown() {
	updateCountdown();
}

void task_toggleTest(){
	HAL_GPIO_TogglePin(GPIOA,RED_LED_TEST_Pin | YEL_LED_TEST_Pin | GREEN_LED_TEST_Pin);
}

void task_checkNoReact(void) {
    if ( timeNoReactMs > 0) {
        timeNoReactMs-=10;
    }
}

