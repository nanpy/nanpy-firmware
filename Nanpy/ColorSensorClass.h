#ifndef COLORSENSOR_CLASS
#define COLORSENSOR_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"
#include "ColorSensorWrapper.h"

class ColorSensor;

namespace nanpy {
    class ColorSensorClass: public ObjectsManager<ColorSensorWrapper> {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();
    };
}

#endif
