#ifndef BME280_CLASS
#define BME280_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Adafruit_BME280;

namespace nanpy
{
class BME280Class : public ObjectsManager<Adafruit_BME280>
{
  public:
    void elaborate(nanpy::MethodDescriptor *m);
    const char *get_firmware_id();
};
} // namespace nanpy

#endif
