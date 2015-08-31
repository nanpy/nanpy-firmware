#include "cfg_all.h"

#if USE_Wire

#include <Arduino.h>
#include <Wire.h>
#include "WireClass.h"
#include <stdlib.h>

const char* nanpy::WireClass::get_firmware_id()
{
    return "Wire";
}

void nanpy::WireClass::elaborate( MethodDescriptor* m ) {

    if (strcmp(m->getName(), "begin") == 0) {
        if (m->getNArgs())
        {
            // slave
            Wire.begin(m->getInt(0));
        }
        else
        {
            // master
            Wire.begin();
        }
        m->returns(0);
    }
    if (strcmp(m->getName(), "requestFrom") == 0) {
        byte x = Wire.requestFrom(m->getInt(0), m->getInt(1), m->getInt(2));
        m->returns(x);
    }
    if (strcmp(m->getName(), "beginTransmission") == 0) {
        Wire.beginTransmission(m->getInt(0));
        m->returns(0);
    }
    if (strcmp(m->getName(), "endTransmission") == 0) {
        byte x = Wire.endTransmission(m->getInt(0));
        m->returns(x);
    }
    if (strcmp(m->getName(), "write") == 0) {
        // string and array writes are not implemented
        byte x = Wire.write(m->getInt(0));
        m->returns(x);
    }
    if (strcmp(m->getName(), "available") == 0) {
        int x = Wire.available();
        m->returns(x);
    }
    if (strcmp(m->getName(), "read") == 0) {
        byte x = Wire.read();
        m->returns(x);
    }

    // onReceive and onRequest are not implemented

};

#endif
