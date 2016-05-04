#pragma once

// check configuration for compatibility

#ifndef ARDUINO_ARCH_AVR
// disable Due incompatible features
//#define USE_ArduinoCore                             0
//#define USE_RAM                                     0
#define USE_EEPROM                                  0
#define USE_Register                                0
#define USE_Watchdog                                0
#define USE_Counter                                 0
#define USE_DHT                                     0
#define USE_LiquidCrystal_I2C                       0
#endif

// check configuration for problems

#ifdef ARDUINO_ARCH_AVR
#if USE_Tone
# if USE_Counter
#  error "USE_Tone conflicts with USE_Counter!"
# endif
#endif
#endif

#ifdef ESP8266
#  define USE_ESP                                  1
#else
#  define USE_ESP                                  0
#endif

#ifndef ESP8266
#  define USE_WIFI_CONNECTION                      0
#endif
