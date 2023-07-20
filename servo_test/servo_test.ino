/*
 * Servo motor test uygulaması. 
 * 
 * Bağlantılar
 * Kırmızı    - 5V
 * Kahverengi - GND
 * Turuncu    - PIN 7
 */
#include <Servo.h>
#define SERVOPIN 7
#define DELAYTIME 20
Servo servo;

void setup () {
  servo.attach(SERVOPIN);
}

void loop() {
  for (int i = 0; i < 180; i++) {
    servo.write(i);
    delay(DELAYTIME);
  }
  for (int i = 180; i > 0; i--) {
    servo.write(i);
    delay(DELAYTIME);
  }
}
