#include <Servo.h>

int ledRed = A0;
int ledYellow = A1;
int ledBlue = A2;

#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8

int frequencyRed = 0;
int frequencyGreen = 0;
int frequencyBlue = 0;

void setup() {
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledBlue, OUTPUT);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.begin(9600);
}

void loop() {
  getFrequency();
  checkColor();
}

void getFrequency() {
  digitalWrite(S2, LOW);
  digitalWrite(S3, LOW);
  frequencyRed = pulseIn(sensorOut, LOW);
  Serial.print("Red = ");
  Serial.print(frequencyRed);
  Serial.print("  ");

  delay(100);
  digitalWrite(S2, HIGH);
  digitalWrite(S3, HIGH);
  frequencyGreen = pulseIn(sensorOut, LOW);
  Serial.print("Green= ");
  Serial.print(frequencyGreen);
  Serial.print("  ");

  delay(100);
  digitalWrite(S2, LOW);
  digitalWrite(S3, HIGH);
  frequencyBlue = pulseIn(sensorOut, LOW);
  Serial.print("Blue= ");
  Serial.print(frequencyBlue);
  Serial.println("  ");
  delay(100);
}

void checkColor() {
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledBlue, LOW);

  // if ((frequencyRed < 65 && frequencyRed > 0) &&
  //     (frequencyGreen < 200 && frequencyGreen > 120) &&
  //     (frequencyBlue < 110 && frequencyBlue > 80)) {
  //   analogWrite(ledRed, 255);
  //   Serial.println("RED object");
    
  // } else if ((frequencyRed < 150 && frequencyRed > 70) &&
  //            (frequencyGreen < 110 && frequencyGreen > 50) &&
  //            (frequencyBlue < 130 && frequencyBlue > 115)) {
  //   analogWrite(ledYellow, 255);
  //   Serial.println("Green Object!");

  // } else if ((frequencyRed < 250 && frequencyRed > 200) &&
  //            (frequencyGreen < 255 && frequencyGreen > 195) &&
  //            (frequencyBlue < 175 && frequencyBlue > 135)) {
  //   analogWrite(ledBlue, 255);
  //   Serial.println("Blue Object");
  // }

  if ((frequencyRed < 65 && frequencyRed > 0) && (frequencyGreen < 110 && frequencyGreen > 90)) {
    analogWrite(ledRed, 255);
    Serial.println("RED object");
    
  } else if ((frequencyGreen < 110 && frequencyGreen > 30)) {
    analogWrite(ledYellow, 255);
    Serial.println("Green Object!");

  } else if ((frequencyBlue < 175 && frequencyBlue > 80)) {
    analogWrite(ledBlue, 255);
    Serial.println("Blue Object");
  }

  delay(1000); // Adjust delay as needed
}
