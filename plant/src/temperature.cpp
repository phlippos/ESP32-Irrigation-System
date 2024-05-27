#include <Temperature.h>

Temperature::Temperature(int pinNumber,int index) 
    : index(index) , Sensors(pinNumber) , oneWire(pinNumber){
    temperatureSensor.setOneWire(&oneWire);
}

void Temperature::read_sensor_value(){
    temperatureSensor.requestTemperatures();
    sensorValue = temperatureSensor.getTempCByIndex(index);
}

float Temperature::get_temp_C(){
    this->read_sensor_value();
    return sensorValue;
}

void Temperature::print_sensor_value(){
    std::cout << "Temperature : " << sensorValue << " °C" << std::endl;
}