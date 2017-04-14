#include "cfg_all.h"

#if USE_ColorSensor

#include "ColorSensorWrapper.h"
#include <Arduino.h>

nanpy::ColorSensorWrapper::ColorSensorWrapper(int s0Pin, int s1Pin, int s2Pin, int s3Pin, int sensorOutPin) {
  s0 = s0Pin;
  s1 = s1Pin;
  s2 = s2Pin;
  s3 = s3Pin;
  sensorOut = sensorOutPin;

  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
}

int nanpy::ColorSensorWrapper::getColor(char color) {
  if (color == 'r') {
    digitalWrite(s2, HIGH);
    digitalWrite(s3, LOW);
  } else if (color == 'g') {
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
  } else if (color == 'b') {
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
  }

  return pulseIn(sensorOut, LOW);
}

#endif
