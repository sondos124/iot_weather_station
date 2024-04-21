#ifndef DHT11_SENSOR_H
#define DHT11_SENSOR_H

// Define DHT11 sensor constants
#define DHTPIN 4    // Replace with the actual GPIO pin where the sensor is connected
#define DHTTYPE DHT11

// Function prototypes
void setupSensor();
void readSensorData(float &humidity, float &temperature);

#endif