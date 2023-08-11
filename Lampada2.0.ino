#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define PIR 2 
#define rele 16
#define botao 14
int ac;


int sensorState = 0;      // Variável para armazenar o estado do sensor
int releState = LOW;       // Variável para armazenar o estado do LED
unsigned long previousMillis = 0;  // Variável para armazenar o tempo de início do acionamento do LED
const long interval = 5000; 


void setup(){
  Serial.begin(9600);
  pinMode(rele, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(botao, OUTPUT);


  
  
}

void loop() {
  ac = digitalRead(PIR);
  Serial.println(ac);

  if(ac == 1){
    digitalWrite(rele, LOW);
    releState = HIGH;
    previousMillis = millis();
  }

  if(releState == HIGH && (millis() - previousMillis >= 5000)){
    digitalWrite(rele, HIGH);
    releState = LOW;
  }
  
   /*if( ac == 1 ){
     digitalWrite(rele, LOW);
     delay(2000);
   }else{
     digitalWrite(rele, HIGH);
   }*/
 } 
