/*******************************************************************************
 System Interrupts File

  File Name:
    system_interrupt.c

  Summary:
    Raw ISR definitions.

  Description:
    This file contains a definitions of the raw ISRs required to support the
    interrupt sub-system.

  Summary:
    This file contains source code for the interrupt vector functions in the
    system.

  Description:
    This file contains source code for the interrupt vector functions in the
    system.  It implements the system and part specific vector "stub" functions
    from which the individual "Tasks" functions are called for any modules
    executing interrupt-driven in the MPLAB Harmony system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    interrupt-driven in the system.  These handles are passed into the individual
    module "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2014 released Microchip Technology Inc.  All rights reserved.

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

#include "system/common/sys_common.h"
#include "app.h"
#include "system_definitions.h"
#include "math.h"
#include "sensor_queue.h"
#include <stdint.h>
#include "LUT.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************
void IntHandlerDrvUsartInstance0(void)
{
    DRV_USART_TasksTransmit(sysObj.drvUsart0);
    DRV_USART_TasksError(sysObj.drvUsart0);
    DRV_USART_TasksReceive(sysObj.drvUsart0);
}
 
void IntHandlerDrvTmrInstance0(void) {
    dbgOutputLoc(DLOC_AFTER_ENTER_ISR); //  0x14
    
    struct MessageFromSensor Message;  // New message for storing the value & units
    BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
    
    // -> ADC Operations:
    DRV_ADC_Open();    // Enable the ADC
    DRV_ADC_Start();   // Start the ADC
    PLIB_ADC_StopInIdleDisable(ADC_ID_1);  //	Continue ADC module operation when the device is in Idle mode
     
    BaseType_t Priority = pdFALSE;  // Set the Priority to false
    BaseType_t *p2 = &Priority;     // Pointer to the priority
    
    uint32_t ADC_Val = DRV_ADC_SamplesRead(0); //  Read the ADC value 
              
    // -> Determine the distance based on a look-up table.
    int Distance = LUT(ADC_Val);

    // -> Add centimeter units to the message:
    Message.units[0] = 'C';
    Message.units[1] = 'e';
    Message.units[2] = 'n';
    Message.units[3] = 't';
    Message.units[4] = 'i';
    Message.units[5] = 'm';
    Message.units[6] = 'e';
    Message.units[7] = 't';
    Message.units[8] = 'e';
    Message.units[9] = 'r';
    Message.units[10] = 's';

    Message.SensorVal = Distance;
      
    dbgOutputLoc(DLOC_BEFORE_SENDING_ISR_QUEUE);    //  0x12
    // -> Send the value to the queue
    int result = Send_Value_to_Sensor_Queue(Message, p2);
    dbgOutputLoc(DLOC_AFTER_SENDING_ISR_QUEUE); //   0x15

    // -> Clear the interrupt flag for the ISR
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_TIMER_2);
    
    dbgOutputLoc(DLOC_BEFORE_LEAVE_ISR);    //  0x11
    
    portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken);
}
 /*******************************************************************************
 End of File
*/
