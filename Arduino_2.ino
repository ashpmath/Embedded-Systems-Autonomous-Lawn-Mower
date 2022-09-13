#include <AFMotor.h> //by Adafruit
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

//4 DC motors
AF_DCMotor m1(1);
AF_DCMotor m2(2);
AF_DCMotor m3(3);
AF_DCMotor m4(4);
char RX[4];
int passes = 0;
const int pingPin = 7;         // Trigger
const int echoPin = 6;         // Echo

//DEFINE MEASUREMENTS
long duration, inches, cm;

//CREATE A TINYGPSPLUS OBJECT
TinyGPSPlus gps;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //baud rate
  Serial.print("Motor Test");

  //Setup speed for the four dc motors
  m1.setSpeed(200);
  m2.setSpeed(200);
  m3.setSpeed(200);
  m4.setSpeed(200); 

  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE); 
}

void loop() {
  // put your main code here, to run repeatedly:

  
  while(1){
    
    //ULTRA SONIC SENSOR
      pinMode(pingPin, OUTPUT);
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(10);
      
      digitalWrite(pingPin, LOW);
      pinMode(echoPin, INPUT);
      
      duration = pulseIn(echoPin, HIGH);
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);

      //lcd.clear();
      //lcd.setCursor(0,0);
      //lcd.
      Serial.print(inches);
      Serial.print("in, ");
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
      delay(100);

    if(Serial.available() > 0){  

      passes = Serial.read();
  
      switch (passes){
        case 1:
          passes = 1;
          startMotors(passes);
        case 2:
          passes = 2;
          startMotors(passes);
        case 3:
          passes = 3;
          startMotors(passes);
        default:
          break;
      }
    }
  }
}
void startMotors(int passNum){
  uint8_t i; //basically this means its an unsigned integer of 8. Same thing as using byte
  
  //PASSNUM IS 1
  if(passNum == 1){
      m1.run(FORWARD);
      for(i = 0; i < 255; i++){
          m1.setSpeed(i); //set speed to i
          delay(10);
      }
      for(i = 255; i != 0; i--){
          m1.setSpeed(i); //set speed to i
          delay(10);
          }    
      m2.run(FORWARD);
      for(i = 0; i < 255; i++){
          m2.setSpeed(i); //set speed to i
          delay(10);
      }
      for(i = 255; i != 0; i--){
          m2.setSpeed(i); //set speed to i
         delay(10);
      }
      m3.run(FORWARD);
      for(i = 0; i < 255; i++){
          m3.setSpeed(i); //set speed to i
        delay(10);
      }
      for(i = 255; i != 0; i--){
          m3.setSpeed(i); //set speed to i
          delay(10);
      }
      m4.run(FORWARD);
      for(i = 0; i < 255; i++){
         m4.setSpeed(i); //set speed to i
         delay(10);
      }
      for(i = 255; i != 0; i--){
        m4.setSpeed(i); //set speed to i
        delay(10);
      }
  }else if(passNum == 2){
      m1.run(FORWARD);
      for(i = 0; i < 255; i++){
          m1.setSpeed(i); //set speed to i
          delay(10);
      }
      for(i = 255; i != 0; i--){
          m1.setSpeed(i); //set speed to i
          delay(10);
          }
      m2.run(FORWARD);
      for(i = 0; i < 255; i++){
          m2.setSpeed(i); //set speed to i
          delay(10);
      }
      for(i = 255; i != 0; i--){
          m2.setSpeed(i); //set speed to i
         delay(10);
      }
      m3.run(FORWARD);
      for(i = 0; i < 255; i++){
          m3.setSpeed(i); //set speed to i
        delay(10);
      }
      for(i = 255; i != 0; i--){
          m3.setSpeed(i); //set speed to i
          delay(10);
      }
      m4.run(FORWARD);
      for(i = 0; i < 255; i++){
         m4.setSpeed(i); //set speed to i
         delay(10);
      }
      for(i = 255; i != 0; i--){
        m4.setSpeed(i); //set speed to i
        delay(10);
      }
  }else if(passNum == 3){
      m1.run(FORWARD);
      for(i = 0; i < 255; i++){
          m1.setSpeed(i); //set speed to i
          delay(10);
      }
      for(i = 255; i != 0; i--){
          m1.setSpeed(i); //set speed to i
          delay(10);
          }
      m2.run(FORWARD);
      for(i = 0; i < 255; i++){
          m2.setSpeed(i); //set speed to i
          delay(10);
      }
      for(i = 255; i != 0; i--){
          m2.setSpeed(i); //set speed to i
         delay(10);
      }
      m3.run(FORWARD);
      for(i = 0; i < 255; i++){
          m3.setSpeed(i); //set speed to i
        delay(10);
      }
      for(i = 255; i != 0; i--){
          m3.setSpeed(i); //set speed to i
          delay(10);
      }
      m4.run(FORWARD);
      for(i = 0; i < 255; i++){
         m4.setSpeed(i); //set speed to i
         delay(10);
      }
      for(i = 255; i != 0; i--){
        m4.setSpeed(i); //set speed to i
        delay(10);
      }
  }else{
    
  }
  //Test Complete
  Serial.print("DONE");
  m1.run(RELEASE);
  m2.run(RELEASE);
  m3.run(RELEASE);
  m4.run(RELEASE);
  delay(10);
}
  //displayInfo();
void noSignal(){
  if(millis()> 5000 && gps.charsProcessed() < 10){
    Serial.print("No GPS Found");
  }
}
long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
