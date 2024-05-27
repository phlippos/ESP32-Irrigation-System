#ifndef TEMPERATURE_H
#define TEMPERATURE_H

#include <DallasTemperature.h>
#include <OneWire.h>
#include <Sensors.h>

class Temperature : public Sensors{
    private:
        /* data */
       DallasTemperature temperatureSensor;
       OneWire oneWire;
       int index;
       void read_sensor_value() override;
    public:
        Temperature(int pinNumber,int index);
        float get_temp_C();
        void print_sensor_value() override;
};


#endif

