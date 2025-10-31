const int ANALOG_IN_PIN = A0;

void setup() {
 
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(ANALOG_IN_PIN);
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("Pot_Value = ");
  Serial.print(sensorValue);
  Serial.print(",");
  Serial.print("Voltage = ");
  Serial.println(voltage);
  delay(100);
}
