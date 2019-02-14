/*  This file is the general implementation of the sensor queue
 *  There are three functions: 
 *      - Generate_Sensor_Queue: generate a new message queue
 *      - Receive_Value_From_Sensor_Queue: output the sensor value
 *      - Send_Value_to_Sensor_Queue: Send the value to the back of sensor queue from ISR
 *  Author: Tingjie Liu
 *  Date: 02/03/2019
 */

#include "sensor_queue.h"

QueueHandle_t SensorQueue = 0;

int Generate_Sensor_Queue( uint8_t Size_of_Queue )
{
    if (SensorQueue != 0){    
        return EXIT_FAILURE;  //THROW ERROR
    }
    SensorQueue = xQueueCreate(Size_of_Queue, sizeof( struct MessageFromSensor ));

    if (SensorQueue == 0){
        return EXIT_FAILURE; //THROW ERROR
    }
    else{
        return EXIT_SUCCESS;   //SUCCESSFULLY
    }
}

int Receive_Value_From_Sensor_Queue( struct MessageFromSensor message)
{
    if(SensorQueue == 0){
        return -1; // The queue is not created yet
    }
    dbgOutputLoc(DLOC_BEFORE_RECEIVE_TASK_QUEUE);   //  0x02
    BaseType_t received_value = xQueueReceive( SensorQueue, &message, portMAX_DELAY);   //waiting for the input of a new value
    dbgOutputLoc(DLOC_AFTER_RECEIVE_TASK_QUEUE);   //  0x04
    if(received_value == pdPASS){
        return message.SensorVal; //The value is received
    }
    else{
        return EXIT_FAILURE; // If the queue is empty
    }
}

int Send_Value_to_Sensor_Queue(struct MessageFromSensor message, BaseType_t * higher_priority_first)
{
    
    if(SensorQueue == 0) {
        return -1;  //  If the queue is non-exist
    }
    dbgOutputLoc(DLOC_BEFORE_SENDING_TASK_QUEUE);   //  0x01
    BaseType_t Val = xQueueSendToBackFromISR( SensorQueue, &message, higher_priority_first);
    dbgOutputLoc(DLOC_AFTER_SENDING_TASK_QUEUE);    //  0x03
    if(Val == pdPASS){
        return 0; //If the value is sent
    }
    else{
        return 1; // If the queue is full
    }
}

