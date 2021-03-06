#include <ESP8266WebServer.h>
#include <Adafruit_NeoPixel.h>
#include <ESP8266WiFi.h>

#define SSID "IOT ARDUINO"
#define SSID_PASSWORD "iot@1234"


//Instance for NeoPixel Library
Adafruit_NeoPixel strip = Adafruit_NeoPixel(10,12,NEO_GRB+NEO_KHZ800);
ESP8266WebServer server(80);
uint32_t red_colour;
uint32_t green_colour;
uint32_t blue_colour;

void red()
{
  for(uint16_t i=0;i<strip.numPixels();i++)
  {
    strip.setPixelColor(i,red_colour);
    Serial.print("Entered Loop");  
  }
  strip.show();
}

void green()
{
  for(uint16_t i=0;i<strip.numPixels();i++)
  {
    strip.setPixelColor(i,green_colour);  
  }
  strip.show();
}

void blue()
{
  for(uint16_t i=0;i<strip.numPixels();i++)
  {
    strip.setPixelColor(i,blue_colour);  
  }
  strip.show();
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(SSID,SSID_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
      delay(500);
      Serial.print(".");
    }
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    server.begin();
    server.on("/light",light);
    //server.onNotFound(handleNotFound);
    strip.begin();
    strip.setBrightness(255);
    //uint32_t red_colour;
    red_colour=strip.Color(255,0,0);
    green_colour=strip.Color(0,255,0);
    blue_colour=strip.Color(0,0,255);
}

void light(){
    if(server.arg("state") == "red"){
    
      Serial.println("Request is for Red ");
      red();
      server.send(200,"text/plain","Red Light Turned ON");
    }

    if(server.arg("state") == "green"){

      Serial.println("Request is for Green");
      green();
      server.send(200,"text/plain","Green Light Turned ON");
    }

    if(server.arg("state") == "blue"){
    
      Serial.println("Request is for Blue ");
      blue();
      server.send(200,"text/plain","Blue Light Turned ON");
    }

    for(int i=0;i<100000000;i++){
    if(server.arg("state") == "disco"){
    
      Serial.println("Request is for Disco ");
      red();
      delay(100);
      green();
      delay(100);
      blue();
      delay(100);
      server.send(200,"text/plain","Disco Lights Turned ON");
    }
    }


  }

void loop() {
     server.handleClient();
  }
