/*  This file is the general implementation of the sensor queue
 *  There are three functions: 
 *      - Generate_Sensor_Queue: generate a new message queue
 *      - Receive_Value_From_Sensot_Queue: output the sensor value
 *      - Send_Value_to_Sensor_Queue: Send the value to the back of sensor queue from ISR
 *  Author: Tingjie Liu
 *  Date: 02/03/2019
 */

#include "sensor_queue.h"

QueueHandle_t SensorQueue = 0;

int Generate_Sensor_Queue( unsigned int Size_of_Queue )
{
    
    if (SensorQueue != 0)
    {    
        return EXIT_FAILURE;  //THROW ERROR
    }
        SensorQueue = xQueueCreate(Size_of_Queue, sizeof( struct MessageFromSensor));
    
        if (SensorQueue == 0)
        {
            return EXIT_FAILURE; //THROW ERROR
        }
        else
        {
            return EXIT_SUCCESS;   //SUCCESSFULLY
        }
        return 0;
}

int Receive_Value_From_Sensot_Queue( struct MessageFromSensor message)
{
        if(SensorQueue == 0)
    {
        //dbgOutputLoc(queue_does_not_exist);
        return -1; // The queue is not created yet
    }
    //dbgOutputLoc(before_receive_message);
    BaseType_t received_value = xQueueReceive( SensorQueue, &message, portMAX_DELAY);   //waiting for the input of a new value
    //dbgOutputLoc(receive_msg);
    if(received_value == pdPASS) 
    {
        //dbgOutputLoc(message.sensorValue);
        return message.SensorVal; //The value is received
    }
    else 
    {
        //dbgOutputLoc(queue_is_empty);
        return EXIT_FAILURE; // If the queue is empty
    }
}

int Send_Value_to_Sensor_Queue(struct MessageFromSensor message, BaseType_t * higher_priority_first)
{
    if(SensorQueue == 0) {
        return -1;  //  If the queue is non-exist
    }
    
    BaseType_t Val = xQueueSendToBackFromISR( SensorQueue, &message, higher_priority_first);
    
    if(Val == pdPASS)
    {
        return 0; //If the value is sent
    }
    else 
    {
        return 1; // If the queue is full
    }
}

