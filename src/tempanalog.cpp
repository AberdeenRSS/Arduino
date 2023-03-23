#include "tempanalog.h"

#include <Arduino.h>


int ThermistorPin = A0;
int Vo;
float R1 = 10000; // value of R1 on board
float logR2, R2, T;
float c1 = 0.001129148, c2 = 0.000234125, c3 = 0.0000000876741;

AnalogThemp::AnalogThemp()
    : AbstractSensor(ThermistorPin, 1) { }

void AnalogThemp::init() {}

void AnalogThemp::message() const  {
    Serial.write("Temperature analog sensor activated! \n");
} 

void AnalogThemp::loop()   {
  Vo = analogRead(ThermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0); //calculate resistance on thermistor
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2)); // temperature in Kelvin
  T = T - 273.15; //convert Kelvin to Celcius
 // T = (T * 9.0)/ 5.0 + 32.0; //convert Celcius to Farenheit
  Serial.print("Temperature: "); 
  Serial.print(T);
  Serial.println(" C"); 

  delay(500);
}

