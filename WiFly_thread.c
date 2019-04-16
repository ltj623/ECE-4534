#include "wifly_thread.h"

void initPorts(){
   
    //LED
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_3);
    
    // Pins 37-30
    PLIB_PORTS_DirectionOutputSet (PORTS_ID_0, PORT_CHANNEL_E, 0x01FF);
    
    // Pins 2, 72, 3, 73
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0,PORT_CHANNEL_E,PORTS_BIT_POS_8);    
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_4);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0,PORT_CHANNEL_D,PORTS_BIT_POS_0);
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0,PORT_CHANNEL_A,PORTS_BIT_POS_5);
    
    PLIB_USART_ReceiverInterruptModeSelect(USART_ID_1, USART_RECEIVE_FIFO_ONE_CHAR);
    PLIB_USART_TransmitterInterruptModeSelect(USART_ID_1, USART_TRANSMIT_FIFO_NOT_FULL);
    SYS_INT_SourceEnable(INT_SOURCE_USART_1_RECEIVE);
}

void WIFLY_THREAD_Initialize ( void )
{
    initPorts(); 
    create100msTimer();
    start100msTimer();
    currState = STATE_INIT;
    
}

void WIFLY_THREAD_Tasks ( void )
{
    struct WiFlyMsg msg_rec;
    receiveWiFlyThreadQueue(&msg_rec);
    currState = uart_FSM(currState, msg_rec);
    //"GET /Arm_State HTTP/1.1\r\nHost: 192.168.20.57\r\n\r\n"
}

 

/*******************************************************************************
 End of File
 */
