void setup() {
  Serial.begin( 9600 );
}

void loop() {
  int sensorValue = analogRead(A0);
  float Amp = 0.05859*sensorValue-29.998;
  Serial.println(Amp);
  delay(500);
}
