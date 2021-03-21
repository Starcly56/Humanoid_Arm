/*
   Humanoid Arm
   Code for Receiver (Slave Hand)
   Anush Gajurel
   Ujjwal Humagain
   Pukar Subedi
   Jay Ram Pandey
   Dipesh Lama
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <Servo.h>
#include <RF24.h>
//defining Servos
Servo thumbServo;
Servo innerThumbServo;
Servo indexServo;
Servo middleServo;
Servo ringAndPinkyServo;
//defining variables 
int innerThumbServoPosition;
int thumbServoPosition;
int indexServoPosition;
int middleServoPosition;
int ringAndPinkyServoPosition;

RF24 radio(9, 10); // CE, CSN for the nrf module
const byte address[6] = "00001";
int flexarray[4];

void setup() {
 Serial.begin(9600);
 //attaching Servos to the pins
 thumbServo.attach(2);
 indexServo.attach(3);
 middleServo.attach(4);
 ringAndPinkyServo.attach(5);
 innerThumbServo.attach(6);
 
 radio.begin();
 radio.openReadingPipe(0, address);
 radio.setPALevel(RF24_PA_MIN);
 radio.startListening();
}

void loop() {
 if (radio.available()) {
 radio.read(flexarray, sizeof(flexarray));
 
 thumbServoPosition=map(flexarray[0],750,880,0,180);
 thumbServo.write(thumbServoPosition);
 Serial.println(thumbServoPosition);

 innerThumbServoPosition=map(flexarray[0],750,880,180,90);
 innerThumbServo.write(innerThumbServoPosition);
 Serial.println(thumbServoPosition);
 
 indexServoPosition=map(flexarray[1],440,710,0,180);
 indexServo.write(indexServoPosition);
 Serial.println(indexServoPosition);

 middleServoPosition=map(flexarray[2],620,850,0,180);
 middleServo.write(middleServoPosition);
 Serial.println(middleServoPosition);
 
 ringAndPinkyServoPosition=map(flexarray[3],430,610,0,180);
 ringAndPinkyServo.write(ringAndPinkyServoPosition);
 Serial.println(ringAndPinkyServoPosition);
 }
}
