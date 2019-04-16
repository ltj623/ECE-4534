#include "generatehttp.h"


void GENERATEHTTP_Initialize ( void )
{
        createQueue();
}

void GENERATEHTTP_Tasks ( void )
{
   // static HTTP_STATE state = HTTP_STATE_SEND_GET;
    
    struct WiFlyMsg msg;
    strcpy(msg.request, "GET /Arm_State HTTP/1.1\r\nHost: 192.168.20.57\r\n\r\n");
    sendWiFlyThreadQueue(msg);
//    state = HTTP_STATE_SEND_GET;

//        case HTTP_STATE_SEND_PUT: {
         //  static struct WiFlyMsg msg;
       //     char buff[500];
        //    char body[500];
      //      int sent_msg_size = 0;
    //        static int count = 0;
  //          static int seqNum = 1;
//            
//            sprintf(body, "{\"claw\": \"closed\", \"seqNum\":\"%d\"}", seqNum);
//            sent_msg_size = strlen(body);
//            strcpy(msg.request, "PUT /Arm_State HTTP/1.1\r\nHost: 192.168.20.57\r\nContent-Type: application/json\r\n");           
//            sprintf(buff, "Content-Length: %d\r\n\r\n%s\r\n\r\n", sent_msg_size, body);
//            strcat(msg.request, buff);
//            sendWiFlyThreadQueue(msg);
//            break;
//        }
 //   }
          


}

 

/*******************************************************************************
 End of File
 */
