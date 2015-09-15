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

struct AdcData
{
 MCP3008 mcp;
 int samples[8];
};

AdcData adcs[10] = {
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 10),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 11),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 12),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 13),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 14),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 15),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 16),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 17),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 18),{}},
  {MCP3008(CLOCK_PIN, MOSI_PIN, MISO_PIN, 19),{}}
};

void readSingleMCPa(AdcData &adc_data){
    for (int i = 0; i < 8; ++i)
  {
   adc_data.samples[i] = adc_data.mcp.readADC(i);
  }
}

void readAll(){
 for (int j = 0; j < sizeof(adcs)/sizeof(adcs[0]); ++j)
 {
  readSingleMCP(adcs[j]);
 }
}

void printData(){
//data to be printed on serial monitor only for debugging purposes uncomment if needed
 for (int j = 0; j < sizeof(adcs)/sizeof(adcs[0]); ++j)
 {   
  Serial.println("---------------------");
  Serial.printf("|    ADC no. %d     |\n",j);
  Serial.println("---------------------");
  for (int i = 0; i < 8; ++i)
  {
   Serial.printf("| channelno %d => %d |\n",i,adcs[j].samples[i]);
  }
  Serial.println("---------------------");
 }
}


void loop(){
 readAll();
 printData();  
}

void setup(){
  Serial.begin(9600);
}
