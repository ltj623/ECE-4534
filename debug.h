// Created by: Samuel Park
// Last Updated: 2/7/2019

#ifndef DEBUG_H
#define	DEBUG_H

#include "app.h"
#include <stdio.h>
#include <stdlib.h>

#define MAXVAL 127

// Task-related dbgOutputLoc arguments. 
#define DLOC_ENTERING_TASK 0x01
#define DLOC_BEFORE_WHILE_ONE_TASK 0x02
#define DLOC_BEFORE_SENDING_TASK_QUEUE 0x03
#define DLOC_BEFORE_RECEIVE_TASK_QUEUE 0x04
#define DLOC_AFTER_SENDING_TASK_QUEUE 0x05
#define DLOC_AFTER_RECEIVE_TASK_QUEUE 0x06

// ISR-related dbgOutputLoc arguments.
#define DLOC_BEFORE_ENTER_ISR 0x10
#define DLOC_BEFORE_LEAVE_ISR 0x20
#define DLOC_BEFORE_SENDING_ISR_QUEUE 0x30
#define DLOC_BEFORE_RECEIVE_ISR_QUEUE 0x40
#define DLOC_AFTER_SENDING_ISR_QUEUE 0x50
#define DLOC_AFTER_RECEIVE_ISR_QUEUE 0x60


void dbgInit();

void dbgOutputVal(unsigned int outVal);

void dbgUARTVal(unsigned char outVal);

void dbgOutputLoc(unsigned int outVal);

void dbgHaltAll(unsigned int outVal);

#endif	/* DEBUG_H */

