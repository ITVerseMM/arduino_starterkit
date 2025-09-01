// ITVerse Myanmar

// https://itversemm.com

// https://github.com/ITVerseMM/arduino_starterkit

// LED blink Program


#define ledPin 8                  //led pin

void setup() {
  pinMode(ledPin,OUTPUT);         // set ledpin to output mode
  digitalWrite(ledPin,LOW);       // initially turn off the led
}

void loop() {
  digitalWrite(ledPin,HIGH);      // turn on the led == HIGH
  delay(500);                     // puse the program for 500 milliseconds 
  digitalWrite(ledPin,LOW);       // turn off the led == LOW
  delay(500);                     // puse the program for 500 milliseconds 
}
