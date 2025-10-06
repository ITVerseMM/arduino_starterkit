// ITVerse Myanmar

// https://itversemm.com

// https://github.com/ITVerseMM/arduino_starterkit

// LED blink Program


int ledPin = 13                  //led pin

void setup() {
  pinMode(ledPin,OUTPUT);         // set ledpin to output mode
}

void loop() {
  digitalWrite(ledPin,HIGH);      // turn on the led == HIGH
  delay(1000);                     // puse the program for 500 milliseconds 
  digitalWrite(ledPin,LOW);       // turn off the led == LOW
  delay(1000);                     // puse the program for 500 milliseconds 
}
