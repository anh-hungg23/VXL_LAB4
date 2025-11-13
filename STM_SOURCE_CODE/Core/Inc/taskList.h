/*
 * task_list.h
 *
 *  Created on: Nov 13, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_TASKLIST_H_
#define INC_TASKLIST_H_
#include "button.h"
#include "fsm_auto.h"
#include "fsm_manual.h"
#include "main.h"
#include "mode_control.h"
#include "set7SEG.h"
#include "setTrafficLed.h"

void task_fsmAutoRun();
void task_fsmManualRun();
void task_readButton();
void task_checkMode();
void task_blinkToggle();
void task_display7SEG();
void task_updateCountdown();
void task_toggleTest();
void task_checkNoReact();
#endif /* INC_TASKLIST_H_ */
