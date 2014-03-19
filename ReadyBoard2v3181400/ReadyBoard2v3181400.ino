#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

#include <Servo.h>

// Setup for pre-wired playboard #1, by Eric Weiss of Terrapin Hackers
// This code is released in the public domain

// 8x8 backpack stuff 
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();
// Digital Pins
int laser=2; //pin laser is connected to
int blue=3; // pin blue LED is connected to (PWM pin)

int toggle=4;//pin switch is connected to
int green=5;// pin green LED is connected to (PWM pin)
int red=6; // pin red LED is connected to (PWM pin)

Servo myservo; //pin motor is connected to (PWM pin)


// Analog pins
int rpot=A0; //Set the right potentiometer
int lpot=A1; //Set the left potentiometer
int flex=A2; //Flex sensor

void setup() {
  // put your setup code here, to run once:

pinMode(laser,OUTPUT); //set laser to output
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
//pinMode(motor,OUTPUT);

pinMode(toggle,INPUT); //set switch to input

Serial.begin(9600); //begin serial communication, needed for printing to serial
myservo.attach(9); //attaches servo to pin 9

matrix.begin(0x70); // pass matrix address to arduino
}

void loop() {
  // put your main code here, to run repeatedly: 
  
  
    //+++Flex Sensor
  
  int flexVal=analogRead(flex);
 int flexValScale=(flexVal*0.006842619)+1; //flexval/1023  *7+1 so is between 2 and 7
  
    //+++Display Potentiometers
  
  int lpotVal=analogRead(lpot);// store left potentiometer value
  int rpotVal=analogRead(rpot);// see lpotVal
  
  
   int rpotscale=rpotVal*0.00782013685; //(rpot/1023) *8
    int lpotscale=lpotVal*0.00782013685 ;//(rpot/1023) *8
  Serial.print("Left: ");
  Serial.print(lpotVal);
  Serial.print(" Right:");
  Serial.print(rpotVal);
  Serial.print("Leftv: ");
  Serial.print(lpotscale);
  Serial.print(" Rightv:");
  Serial.print(rpotscale);
  Serial.print(" FlexVal: ");
  Serial.print(flexValScale);
  Serial.print(" Toggle: ");
  Serial.println(digitalRead(toggle));
  
 
  
  if(digitalRead(toggle)==LOW)
  {
   matrix.setRotation(1);
  for (int8_t x=7; x>=-36; x--) {
    matrix.clear();
    matrix.setCursor(x,0);
    matrix.print(lpotVal);
    matrix.writeDisplay();
    digitalWrite(red,LOW);
    delay(100);
  }}
else if(digitalRead(toggle)==HIGH)
{
    matrix.clear();
  matrix.drawRect(rpotscale,lpotscale, flexValScale,flexValScale, LED_ON);
 // matrix.fillRect(2,2, 4,4, LED_ON);
  matrix.writeDisplay();  // write the changes we just made to the display
  delay(500);
digitalWrite(red,HIGH);
 
}
  
  //+++Flex Sensor
  /*
  int flexVal=analogRead(flex);
  Serial.println(flexVal);
  delay(100);
  */
  

   
    //+++Operating the Servo
  
  //Make sure myservo is actually attached!
  //On a continuous rotation servo, servo.write will set the speed of the servo 
  //(with 0 being full-speed in one direction, 180 being full speed in the other, 
  //and a value near 90being no movement [NOT 90, in most cases])
  
  int rate= rpotVal*.1758;// how fast and in what direction it should turn
  // rate scaled based on 180/1024
  myservo.write(rate);
  
  
  //+++ Turn LASER on, wait 2 sec, turn it off
  
  /*
  digitalWrite(laser,HIGH);
  delay(2000);
  digitalWrite(laser,LOW);
  delay(2000);
  */
  
  
    
  
  //+++ Cycle the colors of the LED
  /*
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  digitalWrite(blue,HIGH);
  delay(1000);
  digitalWrite(blue,LOW);
  digitalWrite(green,HIGH);
  delay(5000);
  digitalWrite(green,LOW);
  */
  
  
  
  
  
  delay(100);
}
