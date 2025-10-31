#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 6     
#define relay_fan 13

#define DHTTYPE DHT11 

DHT dht(DHTPIN, DHTTYPE);

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte propeller_frame0[] = {
  B00000,
  B01110,
  B10101,
  B11111,
  B10101,
  B01110,
  B00000,
  B00000
};

byte propeller_frame1[] = {
  B00000,
  B01110,
  B11011,
  B10101,
  B11011,
  B01110,
  B00000,
  B00000
};



void setup() {
  
  pinMode(relay_fan, OUTPUT);
  digitalWrite(relay_fan, LOW);

  Serial.begin(9600); 
  dht.begin();
  lcd.begin(16, 2);

  lcd.setCursor(4, 0);
  lcd.print("ITVerse");
  lcd.setCursor(2,1);
  lcd.print("Temp Control");
  delay(2000);
  lcd.clear();
  
  lcd.createChar(0, propeller_frame0);
  lcd.createChar(1, propeller_frame1);
  
}

void loop() {
  delay(100);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("!!No Sensor!!");
    Serial.println("Failed to read from DHT sensor!");
    return;
  }


  if(t>=34.0){
    digitalWrite(relay_fan, HIGH);

    lcd.setCursor(15, 0);
    lcd.write(byte(0));              //propeller frame 0
    delay(100);
    lcd.setCursor(15, 0);
    lcd.write(byte(1));              //propeller frame 1
    delay(100);
  }else{
    digitalWrite(relay_fan, LOW);
    lcd.clear();
  }

  lcd.setCursor(0,0);
  lcd.print("Temp : ");
  lcd.setCursor(7, 0);
  lcd.print(t);
  lcd.print((char)223);             // show degree symbol
  lcd.print("C");
  
  lcd.setCursor(0,1);
  lcd.print("Humi : ");
  lcd.setCursor(7, 1);
  lcd.print(h);
  lcd.print(" %");
}
