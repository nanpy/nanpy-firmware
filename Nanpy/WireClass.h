#ifndef Wire_CLASS
#define Wire_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Wire;

namespace nanpy {
    class WireClass: public BaseClass {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif
