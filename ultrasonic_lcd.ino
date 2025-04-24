#include <Wire.h>
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int trig = 9;
int echo = 10;
int duration;
float distances;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distances = (duration / 2.0) * 0.0343;

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:");


  lcd.setCursor(0, 1);
  lcd.print(distances);
  lcd.print(" cm");
 

  delay(1000);
}