int sensorPin = A0; //ACS712 output pin connected to A0

void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorValue = analogRead(sensorPin);
  //float amp = sensorValue/34.133;
  Serial.println(sensorValue);
  delay(100);
}
