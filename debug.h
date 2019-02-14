// Created by: Samuel Park
// Last Updated: 2/12/2019

#ifndef DEBUG_H
#define	DEBUG_H

#include "app.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAXVAL 127

// Task-related dbgOutputLoc arguments. 
#define DLOC_BEFORE_SENDING_TASK_QUEUE 0x01
#define DLOC_BEFORE_RECEIVE_TASK_QUEUE 0x02
#define DLOC_AFTER_SENDING_TASK_QUEUE 0x03
#define DLOC_AFTER_RECEIVE_TASK_QUEUE 0x04

// ISR-related dbgOutputLoc arguments.
#define DLOC_BEFORE_LEAVE_ISR 0x11
#define DLOC_BEFORE_SENDING_ISR_QUEUE 0x12
#define DLOC_BEFORE_RECEIVE_ISR_QUEUE 0x13
#define DLOC_AFTER_ENTER_ISR 0x14
#define DLOC_AFTER_SENDING_ISR_QUEUE 0x15
#define DLOC_AFTER_RECEIVE_ISR_QUEUE 0x16

//  FSM-related dbgOutputLoc arguments.
#define STATE_1 0x21
#define STATE_2 0x22
#define STATE_3 0x23
#define STATE_4 0x24
#define STATE_5 0x25


void dbgInit();

void dbgOutputVal(unsigned int outVal);

void dbgUARTVal(unsigned char outVal);

void dbgOutputLoc(unsigned int outVal);

void dbgHaltAll(unsigned int outVal);

#endif	/* DEBUG_H */
