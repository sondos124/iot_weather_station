#include "dh11_sensor.h"  // Include your DHT11 sensor header
#include <DHT.h>           // Include the DHT library

DHT dht(DHTPIN, DHTTYPE);

void setupSensor() {
  dht.begin();
}

void readSensorData(float &humidity, float &temperature) {
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
}