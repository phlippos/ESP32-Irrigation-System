#include <Sensors.h>

Sensors::Sensors(){
    std::cout << "Sensor is created " << std::endl;
}

Sensors::Sensors(int pinNumber) : pinNumber(pinNumber){
    std::cout << "Sensor is created with pin "<< pinNumber << std::endl;
}

void Sensors::read_sensor_value(){};

void Sensors::print_sensor_value(){};

Sensors::~Sensors(){
    std::cout << "Sensors destructor called" << std::endl;
}


