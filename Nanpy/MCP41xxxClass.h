#ifndef MCP41XXX_CLASS
#define MCP41XXX_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class MCP41xxx;

namespace nanpy{
    class MCP41xxxClass: public ObjectsManager<MCP41xxx>{
      public:
        void elaborate( nanpy::MethodDescriptor* m);
        const char* get_firmware_id();
    };
}

#endif
