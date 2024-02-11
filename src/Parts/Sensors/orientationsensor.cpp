#include "orientationsensor.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <utility/imumaths.h>

#define QUAT_LENGTH = sizeof(double)*4;

OrientationSensor::OrientationSensor()
    : ASensor(10, 100),
      
      bno(Adafruit_BNO055(55))
{

    addCommand(this, 0x00, [](OrientationSensor *t)
               { return t->read_data(); });

    if (!bno.begin())
    {
    }

    bno.setExtCrystalUse(true);

}

void OrientationSensor::update()
{
    this->read_data();
}

char OrientationSensor::read_data()
{
    imu::Quaternion quat = bno.getQuat();
    bool calibrationState = bno.isFullyCalibrated();

    SensorMessages<sizeof(int)*4 + sizeof(bool)> sm(this->getCode(), 1);

    int w = quat.w() * 32767;
    int x = quat.x() * 32767;
    int y = quat.y() * 32767;
    int z = quat.z() * 32767;
    
    sm.addData(&w);
    sm.addData(&x);
    sm.addData(&y);
    sm.addData(&z);
    sm.addData(&calibrationState);

    sm.sendMessage();

    return 0;
}