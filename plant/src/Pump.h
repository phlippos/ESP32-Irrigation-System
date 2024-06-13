#ifndef PUMP_H
#define PUMP_H
#include <Arduino.h>
#include <iostream>
class Pump {
    private :
        const int pinNumber;
        const float flow_rate_per_hour = 120.0;
        float previous_millis;
        bool check_status = false;
    public :
        Pump(const int pinNumber);
        ~Pump();
       /* float determine_water_needed(float moisture_value,float temperature_value,float light_value);
        float calculate_pump_runtime(float water_needed);*/
        //void pump_water(unsigned long start_time, float moisture_value, float temperature_value, float light_value);
        void pump_water(float moisture_value,float current_millis);
};




#endif