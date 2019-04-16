#ifndef _WIFLY_THREAD_STATE_H    /* Guard against multiple inclusion */
#define _WIFLY_THREAD_STATE_H

#include "debug.h"
#include "WiFly_thread.h"
#include "cJSON.h"


/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

STATES uart_FSM(STATES state, struct WiFlyMsg data_rec);
    

    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif

/* *****************************************************************************
 End of File
 */
