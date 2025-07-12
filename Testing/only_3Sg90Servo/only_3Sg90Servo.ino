#include <Servo.h>
int servoPos = 0;
// Define servo objects
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup() {
  // Attach each servo to its respective pin
  servo1.attach(6);
  servo2.attach(7);
  servo3.attach(8);
  servo4.attach(9);
  servo5.attach(10);
}

void loop() {

  servo1.write(0);
    servo2.write(0);
      servo3.write(0);
        servo4.write(0);
          servo5.write(0);


  // Rotate all servos in the same direction
  for (servoPos = 0; servoPos <= 180; servoPos = servoPos + 25) {
    servo1.write(servoPos);
    servo2.write(servoPos);
    servo3.write(servoPos);
    servo4.write(servoPos);
    servo5.write(servoPos);
    delay(100); // Adjust delay if needed for smoother motion
  }

  // Wait at the end of the range
  delay(500);

  // Return all servos to the 0 position
  for (servoPos = 180; servoPos >= 0; servoPos--) {
    servo1.write(servoPos);
    servo2.write(servoPos);
    servo3.write(servoPos);
    servo4.write(servoPos);
    servo5.write(servoPos);
    delay(100); // Adjust delay if needed for smoother motion
  }

  // Wait at the end of the range
  delay(500);
}
