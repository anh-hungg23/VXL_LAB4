/*
 * scheduler.h
 *
 *  Created on: Nov 12, 2025
 *      Author: anh_hungg23
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_
#include "main.h"
#include "global.h"

typedef struct sTask{
	void(*pFunc) (void);
	uint32_t Delay;
	uint32_t Period;
	uint32_t taskID;
	uint8_t  runMe;
	struct sTask * next;
}sTask;

extern sTask * head;
extern uint32_t nextID;
void SCH_Update(void);
void SCH_Init(void);
sTask * SCH_Creat_Task(void (*pFunc)(void), uint32_t DELAY, uint32_t PERIOD);
void SCH_Add_Task(void (*pFunc)(void), uint32_t DELAY, uint32_t PERIOD);;
void SCH_Dispatch(void);
void SCH_Delete_Task(uint32_t id);
void SCH_Delete_All_Task(void);
#endif /* INC_SCHEDULER_H_ */
