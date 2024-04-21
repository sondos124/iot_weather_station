#include <Arduino.h>
#include "dh11_sensor.h"
#include "firebase.h"

void setup() {
    Serial.begin(115200);
    Serial.println("Initializing setupSensor()...");
    setupSensor();       // Set up the DHT11 sensor
    setupFirebase();     // Set up the Firebase configuration
}

void loop() {
    float humidity, temperature;
    readSensorData(humidity, temperature);  // Read sensor data
    // Print data to Serial Monitor
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Temperature: ");
    Serial.print(temperature);
    Serial.println("°C");
    sendDataToFirebase(humidity, temperature);  // Send data to Firebase
    delay(1000);  // Send data every minute
}