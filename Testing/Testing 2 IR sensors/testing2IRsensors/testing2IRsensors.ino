// Define the pins for the sensors
const int sensorPin1 = 3;
const int sensorPin2 = 4;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set the sensor pins as input
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
}

void loop() {
  // Read the sensor values
  int sensorValue1 = digitalRead(sensorPin1);
  int sensorValue2 = digitalRead(sensorPin2);
  
  // Print the sensor values to the serial monitor
  Serial.print("Sensor 1: ");
  Serial.print(sensorValue1);
  Serial.print("   Sensor 2: ");
  Serial.println(sensorValue2);
  
  // Add a small delay to prevent flooding the serial monitor
  delay(1000);
}
