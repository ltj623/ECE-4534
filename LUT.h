// Created by: Tingjie Liu
// Last Modified by: Samuel Park
// Last Updated: 2/13/2019
// ***For the 10-80cm IR sensor***

#ifndef LUT_H
#define	LUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "stdlib.h"
#include "debug.h"
#include "sensor_queue.h"
#include "sensor_state.h"
#include "Stdint.h"
#include "peripheral/usart/plib_usart.h"   
    
    
int LUT( int valADC );

void initLUT();


#ifdef	__cplusplus
}
#endif

#endif	/* LUT_H */

