const int POT_PIN = A0;  // Potentiometer input
const int LED_PIN = 9;   // LED output (must be a PWM pin)

void setup() {
  pinMode(LED_PIN, OUTPUT);   // Set the LED pin as an output
  Serial.begin(9600);
}

void loop() {
  int potValue = analogRead(POT_PIN);
  int outputValue = map(potValue, 0, 1023, 0, 255);  // 2. Map the input value to the PWM output range (0 to 255)                                                            
  
  analogWrite(LED_PIN, outputValue);                    // 3. Write the mapped value to the LED to change its brightness 

  Serial.print("Sensor = ");
  Serial.print(potValue);
  Serial.print("\t Output = ");
  Serial.println(outputValue);

  delay(20); // Small delay
}