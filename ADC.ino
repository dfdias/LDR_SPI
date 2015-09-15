#include <Arduino.h>
#include <MCP3008.h>

#define MISO_PIN 12
#define MOSI_PIN 11
#define CLOCK_PIN 13
#define CS_PIN0 10
//#define CS_PIN1 13
//#define CS_PIN2 14
//#define CS_PIN5 17
//#define CS_PIN6 18
//#define CS_PIN8 20
//#define CS_PIN9 21


MCP3008 adc[10];

adc[0] = MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN0);
//adc[1] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN1);
//adc[2] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN2);
//adc[3] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN3);
//adc[4] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN4);
//adc[5] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN5);
//adc[6] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN6);
//adc[8] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, SC_PIN8);
//adc[9] = MCP3008 adc(CLOCK_PIN, MOSI_PIN, MISO_PIN, CS_PIN9);



void setup{
	Serial.begin(9600);
}
void loop{
	readADC(11,adc);
	printData();
	
}
void read(int ADCidx, MCP3008[] adc){
 if (ADCidx = 11)				
 //if the input is 11 it will read the contents of all ADC's
 {
  for (int j = 0; j < adc.length(); ++i)
  {
   for (int i = 0; i < adc.sammples.length(); ++i)
   {
    adc[j].samples[i] = adc.readADC(i);
   }
  }
 }else
  for (int i = 0; i < count; ++i)
  {
   adc[ADCidx].samples[i]= adc[ADCidx].readADC();
  }
}

/*
void printData()
//data to be printed on serial monitor only for debugging purposes uncomment if needed
 for (int i = 0; i < count; ++i)
 {   
  Serial.println("---------------------");
  Serial.printf("|    ADC no. %d     |\n",j);
  Serial.println("---------------------");
  for (int i = 0; i < count; ++i)
  {
   Serial.printf("| channelno %d => %d |\n",i,adc[j].samples[i]);
  }
  Serial.println("---------------------");
 }
}
*/
