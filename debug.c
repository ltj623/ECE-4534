// Created by: Samuel Park
// Last Updated: 2/12/2019

#include "debug.h"

void dbgInit(){ 
    // ***Configure the Max32 board for respective outputs***
    // ** Useful resource: http://microchipdeveloper.com/harmony:plib-ports ** 
    
    // Pin Output Configuration:
    // -> Set Pins 70, 71, 12, 13, 74, 75, 80, 81 as outputs for dbgOutputVal().
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A, 0x00FF);
    
    // -> Set Pins 30 through 37 as outputs, for dbgOutputLoc().
    PLIB_PORTS_DirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_E, 0x00FF);
}

void dbgOutputVal(unsigned int outVal){
    // Verify that outVal is either less than or equal to 127.
    if(outVal > MAXVAL) 
        return;
    
    
    // Write to Pins 70, 71, 12, 13, 74, 75, 80, 81:
    PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_A, outVal); 
    PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_7);
    
}

void dbgUARTVal(unsigned char outVal){
    //***
    // To capture UART messages:
    // 1) Capture ASYNC signal in DigiView.
    // 2) In DigiView, set Baud Rate to 9600, 8 data bits, no parity bits, 
    //    frame length 8 characters.
    // 3) Press OK, and set the radix to ASCII.
    // 4) To read signals, connect the brown cable to Pin 1, the black 
    //    cable to ground, and run DigiView.
    //***
    
    // Single USART Instance set-up through Harmony Configuration.
    DRV_USART0_WriteByte(outVal);
    
    // Note: The hold is to ensure that characters have enough time to be 
    //       transmitted and received successfully.
    int hold = 0;
    for(hold = 0; hold < 10000; hold++){};
}

void dbgOutputLoc(unsigned int outVal){
    // Verify that outVal is either less than or equal to 127.
    if(outVal > MAXVAL)
        return;

    // Write to Pins 30->37:
    PLIB_PORTS_Write(PORTS_ID_0, PORT_CHANNEL_E, outVal);
    PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_E, PORTS_BIT_POS_7);
}

void dbgHaltAll(unsigned int outVal){
    // Set Pins 13 as an output for the LED.
    PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
    
    // Set the LED to alert the user that the program has stopped. 
    PLIB_PORTS_PinWrite(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3, 1);
    
    // Call dbgOutputLoc here:
    dbgOutputLoc(outVal);
    
    // While loop related to toggling the LED; runs indefinitely:
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