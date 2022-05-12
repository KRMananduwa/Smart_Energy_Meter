#include "ACS712.h"
#include <SoftwareSerial.h>
#include <Filters.h>                      //This library can check by it's .cpp file

#include <LiquidCrystal_I2C.h>    //LCD ic library
#define I2C_ADDR 0x27 //I2C adress
#define BACKLIGHT_PIN 3 // Declaring LCD Pins
#define En_pin 2
#define Rw_pin 1
#define Rs_pin 0
#define D4_pin 4
#define D5_pin 5
#define D6_pin 6
#define D7_pin 7

LiquidCrystal_I2C lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin); //Declaring the lcd

#define ACS_Pin A1                        //Sensor data pin on A1 analog input
ACS712 sensor(ACS712_30A, A1);            // We have 30 amps version sensor connected to A1 pin of arduino
SoftwareSerial espSerial(5, 6);

String str;
unsigned long last_time =0;
unsigned long current_time =0;
float Wh =0 ;
float kWh =0;
char watt[5]; //Make an array to store power

float ACS_Value;                              //Here we keep the raw data valuess
float testFrequency = 50;                    // test signal frequency (Hz)
float windowLength = 40.0/testFrequency;     // how long to average the signal, for statistist

float intercept = 0; // to be adjusted based on calibration testing
float slope = 0.0752; // to be adjusted based on calibration testing

float Amps_TRMS; // estimated actual current in amps
float P; //Power

unsigned long printPeriod = 1000; // in milliseconds
// Track time in milliseconds since last reading 
unsigned long previousMillis = 0;

void setup() {
  Serial.begin( 115200 );    // Start the serial port
  espSerial.begin(115200);
  sensor.calibrate();
  pinMode(ACS_Pin,INPUT);  //Define the pin mode

  digitalWrite(2,HIGH);
  lcd.begin (16,2);
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH); //Lighting backlight
  lcd.home ();
}

void loop() {
  RunningStatistics inputStats;                 // create statistics to look at the raw test signal
  inputStats.setWindowSecs( windowLength );     //Set the window length
   
  while( true ) {
  float U = 230;
  float I = sensor.getCurrentAC();
  
  if(I<0.1){
    float P = 0;
  }else{
    float P = U * I;

     //convert power into Wh.
    last_time = current_time;
    current_time = millis();    
    Wh = Wh+  P *(( current_time -last_time) /3600000.0) ;
    kWh = kWh+  ((P *(( current_time -last_time)/1000.0))/3600000.0); 
  }

    
    ACS_Value = analogRead(ACS_Pin);  // read the analog in value:
    inputStats.input(ACS_Value);  // log to Stats function
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) { //every second we do the calculation
      previousMillis = millis();   // update time
      
      Amps_TRMS = intercept + slope * inputStats.sigma(); //Calibrate the values

      lcd.clear();               //clear the lcd and print in a certain position
      lcd.setCursor(1,0);
      lcd.print(Amps_TRMS);
      lcd.print(" A");

      lcd.setCursor(8,0);
      lcd.print(Wh);
      lcd.print(" Wh");

      lcd.setCursor(0,1);
      lcd.print("Usage:  ");
      lcd.print(kWh);
      lcd.print(" kWh");

      Serial.println(String("P = ") + P + " Watts"+ "\t Amps: "+ Amps_TRMS);
      str =String("coming from arduino: ")+String("Consumption: ")+String(kWh)+String("kWh")+String("\t")+String("P= ")+String(P)+String("\t")+String("Amps= ")+String(Amps_TRMS);
      espSerial.println(str); 
      /*
      Serial.print( "\t Amps: " ); 
      Serial.print( Amps_TRMS );
      */

    }
  }
}
