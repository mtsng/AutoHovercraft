//import servo stuff
#include<Servo.h>
Servo thrust;
Servo myservo;
int pos = 0;
int cal1 = 0;
int cal2 = 180;

const int
//This initializes the fans and sensors
//Power
PWM_B = 11,
//Direction of the fan
DIR_B = 13,
//Stops the lift fan
BRAKE_B = 8,
//Left sensor
SNS_L = A4,
//Photosensor
SNS_S = A3;
//LED
int led = 13;

//More initial setup
void setup(){
  myservo.attach(5);
  pinMode(DIR_B, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  thrust.attach(6);
  thrust.write(cal1);
  delay(5000);
  thrust.write(cal2);
  delay(5000);
  thrust.write(cal1);
  delay(5000);
}

void loop(){
    //Left Sensor value
    int LeftsensorValue = analogRead(SNS_L);
    //Photocell
    int PhotosensorValue = analogRead(SNS_S);
    //LED
    digitalWrite(led, HIGH);
    
    //Serial.print(FrontsensorValue);
    Serial.print("     ");
    Serial.print(LeftsensorValue);
    Serial.print("     ");
    Serial.println(PhotosensorValue);
    
    //Sets the inital angle of servo
    //myservo.write(90);
    
    thrust.write(139);
    //while loop for photosensor
    //Sets fan power and direction
    analogWrite(PWM_B, 189);
    analogWrite(DIR_B, HIGH);
    //Right
    if(LeftsensorValue > 250){
      myservo.write(110);
    }
    //Left
    else if (LeftsensorValue < 195){
      myservo.write(65);
    }
    //Normal
    else{
      myservo.write(90);
    }
    if (PhotosensorValue < 700){
      analogWrite(PWM_B, 0);
      thrust.write(0);
      delay(5000);
    }
}
      
      
