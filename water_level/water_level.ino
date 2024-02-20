#include <ShiftedLCD.h>
#include <SPI.h>

// initialize the ShiftedLCD library with the number of the latch pin
LiquidCrystal lcd(10);

const int relay = 0;
const int floaty_1 = A4;
const int floaty_2 = A3;
const int led_1 = 6;
const int led_2 = 7;
const int led_3 = 4;

void setup() {
  lcd.begin(16, 2); // Initialize the ShiftedLCD
  lcd.noBlink();
  pinMode(relay, OUTPUT);
  pinMode(floaty_1, INPUT);
  pinMode(floaty_2, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  digitalWrite(relay, LOW);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
}

void loop() {
  if((digitalRead(floaty_1) == LOW) && (digitalRead(floaty_2) == HIGH)) {
    digitalWrite(relay, HIGH);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, HIGH); 
    lcd.setCursor(0, 0);
    lcd.print("    PUMP ON     ");
    delay(300);
  }
  else if(digitalRead(floaty_2) == LOW) {
    digitalWrite(relay, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_2, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("LOWER TANK EMPTY");
    lcd.clear();
    delay(300);
    digitalWrite(led_3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("LOWER TANK EMPTY");
    delay(300);
  }
  else if(digitalRead(floaty_1) == HIGH) {
    digitalWrite(relay, LOW);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    lcd.setCursor(0, 0);
    lcd.print("    TANK FULL   ");
    lcd.clear();
    delay(300);
    lcd.setCursor(0, 0);
    lcd.print("    TANK FULL   ");
    digitalWrite(led_1, LOW);
    delay(300);
  }
}

