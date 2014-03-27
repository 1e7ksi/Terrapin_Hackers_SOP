#include <Servo.h>

// Setup for pre-wired playboard #1, by Eric Weiss of Terrapin Hackers
// This code is released in the public domain. 

// Digital Pins
int laser=2; //pin laser is connected to
int blue=3; // pin blue LED is connected to (PWM pin)

int toggle=4;//pin switch is connected to
int green=5;// pin green LED is connected to (PWM pin)
int red=6; // pin red LED is connected to (PWM pin)
Servo myservo; //pin motor is connected to (PWM pin)

// Analog pins
int usadist=A0; // ultrasonic analog distance sensor output, "yeilds ~9.8mV/in"
int pot=A1;// potentiometer reading
int photo=A2;// pin of the photoresistor


void setup() {
  // put your setup code here, to run once:

pinMode(laser,OUTPUT); //set laser to output
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);
pinMode(blue,OUTPUT);
//pinMode(motor,OUTPUT);

pinMode(toggle,INPUT); //set switch to input

Serial.begin(9600); //begin serial communication, needed for printing to serial
//myservo.attach(9); //attaches servo to pin 9

}

void loop() {
  // put your main code here, to run repeatedly: 
  // Each one operates independantly, trying them with multiple together probably won't work.
  
  // Turn LASER on, wait 2 sec, turn it off
  /*
  digitalWrite(laser,HIGH);
  delay(2000);
  digitalWrite(laser,LOW);
  delay(2000);
  */
  
  
  //Operating the Servo
  
  //Make sure myservo is actually attached!
  //On a continuous rotation servo, servo.write will set the speed of the servo 
  //(with 0 being full-speed in one direction, 180 being full speed in the other, 
  //and a value near 90being no movement [NOT 90, in most cases])
  /*
  int rate= 50;//how fast and in what direction it should turn
  myservo.write(rate);
  */

  
  //Read the Sonar, convert the distance
  /*
  int sonout=analogRead(usadist); //read the Sonar Distance "yeilds ~9.8mV/in"
  //float realdist=(sonout/1023)*5000/9.8; // [number/max]*5000 mV/9.8 mv/in
   float realdist=(sonout*.4987); //Same thing as above, just shortens it
  Serial.print("sonout: ");
  Serial.print(sonout);
  Serial.print(" ");
 Serial.print( "Real: " );
 Serial.println( realdist); //Displays both sonout and real 
  delay(100);
  */
  
  
  // Read the photoresistor and print to serial
  /*
  int photoread=analogRead(photo); //capture data from photoresistor
  Serial.println(photoread); //print to serial monitor
  delay(50); // make it less crazy output
  */
  
  
  
  // Cycle the colors of the LED
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
  
  
  
  
  
  
}
