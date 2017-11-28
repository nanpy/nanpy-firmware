#ifndef MCP4725_CLASS
#define MCP4725_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Adafruit_MCP4725;

namespace nanpy{
    class MCP4725Class: public ObjectsManager<Adafruit_MCP4725>{
      public:
        void elaborate( nanpy::MethodDescriptor* m);
        const char* get_firmware_id();
    };
}

#endif
