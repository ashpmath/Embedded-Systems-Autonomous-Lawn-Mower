#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
 
static const int TXPin = 3;
static const int RXPin = 4;
SoftwareSerial ss(RXPin, TXPin);
char TX[8];
//static const int UARTPin0 = RX;
//static const int UARTPin1 = TX;
static const uint32_t GPSBaudRate = 9600;
LiquidCrystal_I2C lcd(0x27, 16, 2);
TinyGPSPlus myGPSModule;

const int pingPin = 7;         // Trigger
const int echoPin = 6;         // Echo

//Button Pins
const int buttonPin = 12;
int counter = 0;    // counter for the number of button presses
int state = 0;       // current state of the up button
int previousState = 0;   // previous state of the up button
bool buttonPressed = false;
int passes = 0;


void setup() {
  Serial.begin(115200);
  ss.begin(GPSBaudRate);

  // Two Pushbuttons
  pinMode(13, INPUT); //button used for user to get # of passes
  pinMode(12, INPUT); //button used for user to press enter and proceed further
  pinMode(buttonPin, INPUT);

  // UART/RS232 Communication between Arduinos
  pinMode(11, OUTPUT);  
  pinMode(10, OUTPUT);
}

void loop() {
  //INITIALIZE LCD USING I2C
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Num of Passes:");
  
  numOfPasses(passes);
  delay(2000);

  //Send #of passes to second arduino
  //sendSignalUART(passes);
  delay(7000); //wait 7 seconds
  Serial.begin(115200);

  //GPS - SETUP
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Receiving GPS"); 

  lcd.setCursor(5, 1);
  lcd.print("Signal...");
  delay(3000);
  lcd.clear(); 
    
  while(1){
    //Sends signal to second arduino.
    //Second Arduino will then receive the #of passes and start motors
    beginUART(passes);

  //GPS SIGNAL
  while (ss.available() > 0){
      if(myGPSModule.encode(ss.read())){
        Serial.write(ss.read());
     
    // print info to LCD
    lcd.setCursor(0, 0);
    lcd.print("LAT ");
    lcd.print(myGPSModule.location.lat(), 7);

    lcd.setCursor(0, 1);
    lcd.print("LON ");
    lcd.print(myGPSModule.location.lng(), 7);  
      }
    }
  }  
}

int numOfPasses(int passesVal){
 state = digitalRead(buttonPin);
 while(buttonPressed){
    if(state == 1){
      passesVal++;
      delay(100);
    }else if(state == 0){
      state = 0;
    }
 }
 lcd.setCursor(3, 1);
 lcd.print(passesVal);
 return passesVal;
}

int beginUART(int passesVal){
   TX[8] = passesVal;
   Serial.print(passesVal);
 
  if(Serial.available() > 0)
  {
    //equiv to wire.read but we are sending byte iifo
    //Serial.readBytes(RX, 7);
    Serial.write(TX, 7); //since [8] we send 7
    Serial.flush();
  }
  //softSerial.write(temperature);  //writes
  Serial.println(passesVal);  //Prints to console
  return passesVal;
}
