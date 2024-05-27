# ESP32 Plant Monitoring and Watering System

This project uses an ESP32 to monitor and manage plant health by measuring soil moisture, temperature, light intensity, and automatically watering the plant when needed.

## Features
- **Soil Moisture Sensor**: Measures the moisture level in the soil to determine when the plant needs watering.
- **Temperature Sensor**: Monitors the ambient temperature around the plant.
- **Light Intensity Sensor**: Measures the amount of light the plant is receiving.
- **LCD Display**: Shows real-time sensor readings and system status.
- **Water Pump**: Automatically waters the plant when the soil moisture level is low.

## Components
- **ESP32**: The main microcontroller used for reading sensors and controlling the pump.
- **Soil Moisture Sensor**: Used to detect the moisture level in the soil.
- **Temperature Sensor**: Used to measure the ambient temperature.
- **Light Intensity Sensor**: Used to measure the light intensity.
- **LCD Display**: Used to display sensor readings and system status.
- **Water Pump**: Used to water the plant automatically.

## Circuit Diagram
Include a diagram or description of how to connect the components to the ESP32. For example:
- **Soil Moisture Sensor**: Connect the analog output to an analog input pin on the ESP32.
- **Temperature Sensor**: Connect the data pin to a digital input pin on the ESP32.
- **Light Intensity Sensor**: Connect the analog output to another analog input pin on the ESP32.
- **LCD Display**: Connect the data pins to the appropriate digital pins on the ESP32.
- **Water Pump**: Connect to a digital output pin on the ESP32 through a relay or transistor to control the pump.

## Software Setup
1. **Install the Arduino IDE**: If you haven't already, download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. **Install the ESP32 Board**: Follow the [ESP32 board installation guide](https://github.com/espressif/arduino-esp32#installation-instructions) to add ESP32 support to the Arduino IDE.
3. **Install Required Libraries**:
   - `LiquidCrystal` library for the LCD display.
   - `DHT` library if using a DHT temperature sensor.
   - Any other sensor-specific libraries.

   You can install libraries via the Arduino IDE Library Manager (Sketch > Include Library > Manage Libraries).

4. **Upload the Code**: Open the project code in the Arduino IDE, select the correct board and port, and upload the code to your ESP32.

## Code Overview
Here's a brief overview of the main parts of the code:

- **Setup**: Initializes the sensors, LCD display, and pump control pin.
- **Loop**: Continuously reads the sensor values, updates the LCD display, and controls the pump based on the soil moisture level.

## Usage
1. **Connect the Sensors and Pump**: Ensure all sensors and the pump are correctly connected to the ESP32 according to the circuit diagram.
2. **Power Up the System**: Connect the ESP32 to a power source.
3. **Monitor the Display**: View real-time sensor readings on the LCD display.
4. **Automatic Watering**: The system will automatically activate the pump to water the plant when the soil moisture level is below a predefined threshold.

## Troubleshooting
- **No Display on LCD**: Check the connections and ensure the contrast is set correctly using the potentiometer.
- **Sensors Not Reading Correctly**: Verify the wiring and connections, and check if the correct pins are used in the code.
- **Pump Not Activating**: Ensure the pump is connected properly and check the relay or transistor control circuit.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing
Contributions are welcome! Please fork the repository and create a pull request with your changes.

## Acknowledgments
- Thanks to the open-source community for providing libraries and resources.
- Inspired by various plant monitoring projects and tutorials available online.

## Contact
For any questions or suggestions, feel free to open an issue or contact me at kilgicihangir@gmail.com.
