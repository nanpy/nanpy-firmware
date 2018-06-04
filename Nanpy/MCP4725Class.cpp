#include "cfg.h"

#if USE_MCP4725

#include <Arduino.h>
#include <Adafruit_MCP4725.h>
#include "MCP4725Class.h"
#include <stdlib.h>

const char* nanpy::MCP4725Class::get_firmware_id() {
  return "MCP4725";
}

void nanpy::MCP4725Class::elaborate( MethodDescriptor* m ) {
  ObjectsManager<Adafruit_MCP4725>::elaborate(m);
  
  if(strcmp(m->getName(), "new") == 0) {
    //Adafruit_TLC5947* tlc = new Adafruit_TLC5947(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
    Adafruit_MCP4725* dac = new Adafruit_MCP4725();
    dac->begin(m->getInt(0));
    v.insert(dac);
    m->returns(v.getLastIndex());
  }

  // void setVoltage( uint16_t output, bool writeEEPROM );
  if (strcmp(m->getName(), "setVoltage") == 0) {
    v[m->getObjectId()]->setVoltage(m->getInt(0),m->getBool(1));
    m->returns(0); 
   }
}

#endif
