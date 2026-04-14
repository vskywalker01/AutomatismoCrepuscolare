#ifndef __SENSOR_H__
#define __SENSOR_H__

#include "Arduino.h"
#include <math.h>

class Sensor {
    private:
    unsigned int sensorPin;
    float a;
    float b;

    public:
    Sensor(int pin,float alpha,float beta);
    unsigned int getCurrentPower();
    float getAlpha();
    float getBeta(); 
    void setAlpha(float alpha);
    void setBeta(float beta);
};

#endif 
