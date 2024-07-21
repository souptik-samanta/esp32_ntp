#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>

// Replace with your network credentials
char* ssid = "YOUR WIFI SSID";
char* password = "YOUR PASSWORD";

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 19800, 60000); // Update interval of 60 seconds

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Connect to Wi-Fi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize NTPClient
  timeClient.begin();
}

void loop() {
  // Update time
  timeClient.update();
  
  // Get the formatted time
  String formattedTime = timeClient.getFormattedTime();
  
  // Print the formatted time to the Serial Monitor
  Serial.println(formattedTime);

  // Wait for 1 second before repeating
  delay(1000);
}
