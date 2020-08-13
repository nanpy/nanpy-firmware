#pragma once

//#ifdef ESP8266

#include "BaseClass.h"
#include "MethodDescriptor.h"

namespace nanpy {
    class EspClass : public BaseClass {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
};

//#endif
