// Define the pins for motor control
#define IN1 2  // Input pin 1 for Motor A
#define IN2 3  // Input pin 2 for Motor A
#define IR_SENSOR_1 12 // Pin for IR sensor 1
#define IR_SENSOR_2 11 // Pin for IR sensor 2

bool objectDetected = false;

void setup() {
  // Set motor control pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  // Set IR sensor pins as input
  pinMode(IR_SENSOR_1, INPUT);
  pinMode(IR_SENSOR_2, INPUT);

  // Initially, stop the motor
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  // Check if IR sensor 1 detects an obstacle
  if (digitalRead(IR_SENSOR_1) == LOW && !objectDetected) {
    startMotor(); 
    objectDetected = true;
  }

  // Check if IR sensor 2 detects an obstacle
  if (digitalRead(IR_SENSOR_2) == LOW && objectDetected) {
    stopMotor();
    objectDetected = false;
  }
}

void startMotor() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void stopMotor() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
