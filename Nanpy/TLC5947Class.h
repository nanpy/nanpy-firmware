#ifndef TLC5947_CLASS
#define TLC5947_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Adafruit_TLC5947;

namespace nanpy {
  class TLC5947Class: public ObjectsManager<Adafruit_TLC5947> {
     public:
       void elaborate( nanpy::MethodDescriptor* m );
       const char* get_firmware_id();
  };
}

#endif
