// ||===================================||
// ||      CREATED by FERY SETIAWAN     ||
// ||      Technology of Univercity     ||
// ||             YOGYAKARTA            ||
// ||===================================||
// 29/07/2024
  
// ||===================================================||
// ||               !!!--- NOTE  ---!!!                 ||
// ||  Masih ada kekurangan, Dikarenakan Chome/Browser  ||
// ||  tidak mengijinkan autoplay audio dibackgroud     ||
// ||  maka saat pertama kali membuka wajib meng-klik   ||
// ||  button - ulang -, Terimakasih                    ||
// ||===================================================||

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#define button 23

#include "Page.h"

int antrian = 0;

// Pengaturan WiFi
const char* ssid = "Fry_sn";
const char* password = "//////////";

AsyncWebServer server(80);

String getdata(){
  String json = "{\"antrian\":";
  json += antrian;
  json += "}";
  return json;
}

void setup(){
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
  request->send_P(200, "text/html", index_html);
  });

  server.on("/data", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "application/json", getdata());
  });
  
  pinMode(button, INPUT);
  server.begin();
}

void loop(){
  if (digitalRead(button) == HIGH){
    delay(250);
    antrian++;
    Serial.println(antrian);
  }
}