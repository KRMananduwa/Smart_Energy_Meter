/*This code works with ACS712 Current sensor, it permits to read the raw data
  It's better to use it with Serial Plotter
  More details on www.surtrtech.com
*/

#define Current_sensor A0  //The sensor analog input pin

float i;
float x;


void setup() {

Serial.begin(9600);
pinMode(Current_sensor, INPUT);

}

void loop() {
  i = analogRead(Current_sensor);
  Serial.println(i);
  delay(500);                     //Modifying or removing the delay will change the way the signal is shown 
                                  //set it until you get the correct sinewave shap

}
