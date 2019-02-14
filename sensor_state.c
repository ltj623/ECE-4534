/*  This file is the general implementation of the FSM
 *  Author: Tingjie Liu
 *  Date: 02/03/2019
 */

#include "sensor_state.h"
#include "debug.h"

int FSM( uint8_t sensor_value, uint8_t *average, uint8_t *state )
{
    switch( *state ) {
        case 1:
            dbgOutputLoc(STATE_1);  //  0X21
            *average = sensor_value;    //  add the value to the average
            dbgOutputVal(sensor_value);
            //dbgUARTVal(*average); //  write the average to the USART
            *state = 2; //  Change to the 2nd state
            //dbgUARTVal('a');
            break;
            
        case 2:
            dbgOutputLoc(STATE_2);  //  0X22
            *average = *average + sensor_value;
            dbgOutputVal(sensor_value);
            //dbgUARTVal(*average);
            *state = 3;
            //dbgUARTVal('b');
            break;
            
        case 3:
            dbgOutputLoc(STATE_3);  //  0X23
            *average = *average + sensor_value;
            dbgOutputVal(sensor_value);
           // dbgUARTVal(*average);
            *state = 4;
            //dbgUARTVal('c');
            break;
        
        case 4:
            dbgOutputLoc(STATE_4);  //  0X24
            *average = *average + sensor_value;
            dbgOutputVal(sensor_value);
           // dbgUARTVal(*average);
            *state = 5;
            //dbgUARTVal('d');
            break;
            
        case 5:
            dbgOutputLoc(STATE_5);  //  0X25
            *average = *average + sensor_value;
            *average = *average / 5;
            dbgOutputVal(*average);
            dbgUARTVal(*average);
            //dbgUARTVal('e');
            *state = 1;
            break;
            
        default:
            *state = 1;
            break;
    }
    return 0;
}


