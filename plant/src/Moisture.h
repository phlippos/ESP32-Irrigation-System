#ifndef MOISTURE_H
#define MOISTURE_H

#include <Sensors.h>

class Moisture : public Sensors{
    private:
        float percentage;
        void calculate_moisture_adc_to_percentage();
        void read_sensor_value() override;
               
    public:
        Moisture(int pinNumber);    
        float get_moisture_percentage();
        void print_sensor_value() override;
        
};

#endif
