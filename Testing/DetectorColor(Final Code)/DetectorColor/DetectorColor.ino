Here's the merged code with the `checkColor()` function integrated into the original code:

```cpp
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal_I2C.h>

// Create the PWM servo driver object
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Replace 0x27 with the correct I2C address for your LCD
LiquidCrystal_I2C lcd(0x27, 20, 4);

// Define the min and max pulse lengths for the servo
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)

// Define pins for color sensor
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready to receive commands from Serial Monitor!");

  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  // Initialize the LCD
  lcd.begin(20, 4);
  lcd.backlight();

  // Initialize color sensor pins
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "red") {
      doRedSequence();
      delay(3000);
      initialPosition();
    } else if (command == "green") {
      doGreenSequence();
      delay(3000);
      initialPosition();
    } else if (command == "blue") {
      doBlueSequence();
      delay(3000);
      initialPosition();
    } else {
      Serial.println("Invalid command. Please enter 'red', 'green', or 'blue'.");
    }
  }

  // Read color sensor values
  getFrequency();

  // Display color on LCD
  displayColor();
}

void initialPosition() {
  // Move all servos to their initial positions
  moveServo(0, 0);
  delay(1000); // wait for a second
  moveServo(1, 80);
  delay(1000);
  moveServo(2, 60);
  delay(1000);
  moveServo(3, 180);
  moveServo(4, 0);
}

void doRedSequence() {
  // Red sequence
  moveServo(0, 50);
  delay(1000); // wait for a second
  moveServo(1, 49);
  delay(1000);
  moveServo(2, 79);
  delay(1000);
  moveServo(3, 161.5);
  moveServo(4, 19.5);
  delay(2000);

  moveServo(1, 80);
  delay(500);
  moveServo(0, 100);
  delay(1000);
  moveServo(3, 180);
  moveServo(4, 0);
  delay(1000);
}

void doGreenSequence() {
  // Green sequence
  moveServo(0, 50);
  delay(1000); // wait for a second
  moveServo(1, 49);
  delay(1000);
  moveServo(2, 79);
  delay(1000);
  moveServo(3, 161.5);
  moveServo(4, 19.5);
  delay(2000);

  moveServo(1, 80);
  delay(500);
  moveServo(0, 140);
  delay(1000);
  moveServo(3, 180);
  moveServo(4, 0);
  delay(1000);
}

void doBlueSequence() {
  // Blue sequence
  moveServo(0, 50);
  delay(1000); // wait for a second
  moveServo(1, 49);
  delay(1000);
  moveServo(2, 79);
  delay(1000);
  moveServo(3, 161.5);
  moveServo(4, 19.5);
  delay(2000);

  moveServo(1, 80);
  delay(500);
  moveServo(0, 180);
  delay(1000);
  moveServo(3, 180);
  moveServo(4, 0);
  delay(1000);
}

// Function to move servo to a specified angle
void moveServo(uint8_t servoNum, uint16_t angle) {
  // Convert angle to pulse length
  uint16_t pulseLen = map(angle, 0, 180, SERVOMIN, SERVOMAX);
  pwm.setPWM(servoNum, 0, pulseLen);
}

void getFrequency() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequencyRed = pulseIn(sensorOut, LOW);
  delay(100);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequencyGreen = pulseIn(sensorOut, LOW);
  delay(100);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequencyBlue = pulseIn(sensorOut, LOW);
  delay(100);
}

void displayColor() {
  lcd.clear(); // Clear the LCD screen

  // Determine the detected color based on frequency values
  if ((frequencyRed < 65 && frequencyRed > 0)) {
    lcd.setCursor(0, 0);
    lcd.print("Detected color: Red");
  } else if ((frequencyGreen < 110 && frequencyGreen > 50)) {
    lcd.setCursor(0, 0);
    lcd.print("Detected color: Green");
  } else if ((frequencyBlue < 175 && frequencyBlue > 100)) {
   