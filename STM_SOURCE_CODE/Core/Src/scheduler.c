/*
 * scheduler.c
 *
 *  Created on: Nov 12, 2025
 *      Author: anh_hungg23
 */

#include "main.h"
#include "scheduler.h"
sTask *head = NULL;
uint32_t nextID = 1;
void SCH_Delete_All_Task(void) {
	sTask *delTask = head;
	while(delTask != NULL) {
		sTask * tmp = delTask;
		delTask = delTask->next;
		free(tmp);
	}
	head = NULL;
	nextID = 1;
}

void SCH_Init(void) {
    SCH_Delete_All_Task();
}

sTask *SCH_Create_Task(void (*pFunc)(void), uint32_t DELAY, uint32_t PERIOD) {
    sTask *newTask = (sTask*)malloc(sizeof(sTask));
    if (newTask == NULL) return NULL;
    newTask->pFunc = pFunc;
    newTask->Delay = DELAY;
    newTask->Period = PERIOD;
    newTask->runMe = 0;
    newTask->next = NULL;
    newTask->taskID = nextID++;
    return newTask;
}

void SCH_Add_Task(void (*pFunc)(void), uint32_t DELAY, uint32_t PERIOD) {
    sTask *newTask = SCH_Create_Task(pFunc, DELAY, PERIOD);
    if (newTask == NULL) return;

    if (head == NULL) {
        head = newTask;
        return;
    }

    sTask *prev = NULL;
    sTask *curr = head;
    uint32_t delta = DELAY;

    // tìm vị trí chèn
    while (curr != NULL && delta >= curr->Delay) {
        delta -= curr->Delay;
        prev = curr;
        curr = curr->next;
    }

    newTask->Delay = delta;
    if (curr != NULL) {
        curr->Delay -= delta;
    }

    if (prev == NULL) {
        newTask->next = head;
        head = newTask;
    } else {
        newTask->next = curr;
        prev->next = newTask;
    }

    if (newTask->Delay == 0) {
        newTask->runMe++;
    }
}

void SCH_Update(void) {
    if (head == NULL) return;

    if (head->Delay > 0) {
        head->Delay--;
    }

    if (head->Delay == 0) {
        head->runMe++;
    }
}

void SCH_Dispatch(void) {
    while (head != NULL && head->runMe > 0) {
        head->runMe--;

        sTask *runTask = head;
        head = head->next;
        if (head != NULL) {
            head->Delay += runTask->Delay;
        }

        runTask->pFunc();

        if (runTask->Period > 0) {
            SCH_Add_Task(runTask->pFunc, runTask->Period, runTask->Period);
        }

        free(runTask);
    }
}

void SCH_Delete_Task(uint32_t ID) {
	if (head == NULL) return;

	    sTask *curr = head;
	    sTask *tmp = NULL;

	    while (curr != NULL) {
	        if (curr->taskID == ID) {
	            if (tmp == NULL) {
	                head = curr->next;
	            } else {
	                tmp->next = curr->next;
	            }
	            free(curr);
	            return;
	        }
	        tmp = curr;
	        curr = curr->next;
	    }

}
