#include "system/common/sys_common.h"
#include "wifly_thread.h"
#include "generatehttp.h"
#include "system_definitions.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************
void IntHandlerDrvUsartInstance0(void)
{
    
    /* Reading the transmit interrupt flag */
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_TRANSMIT))
    {
     //  dbgOutputLoc(ENTERINT_TX);
       static bool done = true;
       static char value[500];
       static int bytes_sent = 0;
       static int msg_size = 0;
       
       if(done){
           done = false;
           struct WiFlyMsg m;
           
            // get request from queue
           if(UART0QueueEmpty() == (BaseType_t) pdFALSE){
            receiveUART0Queue(&m);
            msg_size = strlen(m.request);
            
            // copy request to value
            strcpy(value, m.request);
           }
       }
       else{
           char char_to_send;
           char_to_send = value[bytes_sent];
           
           if(char_to_send != (char)'\0'){
               PLIB_USART_TransmitterByteSend(USART_ID_1, char_to_send);
               bytes_sent += 1;
           }
               
           if(bytes_sent == (int) msg_size){
               // disable TX interrupt
               SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);
               // clear the message from the string
               memset(value,0,strlen(value));
               bytes_sent = 0;
               done = true; 
               
               // tell WiFlyThread the message has been sent
               struct WiFlyMsg doneMsg;
               doneMsg.done = true;
               sendWiFlyThreadQueueISR(doneMsg);  
            }
       }
       SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_TRANSMIT);
         //dbgOutputLoc(LEAVING_TX);   
    }
    
    /* Reading the receive interrupt flag */
     if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_RECEIVE))
    {
       // dbgOutputLoc(ENTERING_RX);
        struct WiFlyMsg msg;
        msg.done = false;
        msg.rx_rec = PLIB_USART_ReceiverByteReceive(USART_ID_1);
        
        sendWiFlyThreadQueueISR(msg);
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_1_RECEIVE);
        
       // dbgOutputLoc(LEAVING_RX);
    }
}
    
 
 /*******************************************************************************
 End of File
*/
