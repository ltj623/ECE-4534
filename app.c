/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "debug.h"
#include "sensor_queue.h"
#include "sensor_state.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/


/*THIS IS DELETED FOR M1*/
//APP_DATA appData;
/*THIS IS DELETED FOR M1*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/


// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    
    /*THIS IS DELETED FOR M1*/
    //appData.state = APP_STATE_INIT;
    /*THIS IS DELETED FOR M1*/
    
    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
    
    int result = Generate_Sensor_Queue(10); 
    if (result !=0)
    {
        dbgHaltAll(result);
        //stopEverything(12,result);
        
    }
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{
    //dbgOutputLoc(initiate_task);

    PLIB_INT_SourceEnable(INT_ID_0, INT_SOURCE_TIMER_2); 
    DRV_TMR0_Start();   //  start the timer
    
    struct MessageFromSensor message;   //  Initialize a meesage queue
    uint8_t state = 1;  //  Initialize the state to 1
    uint8_t avg = 0;    //  Initialize the average value to 0
    
    //dbgOutputLoc(entering_loop);
    while(1) {
        //dbgOutputLoc(before_queuing_send);
        
        int result = Receive_Value_From_Sensot_Queue(message);  //  receive the distance value from Message Queue
        int temp = result;   //  copy the value to a temp variable
        
        //dbgOutputLoc(message.sensorValue);
        result = FSM(temp, &avg, &state);   //  running the FSM to store the value
    }
    /* Check the application's current state. */
    
/*switch case that should be deleted*/ 
//    switch ( appData.state )
//    {
//        /* Application's initial state. */
//        case APP_STATE_INIT:
//        {
//            bool appInitialized = true;
//       
//        
//            if (appInitialized)
//            {
//            
//                appData.state = APP_STATE_SERVICE_TASKS;
//            }
//            break;
//        }
//
//        case APP_STATE_SERVICE_TASKS:
//        {
//        
//            break;
//        }
//
//        /* TODO: implement your application state machine.*/
//        
//
//        /* The default state should never be executed. */
//        default:
//        {
//            /* TODO: Handle error in application's state machine. */
//            break;
//        }
//    }
        
}

 

/*******************************************************************************
 End of File
 */
