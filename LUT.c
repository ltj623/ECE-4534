/*  This file is used to change the Sensor value to the actual distance value with centimeters(cm)
 *  This file only used for 10 to 80cm sensors
 *  Author: Tingjie Liu
 *  Date: 02/03/2019
 * 
 */


#include "LUT.h"

int LUT( int valADC )
{    
    double Volts_Val = ((double)valADC / 1023.0) * 3.3; //  convert the sensor value to volts
    
     if (Volts_Val > 1.83) //   replace the volts value to distance value
        return 10;
     else if (Volts_Val > 1.39)
        return 15;
     else if (Volts_Val > 1.11) 
        return 20;
     else if (Volts_Val > .97) 
        return 25;
     else if (Volts_Val > .85) 
        return 30;
     else if (Volts_Val > .71) 
        return 35;
     else if (Volts_Val > .64)
        return 40;
     else if (Volts_Val > .60) 
        return 45;
     else if (Volts_Val > .56)
        return 50;
     else if (Volts_Val > .53) 
        return 55;
     else if (Volts_Val > .50)
        return 60;
     else if (Volts_Val > .47) 
        return 65;
     else if (Volts_Val > .43)
        return 70;
     else if (Volts_Val > .4) 
        return 75;
     else if (Volts_Val > .60) 
        return 80;
    else
        return 128;
}