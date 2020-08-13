#ifndef LIQUID_CRYSTAL_CLASS_I2C
#define LIQUID_CRYSTAL_CLASS_I2C

#include "BaseClass.h"
#include "MethodDescriptor.h"

class LiquidCrystal_I2C;

namespace nanpy {
    class LiquidCrystalClass_I2C : public ObjectsManager<LiquidCrystal_I2C> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}


#endif
