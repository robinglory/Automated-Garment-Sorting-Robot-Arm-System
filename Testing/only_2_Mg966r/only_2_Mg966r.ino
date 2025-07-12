#include <Servo.h>

// Define servo object
Servo servo1;

void setup() {
  // Attach servo to pin 2
  servo1.attach(3);

  // Set initial position to 0 degrees
  servo1.write(0);

}

void loop() {
  // Sweep servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servo1.write(angle);
    delay(15); // Adjust delay if needed for smoother motion
  }
  
  // Sweep servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servo1.write(angle);
    delay(15); // Adjust delay if needed for smoother motion
  }
}
