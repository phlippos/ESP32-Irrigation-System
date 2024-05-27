#include <Moisture.h>

Moisture::Moisture (const int pinNumber) : Sensors(pinNumber){
    pinMode(pinNumber,INPUT);
    std::cout << "Moisture Sensor is initiated";
}

void Moisture::read_sensor_value(){
    sensorValue = analogRead(pinNumber);
}

void Moisture::print_sensor_value(){
    std::cout << "Moisture level : " << percentage << " %" << std::endl;
}

void Moisture::calculate_moisture_adc_to_percentage(){
    percentage = ((4095.0 - sensorValue)/4095.0)*100;
}

float Moisture::get_moisture_percentage(){
    this->read_sensor_value();
    this->calculate_moisture_adc_to_percentage();
    return percentage;
}
