#include "temph.h"

#include <Adafruit_Sensor.h>

#define DHTPIN 2             // Digital pin connected to the DHT sensor 
#define DHTTYPE    DHT11     // DHT 11

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;

HumTemp::HumTemp() 
    :  AbstractSensor(2, 1) {}


void HumTemp::init() {
      dht.begin();
      
      // Print temperature sensor details.
      sensor_t sensor;
      dht.temperature().getSensor(&sensor);
      dht.humidity().getSensor(&sensor);
     
      // Set delay between sensor readings based on sensor details.
      delayMS = sensor.min_delay / 10000;
  

}

void HumTemp::message() const  {
    Serial.write("Temperature and Humidity sensort activated! \n");
} 

void HumTemp::loop()   {
      // Delay between measurements.
      delay(delayMS);

      // Get temperature event and print its value.
      sensors_event_t event;
      dht.temperature().getEvent(&event);
      if (isnan(event.temperature)) {
        Serial.println(F("Error reading temperature!"));
      }
      else {
        Serial.print(F("Temperature: "));
        Serial.print(event.temperature);
        Serial.println(F("°C"));
      }

      // Get humidity event and print its value.
      dht.humidity().getEvent(&event);
      if (isnan(event.relative_humidity)) {
        Serial.println(F("Error reading humidity!"));
      }
      else {
        Serial.print(F("Humidity: "));
        Serial.print(event.relative_humidity);
        Serial.println(F("%"));
      }
}

