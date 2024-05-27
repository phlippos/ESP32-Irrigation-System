#ifndef SENSORS_H
#define SENSORS_H

#include <string>
#include <iostream>
#include <Arduino.h>

class Sensors{
    public:
        int pinNumber;

        float sensorValue;

        Sensors();
        
        Sensors(const int pinNumber);

        virtual void read_sensor_value();

        virtual void print_sensor_value();

        virtual ~Sensors();
};

#endif // SENSORS_H