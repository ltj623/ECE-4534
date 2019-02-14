// Created by: Tingjie Liu
// Last Modified by: Samuel Park
// Last Updated: 2/13/2019
// ***For the 10-80cm IR sensor***

#include "LUT.h"

int LUTarray[1024];

void initLUT(){
    int i;
    
    // Generate a look-up table of size 2^10 (1024) for the 10-80cm IR sensor. 
    for(i = 275; i < 1024; i++){ LUTarray[i] = 10; }
    for(i = 247; i < 275; i++){ LUTarray[i] = 15; }
    for(i = 215; i < 247; i++){ LUTarray[i] = 20; }
    for(i = 185; i < 215; i++){ LUTarray[i] = 25; }
    for(i = 165; i < 185; i++){ LUTarray[i] = 30; }
    for(i = 155; i < 165; i++){ LUTarray[i] = 35; }
    for(i = 130; i < 155; i++){ LUTarray[i] = 40; }
    for(i = 115; i < 130; i++){ LUTarray[i] = 45; }
    for(i = 105; i < 115; i++){ LUTarray[i] = 50; }
    for(i = 95; i < 105; i++){ LUTarray[i] = 55; }
    for(i = 87; i < 95; i++){ LUTarray[i] = 60; }
    for(i = 81; i < 87; i++){ LUTarray[i] = 65; }
    for(i = 76; i < 81; i++){ LUTarray[i] = 70; }
    for(i = 70; i < 76; i++){ LUTarray[i] = 75; }
    for(i = 0; i < 70; i++){ LUTarray[i] = 80; }
    
    return;
}

int LUT( int valADC )
{      
    int tmp = valADC * 100;
    int value = (tmp / 1023) * 3.3;
    
    // Eliminate the possibility of any indexing errors.
    if(value > 1024) return 80;
    else if(value < 0) return 0;
   
    return LUTarray[value];
}