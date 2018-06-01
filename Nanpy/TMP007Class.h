#ifndef TMP007_CLASS
#define TMP007_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class Adafruit_TMP007;

namespace nanpy
{
class TMP007Class : public ObjectsManager<Adafruit_TMP007>
{
  public:
    void elaborate(nanpy::MethodDescriptor *m);
    const char *get_firmware_id();
};
} // namespace nanpy

#endif
