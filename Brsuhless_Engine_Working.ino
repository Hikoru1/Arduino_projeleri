#include <Servo.h>

Servo ESC;

void setup() {
  pinMode(A0, INPUT);

  Serial.begin(9600);
  
  ESC.attach(9,1000,2000);
}

void loop() {
  int potVal = analogRead(A0);
  int pwmVal = map(potVal, 0, 1023, 0, 180);
  Serial.println(pwmVal);
  ESC.write(pwmVal);
}
