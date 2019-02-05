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

    struct MessageFromSensor{
        
        unsigned int SensorVal;
        char units[20];     //  Structure of Message
   
    };  //  Message From Sensor, includes two components: Value and units.
    
    int Generate_Sensor_Queue( unsigned int Size_of_Queue );    //  Generate a Sensor Queue with specific size value
    
    int Receive_Value_From_Sensot_Queue( struct MessageFromSensor message); //  queue output the value
    
    int Send_Value_to_Sensor_Queue(struct MessageFromSensor message, BaseType_t * higher_priority_first);   //  Queue receive value from ISR


#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_QUEUE_H */

