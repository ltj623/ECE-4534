#ifndef _WIFLY_THREAD_H
#define _WIFLY_THREAD_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "FreeRTOS.h"
#include <queue.h>
#include "timers.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "debug.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

typedef enum {
    STATE_INIT,
    STATE_RX,
    STATE_TX,
            STATE_START_MSG,
            STATE_END_MSG
  } STATES;

//struct Message {
//    char request[250];
//};


struct WiFlyMsg {
    bool done;
    char request[250];
    int seqNum;
    char rx_rec;
};
  
STATES currState;
void WIFLY_THREAD_Initialize ( void );
void WIFLY_THREAD_Tasks( void );


#endif /* _WIFLY_THREAD_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

