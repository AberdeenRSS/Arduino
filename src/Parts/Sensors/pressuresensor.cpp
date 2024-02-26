#include "pressuresensor.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"


#define SEALEVELPRESSURE_HPA (1003)


PressureSensor::PressureSensor() 
    : ASensor(11, 200),
      bmp() {

    sm = new SensorMessages<sizeof(float)*2>(11, 1);

    addCommand(this,  0x00, [](PressureSensor* t) { return t->read_data(); });

    initializeSuccess = bmp.begin_I2C();   // hardware I2C mode, can pass in address & alt Wire
    
    // Set up oversampling and filter initialization
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ);

}

void PressureSensor::update() {
    this->read_data();
}

char PressureSensor::read_data() {

    // if(!initializeSuccess)
    //     return Errors::JustWrong;

    float pressure =  bmp.readPressure();
    float temperature = bmp.readTemperature();

    sm->reset();
    
    sm->addData(&pressure);
    sm->addData(&temperature);

    sm->sendMessage();
    
    return Errors::Success;
}