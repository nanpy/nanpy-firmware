#ifndef ULTRASONIC_CLASS
#define ULTRASONIC_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"
#include "UltrasonicWrapper.h"

class Ultrasonic;

namespace nanpy {
	class UltrasonicClass: public ObjectsManager<UltrasonicWrapper> {
		
		public:
			void elaborate( nanpy::MethodDescriptor* m );
			const char* get_firmware_id();
	};
}

#endif
