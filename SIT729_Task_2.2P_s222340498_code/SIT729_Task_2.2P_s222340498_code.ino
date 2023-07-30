//#include <ArduinoWiFiServer.h>
//#include <BearSSLHelpers.h>
//#include <CertStoreBearSSL.h>
//#include <ESP8266WiFi.h>
//#include <ESP8266WiFiAP.h>
//#include <ESP8266WiFiGeneric.h>
//#include <ESP8266WiFiGratuitous.h>
//#include <ESP8266WiFiMulti.h>
//#include <ESP8266WiFiScan.h>
//#include <ESP8266WiFiSTA.h>
//#include <ESP8266WiFiType.h>
//#include <WiFiClient.h>
//#include <WiFiClientSecure.h>
//#include <WiFiClientSecureBearSSL.h>
//#include <WiFiServer.h>
//#include <WiFiServerSecure.h>
//#include <WiFiServerSecureBearSSL.h>
//#include <WiFiUdp.h>

#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>
#include <WiFiUdp.h>
#include <ThingSpeak.h>
#include <Wire.h> 
//#include <SerialESP8266wifi.h>
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
//#include <ESP8266WiFi.h> 
SoftwareSerial esp8266(2,3);

//#define SSID "ELGAR120" // Your wifi ssid
//#define PASS "DIGIT007"
//
////const char* ssid = "ELGAR120"; // Your wifi ssid
////const char* password = "DIGIT007"; //Your wifi password
//
//unsigned long myChannelNumber = 2223893;
//const char* myWriteAPIKey = "EBC3ARKWE8NT5AWO";
//
//const char* server = "api.thingspeak.com";
//
//WiFiClient client;
//
//void updateThingSpeak(int analogSensor3, int analogSensor9, int flame_detected){
//  ThingSpeak.setField(1,flame_detected);
//  ThingSpeak.setField(2,analogSensor3);
//  ThingSpeak.setField(3,analogSensor9);
//
//  ThingSpeak.writeFields(myChannelNumber,myWriteAPIKey);
//  delay(20*1000);
//     
//}


int buzzer = 10;
#define gas3 A0
#define gas9 A1
//int sensorThreshold = 60;
int flame_sensor = 8;
const int rs = 13, en = 7, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
//SoftwareSerial A6GSM(6,9); //A6 Tx & Rx is connected to Arduino #6 & #9


void setup() {

//Serial.begin(9600);
//    ThingSpeak.begin(client);
//    WiFi.begin(SSID, PASS);
//
//    while (WiFi.status() != WL_CONNECTED)
//    {
//        delay(500);
//        Serial.print("wifi not connected! \n");
//    }
//
//   // lcd.println("");
//    Serial.print("Wifi Connected!");
//    Serial.println("IP address: ");
//    Serial.println(WiFi.localIP());


    
pinMode(buzzer, OUTPUT);
pinMode(gas3, INPUT);
pinMode(gas9, INPUT);
pinMode(flame_sensor, INPUT);
lcd.begin(16,2);
Serial.begin(9600);
//delay(500);

}

void loop() {

int analogSensor3 = digitalRead(gas3);
int analogSensor9 = digitalRead(gas9);
int flame_detected = digitalRead(flame_sensor);

Serial.print("MQ-9: \n");
Serial.println(analogSensor3);
Serial.print("MQ-0: \n");
Serial.println(analogSensor9);
Serial.print("Flame: \n");
Serial.println(flame_detected);

/*for (int positionCounter = 0; positionCounter < 15; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(220);
  }*/

  
// ONLY GAS
if ( analogSensor3 == 1 || analogSensor9 == 1)
{
  if (flame_detected == 1){
//Serial.write(110);
delay(100);
tone(buzzer, 1000, 800);
lcd.setCursor(0,0);
lcd.print("Gas & Flame Detected!!");
Serial.print("Gas & Flame Detected!! \n");
delay(1000);

  }

else {
delay(1000);
tone(buzzer, 1000, 800);
lcd.setCursor(0,0);
lcd.print(" Only Gas Detected!");
Serial.print(" Only Gas Detected! \n");
delay(1000);
 }


}
else
{
if (flame_detected == 1){
//Serial.write(101);
delay(1000);
tone(buzzer, 1000, 800);
lcd.setCursor(0,0);
lcd.print("Only Flame Detected!!");
Serial.print("Only Flame Detected!! \n");
delay(1000);

//yes();
//yes1();
//yes2();
}

else{
noTone(buzzer);
lcd.setCursor(0,0);
lcd.print("All Okay!!");
Serial.print("All Okay!! \n");
//Serial.write(999);
delay(1000);
  }
}
delay(1000);
lcd.clear();



//if(client.connect(server,80)){
//        updateThingSpeak(analogSensor3,analogSensor9,flame_detected);
//
//}
}

/*void yes(){
  Serial.begin(9600);
  delay(500);
  //Begin serial communication with Arduino and A6
  A6GSM.begin(9600);
  delay (50);
  Serial.println("Initiating A6"); 
  delay(50);

  A6GSM.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(50);
  //Serial.println("Text");
  A6GSM.println("AT+CMGF=1"); // Configuring TEXT mode
  delay (100);
  A6GSM.println("AT+CMGS=\"+8801817286223\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //A6GSM.println("AT+CMGS=\"+8801817286223\"");
  delay(1000);
  //change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //delay(3000);
    A6GSM.println("Gas-Leak and/or flame detected in kitchen."); //text content
  delay(1000);
  A6GSM.println(char(26));
  delay(100);
  }*/
  

  /*void yes1(){
  Serial.begin(9600);
  delay(500);
  //Begin serial communication with Arduino and A6
  A6GSM.begin(9600);
  delay (1000);
  Serial.println("Initiating A6"); 
  delay(1000);

  A6GSM.println("AT"); //Once the handshake test is successful, it will back to OK
  delay(1000);
  //Serial.println("Text");
  A6GSM.println("AT+CMGF=1"); // Configuring TEXT mode
  delay (1000);
  A6GSM.println("AT+CMGS=\"+8801775520904\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //A6GSM.println("AT+CMGS=\"+8801817286223\"");
  delay(3000);
  //change ZZ with country code and xxxxxxxxxxx with phone number to sms
  //delay(3000);
    A6GSM.println("Gas-Leak and/or flame detected in kitchen."); //text content
  delay(3000);
  A6GSM.println(char(26));
  delay(2000);
  }*/
