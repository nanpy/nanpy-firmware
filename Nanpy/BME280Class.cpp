#include "cfg.h"

#if USE_BME280

#include <Arduino.h>
#include <Adafruit_BME280.h>
#include "BME280Class.h"
#include <stdlib.h>

const char *nanpy::BME280Class::get_firmware_id()
{
    return "BME280";
}

void nanpy::BME280Class::elaborate(MethodDescriptor *m)
{
    ObjectsManager<Adafruit_BME280>::elaborate(m);

    if (strcmp(m->getName(), "new") == 0)
    {
        Adafruit_BME280 *sensor = new Adafruit_BME280();
        sensor->begin(m->getInt(0));
        v.insert(sensor);
        m->returns(v.getLastIndex());
    }

    // float get_temperature();
    if (strcmp(m->getName(), "get_temperature") == 0)
    {
        float temperature = v[m->getObjectId()]->readTemperature();
        m->returns(temperature);
    }

    // float get_pressure();
    if (strcmp(m->getName(), "get_pressure") == 0)
    {
        float pressure = v[m->getObjectId()]->readPressure();
        m->returns(pressure);
    }

    // float get_humidity();
    if (strcmp(m->getName(), "get_humidity") == 0)
    {
        float humidity = v[m->getObjectId()]->readHumidity();
        m->returns(humidity);
    }
}

#endif
