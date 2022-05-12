#include "ACS712.h"
#include <Filters.h>                      //This library can check by it's .cpp file

#define ACS_Pin A1                        //Sensor data pin on A1 analog input
ACS712 sensor(ACS712_30A, A1);            // We have 30 amps version sensor connected to A1 pin of arduino

float ACS_Value;                              //Here we keep the raw data valuess
float testFrequency = 50;                    // test signal frequency (Hz)
float windowLength = 40.0/testFrequency;     // how long to average the signal, for statistist

float intercept = 0; // to be adjusted based on calibration testing
float slope = 0.0752; // to be adjusted based on calibration testing

float Amps_TRMS; // estimated actual current in amps

unsigned long printPeriod = 1000; // in milliseconds
// Track time in milliseconds since last reading 
unsigned long previousMillis = 0;

void setup() {
  Serial.begin( 115200 );    // Start the serial port
  sensor.calibrate();
  pinMode(ACS_Pin,INPUT);  //Define the pin mode
}

void loop() {
  RunningStatistics inputStats;                 // create statistics to look at the raw test signal
  inputStats.setWindowSecs( windowLength );     //Set the window length
   
  while( true ) {
  float U = 230;
  float I = sensor.getCurrentAC();
  float P = U * I;  
  
    ACS_Value = analogRead(ACS_Pin);  // read the analog in value:
    inputStats.input(ACS_Value);  // log to Stats function
        
    if((unsigned long)(millis() - previousMillis) >= printPeriod) { //every second we do the calculation
      previousMillis = millis();   // update time
      
      Amps_TRMS = intercept + slope * inputStats.sigma();

      Serial.println(String("P = ") + P + " Watts"+ "\t Amps: "+ Amps_TRMS); 
      /*
      Serial.print( "\t Amps: " ); 
      Serial.print( Amps_TRMS );
      */

    }
  }
}
