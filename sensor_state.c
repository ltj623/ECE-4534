/*  This file is the general implementation of the FSM
 *  Author: Tingjie Liu
 *  Date: 02/03/2019
 */

#include "sensor_state.h"
#include "debug.h"

int FSM( uint8_t sensor_value, uint8_t *average, uint8_t *state )
{
    //int calculated_value;
    
    switch( *state ) {
        
        case 1:
            dbgOutputVal(sensor_value); //  output the sensor value each time
            *average = sensor_value;    //  add the value to the average
            DRV_USART0_WriteByte(*average); //  write the average to the USART
            *state = 2; //  Change to the 2nd state
            //dbgOutputLoc(FSM_state1);
            break;
            
       case 2:
            dbgOutputVal(sensor_value);
            *average = *average + sensor_value;
            DRV_USART0_WriteByte(*average);
            *state = 3;
            //dbgOutputLoc(FSM_state2);
            break;
            
       case 3:
            dbgOutputVal(sensor_value);
            *average = *average + sensor_value;
            DRV_USART0_WriteByte(*average);
            *state = 4;
            //dbgOutputLoc(FSM_state3);
            break;
            
       case 4:
            dbgOutputVal(sensor_value);
            *average = *average + sensor_value;
            DRV_USART0_WriteByte(*average);
            *state = 5;
            //dbgOutputLoc(FSM_state4);
            break;
            
        case 5:
            dbgOutputVal(sensor_value);
            *average = *average + sensor_value;
            *average = *average / 5;
           // dbgOutputLoc(FSM_state5);
           // dbgOutputLoc(send_to_USART);
            DRV_USART0_WriteByte(*average);
            *state = 1;
            break;
            
        default:
            *state = 1;
            break;
    }
    return 0;
}
