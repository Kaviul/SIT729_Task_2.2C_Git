#include <SerialESP8266wifi.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ThingSpeak.h>
#include <Wire.h> 
//#include <SerialESP8266wifi.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
//#include <ESP8266WiFi> 
SoftwareSerial esp8266(2,3);

#define SSID "ELGAR120" // Your wifi ssid
#define PASS "DIGIT007"

unsigned long myChannelNumber = 2223893;
const char* myWriteAPIKey = "EBC3ARKWE8NT5AWO";

const char* server = "api.thingspeak.com";

WiFiClient client;

void updateThingSpeak(int analogSensor3, int analogSensor9, int flame_detected){
  ThingSpeak.setField(1,flame_detected);
  ThingSpeak.setField(2,analogSensor3);
  ThingSpeak.setField(3,analogSensor9);

  ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
  delay(20*1000);
     
}





void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
    ThingSpeak.begin(client);
    WiFi.begin(SSID, PASS);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print("wifi not connected! \n");
    }

   // lcd.println("");
    Serial.print("Wifi Connected!");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
