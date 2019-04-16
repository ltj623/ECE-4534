#include "WiFly_thread_state.h"

STATES uart_FSM(STATES state, struct WiFlyMsg msg_rec){
    static char response[250];
    static int  bytes_rec = 0;
    static int  sent_msg_size = 0;
    switch(state){
        case STATE_INIT:{
            static STATES next_state;
            if(strlen(msg_rec.request) != (int) 0){
                sendUART0Queue(msg_rec);
                SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
                next_state = STATE_INIT;
            }
            else{
                next_state = STATE_TX;
            }
            return next_state;
            break;
        }
        case STATE_TX:{
            //dbgOutputLoc(0x01);
             
             static STATES next_state;
             
             if (msg_rec.done){
                 next_state = STATE_RX;
             }
             else{
                 next_state = STATE_TX;
             }

          //  dbgOutputLoc(0x02);
            return next_state;
            break;
        }
        case STATE_RX:{
         // dbgOutputLoc(0x03);
            STATES next_state;
            if(msg_rec.rx_rec == (char) '{'){
                
                next_state = STATE_START_MSG;
                response[bytes_rec] = msg_rec.rx_rec;
                bytes_rec += 1;
            }
            else{
                next_state = STATE_RX;
            }
           
        //   dbgOutputLoc(0x04);
            return next_state;
            break;
        }
        case STATE_START_MSG:{
           // dbgOutputLoc(0x05);
            STATES next_state;
            response[bytes_rec] = msg_rec.rx_rec;
            bytes_rec += 1;
            if(msg_rec.rx_rec == (char)'}'){
                bytes_rec = 0;
                next_state = STATE_END_MSG;
            }
            else {
                next_state = STATE_START_MSG;
            }
          // dbgOutputLoc(0x06);
            return next_state;
            break;
        }
        case STATE_END_MSG: {
           // dbgOutputLoc(0x07);
            int i = strlen(response);
           
            
          dbgOutputLoc(i);
           // dbgOutputLoc(0x08);
            return STATE_INIT;
            break;
        }
    }
}