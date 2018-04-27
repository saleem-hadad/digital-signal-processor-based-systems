/*Mini Project 1: Moving Average
  Prepared by:    Omar Abdelrahim Ashour  1128555
                  Osamah Mahdi Al-Samraie 1321775
                  Saleem Murhaf Hadad     1337479
*/
        
#include "SPI.h"

class Analog
{

    public:
        Analog()
        {
               //For ADC
              DDRB |= 4;      //pinMode(10, OUTPUT);
              PORTB |= 4;     //digitalWrite(10, HIGH);
              
              //For DAC
              DDRB |= 2;       //pinMode(9, OUTPUT);
              PORTB |= 2;     //digitalWrite(9, HIGH);
              
              SPI.begin();
              SPI.setClockDivider(SPI_CLOCK_DIV2);
        }

        void Write(unsigned int value)
        {  
              PORTB &= 253;                                     //digitalWrite(9, LOW);
              SPI.transfer(0b00110000 | (value & 0xF00) >> 8);  //Send 4 command bits + 4 MSB bits of the value
              SPI.transfer((char)value);                        //Send the remaining 8 bits of the value
              PORTB |= 2;                                       //digitalWrite(9, HIGH);
        }            
        
        int Read()
        {                     
              PORTB &= 251;                             //digitalWrite(10, LOW);
              SPI.transfer (B00000001);                 //Send start bit
              int HighByte = SPI.transfer(B10100000);   //Channel 0  
              HighByte = HighByte & B00001111;          //We need only 12 bits. So delete anything after 12th bits 
              int LowByte = SPI.transfer(0x00);         //End transmission
              PORTB |= 4;                               //digitalWrite(10, HIGH);  
              return ((int) HighByte) <<8 | LowByte;
        }
};

 


int main()
{
    Analog analog;
    int input[9]={0,0,0,0,0,0,0,0,0};  //input signal
   
    int moving_average=9; //order of moving average
    int current_input=0;  //latest input
    while(1)
    {
        current_input= analog.Read();   //get latest input
        int output=0;
        for(int i=(moving_average-1);i>=1; i--)
        {
            input[i]=input[i-1];
            output+=input[i];
        }
   
        input[0]=current_input;
        output=(output+input[0])/moving_average;
        analog.Write(output);
    }
}

