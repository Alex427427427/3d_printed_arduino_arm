#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:
  servo.attach(8);

}

void loop() {
  // put your main code here, to run repeatedly:
  servo.write(90);
  /*
  for (int angle = 0; angle < 45; angle++) {
    servo.write(angle);
    delay(15);
  }
  for (int angle = 45; angle > 0; angle = angle - 1) {
    servo.write(angle);
    delay(15);
  }
  */

}
