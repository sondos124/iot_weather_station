#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>


/* WiFi credentials */
#define WIFI_SSID "sondos"/*"TOPNET_F5A8"*/
#define WIFI_PASSWORD "sondostha"/*"BCBSUU3422" */      

/* Firebase RTDB */
#define DATABASE_URL "weatherstation-39665-default-rtdb.firebaseio.com"
#define DATABASE_SECRET "MXXCXSCfQ4Zu6ob2mgGSaIEds3EONgg20aQhIrsI"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

unsigned long dataMillis = 0;
int count = 0;

void resetESP() {
  Serial.println("Resetting ESP...");
  ESP.restart();
}

// The setup for Firebase alone
void setupFirebase() {
    Serial.begin(115200);

    // Wait for WiFi connection
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print("a");
        delay(1000);
    }
    Serial.println();

    // Set the Firebase database URL and secret
   Firebase.begin(&config, &auth);

    Serial.println("Connected to WiFi");
}

// Function to send data to Firebase
void sendDataToFirebase(float humidity, float temperature) {
    // Your logic to send data to Firebase using humidity and temperature
     FirebaseJson json;
    json.add("humidity", humidity);
    json.add("temperature", temperature);
    String jsonData;
    json.toString(jsonData);

    // Set the data at the specified path in the database
    String path = "/weather_data/" + String(count);  // Assuming you want to store data under the "weather_data" node with a unique key
    if (Firebase.set(fbdo, path.c_str(), jsonData)) {
        Serial.println("Data sent to Firebase successfully!");
        count++;
    } else {
        Serial.println("Failed to send data to Firebase. " + fbdo.errorReason());
    }
}