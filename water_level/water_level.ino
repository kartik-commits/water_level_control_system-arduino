#include <ShiftedLCD.h>
#include <SPI.h>

// initialize the ShiftedLCD library with the number of the latch pin
LiquidCrystal lcd(10);

const int relay_1 = A5;    // O/P
const int relay_2 = A4;    // O/P
const int START = 2;       // I/P
const int STOP = 3;        // I/P
const int ENTER = 4;       // I/P
const int floaty_1 = 7;    // I/P
const int floaty_2 = 6;    // I/P
const int floaty_3 = 8;    // I/P

const int led_1 = A0;      // O/P
const int led_2 = 9;       // O/P
const int led_3 = 5;       // O/P

void setup() {
  lcd.begin(16, 2); // Initialize the ShiftedLCD
  lcd.noBlink();
  pinMode(relay_1, OUTPUT);
  pinMode(relay_2, OUTPUT);
  pinMode(floaty_1, INPUT);
  pinMode(floaty_2, INPUT);
  pinMode(floaty_3, INPUT);
  pinMode(START, INPUT);
  pinMode(STOP, INPUT);
  pinMode(ENTER, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  digitalWrite(relay_1, LOW);
  digitalWrite(relay_2, LOW);
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
}

void loop() {
  if(digitalRead(floaty_3) == HIGH) {
      if((digitalRead(floaty_1) == LOW) && (digitalRead(floaty_2) == HIGH)) {
        digitalWrite(relay_1, HIGH);
        digitalWrite(led_1, HIGH);
        digitalWrite(led_2, LOW);
        digitalWrite(led_3, HIGH); 
        lcd.setCursor(0, 0);
        lcd.print("    PUMP ON     ");
        delay(300);
      }
      else if(digitalRead(floaty_2) == LOW) {
        digitalWrite(relay_1, LOW);
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
        digitalWrite(relay_1, LOW);
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
    else if(digitalRead(floaty_3) == LOW) {
      lcd.setCursor(0, 0);
      lcd.print("    MANUAL MODE    ");
      //TODO
    
  }

}
