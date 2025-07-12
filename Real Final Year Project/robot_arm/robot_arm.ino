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
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

}

void loop() {
  Serial.println("The operation of the Garment System is started now!!");
  // Read color sensor values
  getFrequency();
  lcd.clear(); // Clear the LCD screen
  // Check the detected color and trigger the corresponding action
  if ((frequencyRed < 120 && frequencyRed > 65)) {
    lcd.setCursor(3, 1); // Set cursor position for the title
    lcd.print("Detected color:");
    Serial.println("Detected Color: Red Garment");
    lcd.setCursor(1, 2); // Set cursor position for the color description
    lcd.print("Red Garment Object");
    doRedSequence();
    delay(2000);
    initialPosition();
  } else if ((frequencyGreen < 175 && frequencyGreen > 130)) {
    lcd.setCursor(3, 1); // Set cursor position for the title
    lcd.print("Detected color:");
    Serial.println("Detected Color: Green Garment");
    lcd.setCursor(0, 2); // Set cursor position for the color description
    lcd.print("Green Garment Object");
    doGreenSequence();
    delay(2000);
    initialPosition();
  } else if ((frequencyBlue < 150 && frequencyBlue > 120)) {
    lcd.setCursor(3, 1); // Set cursor position for the title
    lcd.print("Detected color:");
    Serial.println("Detected Color: Blue Garment");
    lcd.setCursor(1, 2); // Set cursor position for the color description
    lcd.print("Blue Garment Object");
    doBlueSequence();
    delay(2000);
    initialPosition();
  } else {
    lcd.setCursor(3, 1); // Set cursor position for the title
    lcd.print("Detected color:");
    Serial.println("Detected Color: Unknown");
    lcd.setCursor(6, 2); // Set cursor position for the unknown color description
    lcd.print("Unknown");
    initialPosition();
  }

  // Display color on LCD
  // displayColor();
}

void initialPosition() {
  // Move all servos to their initial positions
  moveServo(0, 0);    // Servo 1
  delay(500); // wait for a second
  moveServo(1, 100);   // Servo 2
  delay(500);
  moveServo(4, 10);   // Servo 3
  delay(500);
  moveServo(8, 190);  // Servo 4
  moveServo(12, -10);   // Servo 5
  delay(2000);
  Serial.println("Servos moved to initial positions.");
}

void doRedSequence() {
  // Red sequence
  moveServo(0, -5);   // Servo 1
  delay(500); // wait for a second
  moveServo(1, 40);   // Servo 2
  delay(500);
  moveServo(4, 30);
  moveServo(4, 45);
  moveServo(4, 55);   // Servo 3
  delay(500);
  moveServo(8, 161.5); // Servo 4
  moveServo(12, 19.5); // Servo 5
  delay(500);

  // To the Red box
  moveServo(1, 80);   // Servo 2
  delay(500);
  moveServo(4, 30);
  delay(500);
  moveServo(0, 50);  // Servo 1
  delay(500);
  moveServo(1, 50);
  delay(500);
  moveServo(4, 55);
  delay(500);
  moveServo(8, 180);  // Servo 4
  moveServo(12, 0);   // Servo 5
  delay(500);
  moveServo(1, 80);   // Servo 2
  delay(500);
  moveServo(4, 30);
  delay(500);

  Serial.println("Red sequence completed.");
}

void doGreenSequence() {
  // Green sequence
  moveServo(0, -5);   // Servo 1
  delay(500); // wait for a second
  moveServo(1, 40);   // Servo 2
  delay(500);
  moveServo(4, 30);
  moveServo(4, 45);
  moveServo(4, 55);   // Servo 3
  delay(500);
  moveServo(8, 161.5); // Servo 4
  moveServo(12, 19.5); // Servo 5
  delay(500);

  // To the Green box
  moveServo(1, 80);   // Servo 2
  delay(500);
  moveServo(4, 30);
  delay(500);
  moveServo(0, 130);  // Servo 1
  delay(500);
  moveServo(1, 50);
  delay(500);
  moveServo(4, 55);
  delay(500);
  moveServo(8, 180);  // Servo 4
  moveServo(12, 0);   // Servo 5
  delay(500);
  moveServo(1, 80);   // Servo 2
  delay(500);
  moveServo(4, 30);
  delay(500);

  Serial.println("Green sequence completed.");
}

void doBlueSequence() {
  // Blue sequence
  moveServo(0, -5);   // Servo 1
  delay(500); // wait for a second
  moveServo(1, 40);   // Servo 2
  delay(500);
  moveServo(4, 30);
  moveServo(4, 45);
  moveServo(4, 55);   // Servo 3
  delay(500);
  moveServo(8, 161.5); // Servo 4
  moveServo(12, 19.5); // Servo 5
  delay(500);

  // To the Blue box
  moveServo(1, 80);   // Servo 2
  delay(500);
  moveServo(4, 30);
  delay(500);
  moveServo(0, 180);  // Servo 1
  delay(500);
  moveServo(1, 50);
  delay(500);
  moveServo(4, 55);
  delay(500);
  moveServo(8, 190);  // Servo 4
  moveServo(12, 0);   // Servo 5
  delay(500);
  moveServo(1, 80);   // Servo 2
  delay(500);
  moveServo(4, 30);
  delay(500);

  Serial.println("Blue sequence completed.");
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
  Serial.println("Red Frequency is " + String(frequencyRed));
  delay(100);

  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequencyGreen = pulseIn(sensorOut, LOW);
  Serial.println("Green Frequency is " + String(frequencyGreen));
  delay(100);

  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequencyBlue = pulseIn(sensorOut, LOW);
  Serial.println("Blue Frequency is " + String(frequencyBlue));
  delay(100);
}
