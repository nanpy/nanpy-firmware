#include "cfg_all.h"

#if USE_MEMS

#include <Arduino.h>
#include <Wire.h>
#include "MemsClass.h"
#include <stdlib.h>

const char* nanpy::MemsClass::get_firmware_id()
{
    return "Mems";
}

void nanpy::MemsClass::elaborate( MethodDescriptor* m ) {

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
    if (strcmp(m->getName(), "get_error_code") == 0) {
        uint8_t addr;
        addr = m->getInt(0);
        Wire.beginTransmission(addr);
        Wire.write((uint8_t)MEMS_REG_ERROR_CODE);
        Wire.endTransmission();
        Wire.requestFrom(addr, (uint8_t)1);
        uint8_t errorCode = Wire.read();
        m->returns(errorCode);
    }
    if (strcmp(m->getName(), "get_firmware_version") == 0) {
        uint8_t addr;
        addr = m->getInt(0);
        Wire.beginTransmission(addr);
        Wire.write((uint8_t)MEMS_REG_FIRMWARE_VERSION);
        Wire.endTransmission();
        Wire.requestFrom(addr, (uint8_t)3);
        uint32_t data; // Firmware version is made up of 3 bytes
        data = Wire.read() & 0xFF; // Trim each read result
        data <<= 8;
        data |= Wire.read() & 0xFF;
        data <<= 8;
        data |= Wire.read() & 0xFF;
        m->returns(data);
    }
    if (strcmp(m->getName(), "get_status") == 0) {
        uint8_t addr;
        addr = m->getInt(0);
        Wire.beginTransmission(addr);
        Wire.write((uint8_t)MEMS_REG_GET_CHANNEL_NUMBER);
        Wire.endTransmission();
        Wire.requestFrom(addr, (uint8_t)2);
        uint16_t data;
        data = Wire.read(); // Status code
        data <<= 8;
        data |= Wire.read(); // Channel number
        m->returns(data);
    }
    if (strcmp(m->getName(), "set_channel_number") == 0) {
        uint8_t addr;
        uint8_t channel;
        addr = m->getInt(0);
        channel = m->getInt(1);
        Wire.beginTransmission(addr);
        Wire.write((uint8_t)MEMS_REG_SET_CHANNEL_NUMBER);
        Wire.write(channel);
        Wire.endTransmission();
        delay(15); // Delay while switch updates (from spec)
        Wire.requestFrom(addr, (uint8_t)1);
        uint8_t data = Wire.read();
        m->returns(data);
    }
    if (strcmp(m->getName(), "get_device_dimensions") == 0) {
        uint8_t addr;
        addr = m->getInt(0);
        Wire.beginTransmission(addr);
        Wire.write((uint8_t)MEMS_REG_DEVICE_DIMENSIONS);
        Wire.endTransmission();
        Wire.requestFrom(addr, (uint8_t)2);
        uint16_t data;
        data = Wire.read(); // Number of inputs
        data <<= 8;
        data |= Wire.read(); // Number of outputs
        m->returns(data);
    }
};

#endif
