#include <Moisture.h>
#include <Temperature.h>
#include <Light.h>
#include <LCD.h>

#define ONE_WIRE_BUS 15
#define HUMIDITY 13
#define RELAY 23
#define SDA_LIGHT_INTENSITY_SENSOR 18
#define SCL_LIGHT_INTENSITY_SENSOR 19

//global variable
unsigned long previousMillisHumidity = 0;
unsigned long previousMillisTemperature = 0;
int intervall_humidity = 10000; // 10 second
int intervall_temperature = 5000;// 5 5econd

//Sensor objects
Moisture moisture(HUMIDITY);
Temperature temperature(ONE_WIRE_BUS , 0);
Light light(18 , 19 , 0x23 , BH1750::CONTINUOUS_HIGH_RES_MODE);
LCD lcd((uint8_t)39,(uint8_t)20,(uint8_t)2,"Hello :)");

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  light.begin();
  lcd.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  
  unsigned long currentMillis = millis(); // a command that returns the number of milliseconds since the board started running its current sketch
  if((currentMillis - previousMillisHumidity) == intervall_humidity){
    previousMillisHumidity = currentMillis;
    lcd.update_display(0,0,"Moi : " + (String)moisture.get_moisture_percentage() + " %");
    moisture.print_sensor_value();
  }
  
  if((currentMillis - previousMillisTemperature) == intervall_temperature){
    previousMillisTemperature = currentMillis;

    temperature.print_sensor_value();
    lcd.update_display(0,1,"Temp : " + (String)temperature.get_temp_C() + " C");
    //light.get_light_intensity();
    //light.print_light_intensity();
    
  }

}