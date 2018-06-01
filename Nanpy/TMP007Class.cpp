#include "cfg.h"

#if USE_TMP007

#include <Arduino.h>
#include "Adafruit_TMP007.h"
#include "TMP007Class.h"
#include <stdlib.h>

const char *nanpy::TMP007Class::get_firmware_id()
{
    return "TMP007";
}

void nanpy::TMP007Class::elaborate(MethodDescriptor *m)
{
    ObjectsManager<Adafruit_TMP007>::elaborate(m);

    if (strcmp(m->getName(), "new") == 0)
    {
        Adafruit_TMP007 *sensor = new Adafruit_TMP007(m->getInt(0));
        sensor->begin(m->getInt(1));
        v.insert(sensor);
        m->returns(v.getLastIndex());
    }

    // float get_object_temperature();
    if (strcmp(m->getName(), "get_object_temperature") == 0)
    {
        float objectTemp = v[m->getObjectId()]->readObjTempC();
        m->returns(objectTemp);
    }

    // float get_die_temperature();
    if (strcmp(m->getName(), "get_die_temperature") == 0)
    {
        float dieTemp = v[m->getObjectId()]->readDieTempC();
        m->returns(dieTemp);
    }
}

#endif
