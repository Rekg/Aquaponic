#include <Arduino.h>
/*
//Pin assignments
const int WATER_LEVEL_PIN = A0;
const int RELAY_PIN = 13;

void setup() {
pinMode(WATER_LEVEL_PIN, INPUT);
pinMode(RELAY_PIN, OUTPUT);
digitalWrite(RELAY_PIN, LOW); // Initialize relay to off state
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(WATER_LEVEL_PIN);
Serial.print("sensor = ");
Serial.print(sensorValue);
Serial.print("\n");
delay(2);


if (sensorValue >= 100 && sensorValue <= 600) {
digitalWrite(RELAY_PIN, LOW); // Activate the relay or perform any other action
delay(100);
}
else if (sensorValue >= 601 && sensorValue <= 625) {
digitalWrite(RELAY_PIN, HIGH); // Deactivate the relay or perform any other action
delay(60000);
}
else if (sensorValue >= 626 && sensorValue <= 700) {
digitalWrite(RELAY_PIN, LOW); // Activate the relay or perform any other action
delay(100);
}
else {
digitalWrite(RELAY_PIN, HIGH); // Deactivate the relay or perform any other action
delay(100);
}
if (sensorValue >= 0) {
digitalWrite(RELAY_PIN, HIGH); // Activate the relay or perform any other action
delay(60000);
}
else {
digitalWrite(RELAY_PIN, HIGH); // Deactivate the relay or perform any other action
delay(100);
}

}*/



#define sensorPower 7
#define sensorPin A0
const int RELAY_PIN = 13;
int count;

// Value for storing water level
int val = 0;

void setup() {
  // Set D7 as an OUTPUT
  pinMode(sensorPower, OUTPUT);
  
  // Set to LOW so no power flows through the sensor
  digitalWrite(sensorPower, LOW);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  
  Serial.begin(9600);
}

void loop() {
  //get the reading from the function below and print it
  int level = readSensor();
  
  Serial.print("Water level: ");
  Serial.println(level);
  
  if (level >= 500)
    {
      digitalWrite(RELAY_PIN, LOW); 
      delay(60000);

    }
  else 
  {
    digitalWrite(RELAY_PIN, HIGH); 
    
  }
  delay(1000);
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);    // Turn the sensor OFF
  return val;              // send current reading
}