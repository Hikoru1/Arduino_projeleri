#include <Servo.h>

Servo servo;

void setup () {
  servo.attach(7);
}

void loop() {
  for (int i = 0; i < 180; i++) {
    servo.write(i);
    delay(20);
  }
  for (int i = 180; i > 0; i--) {
    servo.write(i);
    delay(20);
  }
}
