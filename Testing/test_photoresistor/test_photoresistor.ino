// Define pin numbers for components
const int lightPin = A0;  // Analog pin for reading light sensor
const int redPin = 9;     // Digital pin for controlling red LED
const int greenPin = 8;   // Digital pin for controlling green LED

void setup() {
  pinMode(lightPin, INPUT);  // Set light sensor pin as input
  pinMode(redPin, OUTPUT);   // Set red LED pin as output
  pinMode(greenPin, OUTPUT); // Set green LED pin as output
  
  Serial.begin(9600);  // Initialize serial communication
}

void loop() {
  int lightVal = analogRead(lightPin);  // Read analog value from light sensor
  Serial.println(lightVal);             // Print light sensor value to serial monitor
  
  // Determine LED states based on light sensor value
  if (lightVal > 350) {
    digitalWrite(greenPin, HIGH);  // Turn on green LED
    digitalWrite(redPin, LOW);     // Turn off red LED
  } else {
    digitalWrite(greenPin, LOW);   // Turn off green LED
    digitalWrite(redPin, HIGH);    // Turn on red LED
  }
  
  delay(250);  // Delay for stability
}
