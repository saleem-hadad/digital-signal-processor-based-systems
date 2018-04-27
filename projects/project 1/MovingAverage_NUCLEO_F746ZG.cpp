/*	Mini Project 1: Moving Average

	Prepared by: 	Omar Abdelrahim Ashour	1128555
					Osamah Mahdi Al-Samraie	1321775
					Saleem Murhaf Hadad		1337479
*/
				
#include "mbed.h"

AnalogIn input(PF_3);	//A3

#if !DEVICE_ANALOGOUT
#error You cannot use this example as the AnalogOut is not supported on this device.
#else
AnalogOut output(PA_5);	//D13
#endif


int main()
{
    float x[60];
    int MAV = 60;
    float y = 0;
    float latest_x=0;
    while (1) 
    {
         latest_x = input.read();
       
        for(int i = (MAV - 1); i >= 1; i--) 
        {
            x[i] = x[i - 1];
            y += x[i];
        }
        x[0] = latest_x;
        y = (y + x[0]) / MAV;

        output.write(y);
    }

}
