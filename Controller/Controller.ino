/*
   Humanoid Arm
   Code for Transmitter (Master Hand)
   Anush Gajurel
   Ujjwal Humagain
   Pukar Subedi
   Jay Ram Pandey
   Dipesh Lama
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

//defining variables for flex sensors and initializing them to analog pins
int thumb = A0;
int index = A1;
int middle=A2;
int ringAndPinky = A3;

RF24 radio(9, 10); // CE, CSN for the nrf module
const byte address[6] = "00001";
int flexarray[4];

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  flexarray[0]=analogRead(thumb);
//  Serial.println("Thumb " + String(flexarray[0]));

  flexarray[1]=analogRead(index);
//  Serial.println("Index " +  String(flexarray[1]));

  flexarray[2]=analogRead(middle);
//  Serial.println("Middle " +  String(flexarray[2]));

  flexarray[3]=analogRead(ringAndPinky);
  Serial.println("RingAndPinky " +  String(flexarray[3]));

  radio.write(flexarray, sizeof(flexarray));
}
