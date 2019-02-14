/* This is the header file for the sensor queue 
 * File:   sensor_queue.h
 * Author: ltj623
 * 
 * Created on January 31, 2019, 8:47 AM
 */

#ifndef SENSOR_QUEUE_H
#define	SENSOR_QUEUE_H



#ifdef	__cplusplus
extern "C" {
    
#endif
    
    
#include "FreeRTOS.h"
#include <queue.h>
#include "debug.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdint.h"
#include "task.h"

// Message From the sensor, which includes two components: value and units.
struct MessageFromSensor{
    unsigned int SensorVal;
    char units[20];     //  Structure of Message
};

int Generate_Sensor_Queue( uint8_t Size_of_Queue );    //  Generate a Sensor Queue with specific size value

int Receive_Value_From_Sensor_Queue( struct MessageFromSensor message); //  queue output the value

int Send_Value_to_Sensor_Queue(struct MessageFromSensor message, BaseType_t * higher_priority_first);   //  Queue receive value from ISR


#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_QUEUE_H */

