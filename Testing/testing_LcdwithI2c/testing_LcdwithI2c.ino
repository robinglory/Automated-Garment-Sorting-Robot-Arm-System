// Scanning...
// I2C device found at address 0x27 !
// done

// #include <Wire.h>

// void setup() {
//   Wire.begin(); 
//   Serial.begin(9600); 
//   while (!Serial); // wait for serial monitor 
//   Serial.println("\nI2C Scanner"); 
// }

// void loop() {
//   byte error, address; 
//   int nDevices; 
//   Serial.println("Scanning..."); 
//   nDevices = 0; 
//   for(address = 1; address < 127; address++ ) { 
//     // The i2c_scanner uses the return value of 
//     // the Write.endTransmisstion to see if 
//     // a device did acknowledge to the address. 
//     Wire.beginTransmission(address); 
//     error = Wire.endTransmission(); 
//     if (error == 0) { 
//       Serial.print("I2C device found at address 0x"); 
//       if (address<16) 
//         Serial.print("0"); 
//       Serial.print(address,HEX); 
//       Serial.println(" !"); 
//       nDevices++; 
//     } 
//     else if (error==4) { 
//       Serial.print("Unknown error at address 0x"); 
//       if (address<16) 
//         Serial.print("0"); 
//       Serial.println(address,HEX); 
//     } 
//   } 
//   if (nDevices == 0) 
//     Serial.println("No I2C devices found\n"); 
//   else 
//     Serial.println("done\n"); 
//   delay(5000); // wait 5 seconds for next scan 
// }


// 

#include <LiquidCrystal_I2C.h>

// Pin definitions for color sensor
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

// Variables to store color frequencies
int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;

// Initialize LCD with I2C address 0x27, 16 columns, and 2 rows
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  // Initialize LCD
  lcd.init();

  // Set up pins for color sensor
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Set initial state for color sensor pins
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
}

void loop() {
  // Display color on LCD and check color using color sensor
  displayColor();
  checkColor();
}

void displayColor() {
  // Set LCD cursor to column 0, row 0
  lcd.setCursor(0, 0);
  // Print message on LCD
  lcd.print(" Color Detected ");
}

void checkColor() {
  // Get frequencies of red, green, and blue from color sensor
  getFrequency();

  // Clear previous serial data
  Serial.println();

  // Check color based on frequencies and display on LCD
  if ((frequencyRed < 100 && frequencyRed > 60) && (frequencyGreen < 200 && frequencyGreen > 170)) {
    Serial.println("RED object");
    lcd.setCursor(0, 1);
    lcd.print(" RED Color ");
  } else if ((frequencyGreen < 70 && frequencyGreen > 50)) {
    Serial.println("Green Object!");
    lcd.setCursor(0, 1);
    lcd.print(" Green Color ");
  } else if ((frequencyBlue < 55 && frequencyBlue > 35)) {
    Serial.println("Blue Object");
    lcd.setCursor(0, 1);
    lcd.print(" Blue Color ");
  } else {
    // If color cannot be identified
    Serial.println("Can't Identify");
    lcd.setCursor(0, 1);
    lcd.print(" Can't Identify");
  }

  // Delay for visibility
  delay(500);
}

void getFrequency() {
  // Select red filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  // Measure red frequency
  frequencyRed = pulseIn(sensorOut, LOW);
  Serial.print("Red = ");
  Serial.print(frequencyRed);
  Serial.print("  ");
  delay(100);

  // Select green filter
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  // Measure green frequency
  frequencyGreen = pulseIn(sensorOut, LOW);
  Serial.print("Green= ");
  Serial.print(frequencyGreen);
  Serial.print("  ");
  delay(100);

  // Select blue filter
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  // Measure blue frequency
  frequencyBlue = pulseIn(sensorOut, LOW);
  Serial.print("Blue= ");
  Serial.print(frequencyBlue);
  Serial.println("  ");
  delay(100);
}

