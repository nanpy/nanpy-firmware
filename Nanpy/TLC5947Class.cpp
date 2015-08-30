#include "cfg.h"

#if USE_TLC5947

#include <Arduino.h>
#include <Adafruit_TLC5947.h>
#include "TLC5947Class.h"
#include <stdlib.h>

const char* nanpy::TLC5947Class::get_firmware_id() {
  return "TLC5947";
}

void nanpy::TLC5947Class::elaborate( MethodDescriptor* m ) {
  ObjectsManager<Adafruit_TLC5947>::elaborate(m);
  
  if(strcmp(m->getName(), "new") == 0) {
    Adafruit_TLC5947* tlc = new Adafruit_TLC5947(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
    tlc->begin();
    v.insert(tlc);
    m->returns(v.getLastIndex());
  }
  
  if (strcmp(m->getName(), "setLED") == 0) {
    v[m->getObjectId()]->setLED(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3));
    m->returns(0);
  }
  
  if (strcmp(m->getName(), "write") == 0) {
    v[m->getObjectId()]->write();
    m->returns(0);
  }
  
}

#endif
