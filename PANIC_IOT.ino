#include <SPI.h>
#include <ThingerESP8266.h>

#define USERNAME "xxxx" // thinger.io username 
#define DEVICE_ID "yyy" // thinger.io created user device
#define DEVICE_CREDENTIAL "asdwasdw" // thinger.io device credentials

ThingerESP8266 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);
int val = 0;     // variable for reading the pin status

void setup() {

pinMode(D2, OUTPUT);  // declare LED as output
pinMode(D5, INPUT_PULLUP);// declare pushbutton as input
Serial.begin(115200);
//connecting to WIFI
thing.add_wifi("*Network Name", "*Password");
Serial.println("entering the gates");
} 

void loop(){

val = digitalRead(D5);
  Serial.println(val);// read input value
  if (val == LOW) {         // check if the input is HIGH (button released)
    digitalWrite(D2, HIGH);  // turn LED OFF
    delay(2000);
            digitalWrite(D2, LOW);
           thing.handle();
           thing.call_endpoint("xxxx"); // add endpoint name in the "xxxx"
           delay(5000);
  }
  else
  digitalWrite(D2, LOW);  // turn LED ON   
}

 
