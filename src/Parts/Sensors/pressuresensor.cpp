#include "pressuresensor.h"
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include "Adafruit_BMP3XX.h"


#define SEALEVELPRESSURE_HPA (1003)


PressureSensor::PressureSensor() 
    : ASensor(0x53),
      bmp() {

    addCommand(this,  0x00, [](PressureSensor* t) { return t->read_data(); });

    if (!bmp.begin_I2C()) {   // hardware I2C mode, can pass in address & alt Wire
    
    }

    // Set up oversampling and filter initialization
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}


void PressureSensor::update() {
    
}

char PressureSensor::read_data() {
    if (!bmp.performReading()) 
        return Errors::JustWrong;
    
    send_Message(bmp.temperature, bmp.pressure / 100.0, bmp.readAltitude(SEALEVELPRESSURE_HPA));
    return Errors::Success;
}