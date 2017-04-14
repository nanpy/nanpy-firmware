#include "cfg_all.h"

#include <Arduino.h>
#include "ColorSensorClass.h"
#include <stdlib.h>

const char* nanpy::ColorSensorClass::get_firmware_id() {
  return "ColorSensor";
}

void nanpy::ColorSensorClass::elaborate( MethodDescriptor* m ) {
  ObjectsManager<ColorSensorWrapper>::elaborate(m);

  if (strcmp(m->getName(), "new") == 0) {
    v.insert(new ColorSensorWrapper(m->getInt(0), m->getInt(1), m->getInt(2), m->getInt(3), m->getInt(4)));
    m->returns(v.getLastIndex());
  }

  if (strcmp(m->getName(), "get_color") == 0) {
      char* p = m->getString(0);
    m->returns(v[m->getObjectId()]->getColor(*p));
  }
}
