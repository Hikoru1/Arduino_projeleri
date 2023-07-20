#include <LiquidCrystal.h>
#include<Servo.h>

#define B1 8
#define B2 9
#define SERVO 6

int pos = 100;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Servo servo;
void setup() {
  lcd.begin(16, 2);
  pinMode(B1, INPUT);
  pinMode(B2, INPUT);
  lcd.setCursor(0, 0);
  lcd.print("Position: ");
  servo.attach(SERVO);
}
void loop() {
  lcd.setCursor(9, 0);
  lcd.print(pos, DEC);

  if (digitalRead(B1) == true) {
    pos++;
    delay(25);
    if (pos > 180) {
      pos = 180;
    }
  }
  else if (digitalRead(B2) == true) {
    pos--;
    delay(25);
    if (pos < 100) {
      lcd.setCursor(11, 0);
      lcd.print(" ");

    }
    if (pos < 0) {
      pos = 0;
    }
    if (pos < 10) {
      lcd.setCursor(10, 0);
      lcd.print(" ");

    }
  }
  servo.write(pos);
}
