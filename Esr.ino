
#include <Metro.h>

int ledPin = 2;
int valveControl = 4;
int photoDiode = A5;    

float measuredVoltage = 0.0;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
boolean timeCheck = true;

Metro measTime = Metro(400); // to sample at every 400 ms during 5 mins
Metro valveTime = Metro(500); // to run pinch valve at every 500 ms during the first 15 s

unsigned long measDuration = 300000; // measurement for 5 min
unsigned long valveDuration = 15000; // pinch valve works for 15 s
unsigned long startTime;

void setup() {
  pinMode(photoDiode, INPUT);
  pinMode(valveControl, OUTPUT);
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin, HIGH);
  startTime = millis();
  Serial.begin(9600);
}

void loop() {
  if (millis() - startTime <= measDuration) { // sampling process
    digitalWrite(ledPin, HIGH);
    
    if (measTime.check()) {
      sensorValue = analogRead(photoDiode);
      measuredVoltage = (sensorValue*5.0)/1023.0;
      Serial.println(measuredVoltage, 5);
//      measuredVoltage = 10.0*((sensorValue*5.0)/1023.0 - 3.20);
//      Serial.println(measuredVoltage, 2);
    }
  }
  else {
    digitalWrite(ledPin, LOW);
  }

  if (millis() - startTime <= valveDuration) { // valve process
    if (valveTime.check()) {
      digitalWrite(valveControl, timeCheck);
      timeCheck = !timeCheck;
    }
  }
  else {
    digitalWrite(valveControl, LOW);
  }
    
}

