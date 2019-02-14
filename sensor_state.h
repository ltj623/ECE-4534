/* 
 * File:   sensor_state.h
 * Author: ltj623
 *
 * Created on February 3, 2019, 8:30 PM
 */

#ifndef SENSOR_STATE_H
#define	SENSOR_STATE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "Stdint.h"

    
int FSM( uint8_t sensor_value, uint8_t *average, uint8_t *state );

#ifdef	__cplusplus
}
#endif

#endif	/* SENSOR_STATE_H */

