#include <Moisture.h>
#include <Temperature.h>
#include <Light.h>
#include <LCD.h>
#include <AsyncTCP.h>
#include "ESPAsyncWebServer.h"
#include "Pump.h"

#define ONE_WIRE_BUS 15
#define HUMIDITY 32
#define RELAY 23
#define SDA_LIGHT_INTENSITY_SENSOR 18
#define SCL_LIGHT_INTENSITY_SENSOR 19

// Global variables
const char* ssid = "SelaM";
const char* password = "12345678.";

unsigned long previousMillis = 0;
int interval = 5000; // 5 seconds
float moisture_value = 100.0;
float temperature_value = 0.0;
float light_intensity = 0.0;

// Sensor objects
Moisture moisture(HUMIDITY);
Temperature temperature(ONE_WIRE_BUS , 0);
Light light(18 , 19 , 0x23 , BH1750::CONTINUOUS_HIGH_RES_MODE);
LCD lcd((uint8_t)39,(uint8_t)20,(uint8_t)2,"Hello :)");
Pump pump(RELAY);


// Web server and WebSocket
AsyncWebServer server(80);
AsyncWebSocket ws("/ws"); 

void f1() {
  if (!isnan(temperature_value) && !isnan(moisture_value)) {
    String json = "{\"temperature\":" + String(temperature_value) +
                  ",\"humidity\":" + String(moisture_value) + 
                  ",\"light\":" + String(light_intensity) + "}";
    ws.textAll(json);
  }
}

void handleRoot(AsyncWebServerRequest *request) {
  String message = "Temperature: " + String(temperature.get_temp_C()) + " °C\n";
  message += "Humidity: " + String(moisture.get_moisture_percentage()) + " %\n";
  message += "Light: " + String(light.get_light_intensity()) + " %\n";
  request->send(200, "text/plain", message);
}

// Function to handle WebSocket events
void onWebSocketEvent(AsyncWebSocket *server, AsyncWebSocketClient *client,
  AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_CONNECT) {
    Serial.println("WebSocket client connected");
  } else if (type == WS_EVT_DISCONNECT) {
    Serial.println("WebSocket client disconnected");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", HTTP_GET, handleRoot);
  ws.onEvent(onWebSocketEvent);
  server.addHandler(&ws);
  server.begin();
  Serial.println("HTTP server started");
  
  light.begin();
  lcd.begin();
  Serial.println("IP");
  Serial.println(WiFi.localIP());
}

void loop() {

  unsigned long currentMillis = millis();
  if ((currentMillis - previousMillis) >= interval) {
    previousMillis = currentMillis;
    moisture_value = moisture.get_moisture_percentage();
    pump.pump_water(moisture_value,currentMillis);
    lcd.update_display(0,0,"Moi : " + (String)moisture_value + " %");
    moisture.print_sensor_value();
    temperature_value = temperature.get_temp_C();
    temperature.print_sensor_value();
    lcd.update_display(0,1,"Temp : " + (String)temperature_value + " C");
    light_intensity = light.get_light_intensity();
    light.print_light_intensity();
    f1();
  }
}