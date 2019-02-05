#ifndef DEBUG_H
#define	DEBUG_H

#include "app.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 127

// Task-related dbgOutputLoc arguments. 
#define DLOC_ENTERING_TASK 1
#define DLOC_BEFORE_WHILE_ONE_TASK 2
#define DLOC_BEFORE_SENDING_TASK_QUEUE 3
#define DLOC_BEFORE_RECEIVE_TASK_QUEUE 4
#define DLOC_AFTER_SENDING_TASK_QUEUE 5
#define DLOC_AFTER_RECEIVE_TASK_QUEUE 6

// ISR-related dbgOutputLoc arguments.
#define DLOC_BEFORE_ENTER_ISR 7
#define DLOC_BEFORE_LEAVE_ISR 8
#define DLOC_BEFORE_SENDING_ISR_QUEUE 9
#define DLOC_BEFORE_RECEIVE_ISR_QUEUE 10
#define DLOC_AFTER_SENDING_ISR_QUEUE 11
#define DLOC_AFTER_RECEIVE_ISR_QUEUE 12


void dbgInit();

void dbgOutputVal(unsigned int outVal);

void dbgUARTVal(unsigned char outVal);

void dbgOutputLoc(unsigned int outVal);

void dbgHaltAll(unsigned int outVal);

#endif	/* DEBUG_H */