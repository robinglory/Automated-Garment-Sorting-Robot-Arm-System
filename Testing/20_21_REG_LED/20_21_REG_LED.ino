// Define the pins
int lightPin = A0; // Pin connected to the photo resistor
int buzzPin = 8;   // Pin connected to the buzzer

void setup() {
  // Set the pin modes
  pinMode(lightPin, INPUT); // Set the photo resistor pin as input
  pinMode(buzzPin, OUTPUT); // Set the buzzer pin as output

  // Begin serial communication (for debugging)
  Serial.begin(9600);
}

void loop() {
  // Read the value from the photo resistor
  int lightVal = analogRead(lightPin);

  // Calculate the delay time based on the light value
  float delayTime = (9.0 / 550.0) * lightVal - (9.0 * 200.0 / 550.0) + 1.0;

  // Print the delay time (for debugging)
  Serial.println(delayTime);
  Serial.println(lightVal);


  // Produce the audible tone with the buzzer
  digitalWrite(buzzPin, HIGH);  // Turn the buzzer on
  delay(delayTime);             // Wait for the specified delay time
  digitalWrite(buzzPin, LOW);   // Turn the buzzer off
  delay(delayTime);             // Wait for the same delay time
}
