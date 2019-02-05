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
    
     if ((Volts_Val > 2.9) && (Volts_Val <= 3.2)) //   replace the volts value to distance value
        return 5;
     else if ((Volts_Val > 2.0) && (Volts_Val < 2.8))
        return 10;
     else if ((Volts_Val > 1.4) && (Volts_Val < 1.9)) 
        return 15;
     else if ((Volts_Val > 1.2) && (Volts_Val < 1.3)) 
        return 20;
     else if ((Volts_Val > 1.0) && (Volts_Val < 1.1)) 
        return 25;
     else if ((Volts_Val > 0.8) && (Volts_Val < 0.9)) 
        return 30;
     else if ((Volts_Val > 0.67) && (Volts_Val < 0.79))
        return 35;
     else if ((Volts_Val > 0.6) && (Volts_Val < 0.66)) 
        return 40;
     else if ((Volts_Val > 0.54) && (Volts_Val < 0.59))
        return 45;
     else if ((Volts_Val > 0.51) && (Volts_Val < 0.53)) 
        return 50;
     else if ((Volts_Val > 0.46) && (Volts_Val < 0.5))
        return 55;
     else if ((Volts_Val > 0.43) && (Volts_Val < 0.45)) 
        return 60;
     else if ((Volts_Val > 0.40) && (Volts_Val < 0.42))
        return 65;
     else if ((Volts_Val > 0.37) && (Volts_Val < 0.39)) 
        return 70;
     else if ((Volts_Val > 0.34) && (Volts_Val < 0.36)) 
        return 75;
     else if ((Volts_Val > 0.2) && (Volts_Val < 0.3))
        return 80;
    else
        return EXIT_FAILURE;
}