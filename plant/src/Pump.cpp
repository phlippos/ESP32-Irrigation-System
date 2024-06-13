#include "Pump.h"

Pump::Pump(int pinNumber) : pinNumber(pinNumber){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber,HIGH);
    std::cout << "Pumper object created" << std::endl;
}

Pump::~Pump(){
    std::cout << "Pumper object destroyed" << std::endl;
}

/*float Pump::determine_water_needed(float moisture_value,float temperature_value,float light_value){
    float moisture_weight = 0.4;
    float light_weight = 0.3;
    float temperature_weight = 0.3;
    float normalized_moisture = moisture_value / 100.0;
    float normalized_light = light_value / 65536.0;
    float normalized_temperature = (temperature_value + 55.0)/180.0;
    float weighted_sum = (moisture_weight * normalized_moisture +
                    light_weight * normalized_light +
                    temperature_weight * normalized_temperature);
    return weighted_sum;
}

float Pump::calculate_pump_runtime(float water_needed){
    float flow_rate_per_second = flow_rate_per_hour / 3600.0;
    float runtime_seconds = water_needed / flow_rate_per_second;
    return runtime_seconds;
}*/

void Pump::pump_water(float moisture_value,float current_millis){
    /*float water_needed = determine_water_needed(moisture_value,temperature_value,light_value);
    float runtime_seconds = calculate_pump_runtime(water_needed) * 1000;*/
    if((current_millis - previous_millis) >= 500.0 && check_status == true){
        digitalWrite(pinNumber,HIGH);
        Serial.println("stop");
        check_status = false;
    }

    if(moisture_value < 40.0 && check_status == false){
        digitalWrite(pinNumber,LOW);
        Serial.println("pumping");
        previous_millis = current_millis;
        check_status = true;
       
    }
}