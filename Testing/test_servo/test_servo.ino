#include <Servo.h>

Servo servo;

void setup() {
  // put your setup code here, to run once:

  servo.attach(8);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  // for(angle = 10; angle < 180; angle++)
  // {
  //   servo.write(angle);
  //   delay(15);
  // }

  // for(angle = 180; angle > 10; angle--){
  //   servo.write(angle);
  //   delay(15);
  // }
  servo.write(0);
  delay(1000);
  servo.write(90);
  delay(1000);
  servo.write(180);
  delay(1000);
}
