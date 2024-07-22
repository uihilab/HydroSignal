#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESP32Servo.h>

#include <WiFiManager.h>  //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
WiFiManager wifiManager;

Servo myservo;
int servoPin = 12;
unsigned int lastAngle = 0;

String apiJsonString;
StaticJsonDocument<250> jsonDocument;
char buffer[250];

const char* apikey = "a5453265-338c-4e9c-b419-2a3f3814a561";
// Replace with your REST API endpoint
const char* apiEndpoint = "https://github.com/uihilab/HydroSignal/api/data";
char apiAddress[200];
// Interval to check the REST API (in milliseconds)
const unsigned long apiCheckInterval = 1000;  //300000;  // 5 minutes

unsigned long lastApiCheckTime = 0;
int lastApiResult = 0;

void setup() {
  Serial.begin(115200);

  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);           // standard 50 hz servo
  myservo.attach(servoPin, 500, 2400);  // attaches the servo on pin 18 to the servo object

  // Get the ESP chip ID
  uint64_t espChipID = ESP.getEfuseMac();

  //http://hydrosignal.kaynak.me/data?apiKey=a5453265-338c-4e9c-b419-2a3f3814a561&deviceId=1
  strcpy(apiAddress, apiEndpoint);
  strcat(apiAddress, "?apiKey=");
  strcat(apiAddress, apikey);
  strcat(apiAddress, "&deviceId=");
  // Convert espChipID to hexadecimal string and append to combinedString
  char hexBuffer[17];
  sprintf(hexBuffer, "%llx", espChipID);
  strcat(apiAddress, hexBuffer);

  Serial.print("apiAddress:");
  Serial.println(apiAddress);

  wifiManager.autoConnect();
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    // Make the GET request
    http.begin(apiAddress);
    int httpCode = http.GET();

    if (httpCode > 0) {
      // Check if the response is successful
      if (httpCode == HTTP_CODE_OK) {
        // Parse JSON
        DynamicJsonDocument doc(1024);
        DeserializationError error = deserializeJson(doc, http.getString());

        if (!error) {
          // Extract angle value
          int angle = doc["angle"];
          Serial.print("Angle: ");
          Serial.println(angle);
          if (angle != lastAngle) {
            myservo.write(angle);
            lastAngle = angle;
          }
        } else {
          Serial.println("Failed to parse JSON");
        }
      } else {
        Serial.print("HTTP request failed with error code: ");
        Serial.println(httpCode);
      }
    } else {
      Serial.println("Connection failed");
    }

    // Close the connection
    http.end();
  }

  delay(5000);  // Wait
}
