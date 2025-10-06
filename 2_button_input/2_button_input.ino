int buzzer_pin = 7;
int button_pin = 6;
void setup() {
  pinMode(buzzer_pin, OUTPUT);
  pinMode(button_pin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int button_status = digitalRead(button_pin);

  Serial.print("Button Status : ");
  Serial.println(button_status);

  if(button_status==1){
    digitalWrite(buzzer_pin,HIGH);
  }else{
    digitalWrite(buzzer_pin,LOW);
  }

}
