#pragma once


// only for ESP8266
#define USE_WIFI_CONNECTION                         0

// for WIFI connection
#define WIFI_SSID 		"***"
#define WIFI_PASSWORD 	"***"


// for serial connection
#define BAUDRATE 115200
#define COMM_SERIAL                                 Serial

// info about existence of other features
#define USE_Info                                    1

// definitions: MCU type, frequency, Arduino version,
// EEPROM size, RAM size, pin count, build time,..
#define USE_Define                                  1

// low level mapping of pins and ports
#define USE_ArduinoCore                             1

// read, write RAM
#define USE_RAM                                     1

// read, write EEPROM
#define USE_EEPROM                                  1

// read, write AVR registers
#define USE_Register                                0

// watchdog and reset
#define USE_Watchdog                                0

#define USE_Tone                                    0

#define USE_LiquidCrystal                           0

// I2C
#define USE_Wire                                    0

#define USE_Servo                                   0

#define USE_Stepper                                 0

// frequency counter,  USE_Tone should be off!
#define USE_Counter                                 0

// GW Robotics Classes
#define USE_Ultrasonic				                0
#define USE_ColorSensor                             0

///////////////////////////////////////////////////////////////////////
// external libraries should be installed for the following features:
///////////////////////////////////////////////////////////////////////

// install with Library Manager: "OneWire"
// https://github.com/PaulStoffregen/OneWire
#define USE_OneWire                                 0

// install with Library Manager: "DallasTemperature"
// https://github.com/milesburton/Arduino-Temperature-Control-Library
#define USE_DallasTemperature                       0


// install with Library Manager: "CapacitiveSensor"
// https://github.com/PaulStoffregen/CapacitiveSensor
#define USE_CapacitiveSensor                        0

// install with Library Manager: "DHT sensor library","Adafruit Unified Sensor"
// https://github.com/adafruit/DHT-sensor-library
#define USE_DHT                                     0

// https://bitbucket.org/fmalpartida/new-liquidcrystal
#define USE_LiquidCrystal_I2C                       0

// install with Library Manager: "Adafruit TLC5947"
// https://github.com/adafruit/Adafruit_TLC5947
#define USE_TLC5947                                 0

// install with Library Manager: "MCP41XXX"
// https://github.com/ArduinoMax/MCP41xxx
#define USE_MCP41xxx                                0
