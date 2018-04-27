/*	
    Mini Project 1: Moving Average

	Prepared by: 
    Omar Abdelrahim Ashour	   1128555
	Osamah Mahdi Al-Samraie	   1321775
    Saleem Murhaf Hadad		   1337479
*/

#include "mbed.h"

AnalogIn input(PF_3);
AnalogOut output(PA_5);

int main()
{
    int movingAverage = 60;
    float x[60], result = 0, input = 0;
    
    while (1) 
    {
        input = input.read();
       
        for(int i = (movingAverage - 1); i >= 1; i--) 
        {
            x[i] = x[i - 1];
            result += x[i];
        }

        x[0] = input;

        result = (result + x[0]) / movingAverage;

        output.write(result);
    }
    return 0;
}
