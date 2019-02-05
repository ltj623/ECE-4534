#include "debug.h"

int DEBUG_INIT_CALLED = 0;

void dbgInit(){ 
    // ***Configure the Max32 board for respective outputs***
    // **Useful resource: http://microchipdeveloper.com/harmony:plib-ports ** 
    
    // (a) Pin Output Configuration:
    // -> Set Pins 53, 51, 49, 47, 45, 43, 41, 39 as outputs.
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5);   //39
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13);  //41
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8);   //43
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_0);   //45
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6);   //47
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11);  //49
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8);   //51
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_9);   //53
    
    // -> Set Pins 30 through 37 as outputs.
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7);   //30
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6);   //31
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5);   //32
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_4);   //33
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3);   //34
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_2);   //35
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_1);   //36
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_0);   //37
    
    // (b) USART Configuration, set up through Harmony:
    DRV_USART0_Initialize();
}

void dbgOutputVal(unsigned int outVal){
    // Verify that outVal is either less than or equal to 127.
    if(outVal > MAXVAL) return;
    
    // Ensure that the necessary pins are set as outputs.
    if(DEBUG_INIT_CALLED == 0){
        dbgInit();
        DEBUG_INIT_CALLED = 1;
    }
    
    // Toggle pin 53
    PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_9);
    
    // Write to board pins 51:-2:39.
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8, (outVal&0x40)>>6);  //51
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_11, (outVal&0x20)>>5); //49
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_6, (outVal&0x10)>>4);  //47
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_F, PORTS_BIT_POS_0, (outVal&0x08)>>3);  //45
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_G, PORTS_BIT_POS_8, (outVal&0x04)>>2);  //43
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_13, (outVal&0x02)>>1); //41
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_5, (outVal&0x01));     //39
}

void dbgUARTVal(unsigned char outVal){
    //***
    // To capture UART messages:
    // 1) Capture ASYNC signal in DigiView.
    // 2) In DigiView, set Baud Rate to 9600, 8 data bits, no parity bits, 
    //    frame length 8 characters.
    // 3) Press OK, and set the radix to ASCII.
    // 4) To read signals, connect the brown cable to Pin 1, and run DigiView.
    //***
    
    // Ensure that the necessary pins are set as outputs.
    if(DEBUG_INIT_CALLED == 0){
        dbgInit();
        DEBUG_INIT_CALLED = 1;
    }
    
    // Single USART Instance set-up through Harmony Configuration.
    DRV_USART0_WriteByte(outVal);
    
    
    // Note: The hold is to ensure that characters have enough time to be 
    //       transmitted and received successfully.
    int hold = 0;
    for(hold = 0; hold < 10000; hold++){};
}

void dbgOutputLoc(unsigned int outVal){
    // Verify that outVal is either less than or equal to 127.
    if(outVal > MAXVAL) return;
    
    // Ensure that the necessary pins are set as outputs.
    if(DEBUG_INIT_CALLED == 0){
        dbgInit();
        DEBUG_INIT_CALLED = 1;
    }
    
    // Toggle pin 37
    PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_0);
    
    // Write to board pins 36-30.
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_1, (outVal&0x40)>>6);  //36
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_2, (outVal&0x20)>>5);  //35
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_3, (outVal&0x10)>>4);  //34
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_4, (outVal&0x08)>>3);  //33
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_5, (outVal&0x04)>>2);  //32
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_6, (outVal&0x02)>>1);  //31
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7, (outVal&0x01));     //30
}

void dbgHaltAll(unsigned int outVal){
    // -> Set Pins 13 as an output for the LED.
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    
    // -> Set the LED to alert the user that the program has stopped. 
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3, 1);
    
    // -> Call dbgOutputLoc here:
    dbgOutputLoc(outVal);
    
    int timer = 0;
    while(1){
        timer = timer + 1;
        
        // Toggle the LED.
        if(timer == 2500000){
            PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
            timer = 0;
        }
    }
}