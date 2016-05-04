//#include "cfg_all.h"

#ifdef ESP8266

#include "EspClass.h"
#include <stdlib.h>

const char* nanpy::EspClass::get_firmware_id()
{
    return "Esp";
}

// https://github.com/esp8266/Arduino/blob/master/cores/esp8266/Esp.cpp
void nanpy::EspClass::elaborate( nanpy::MethodDescriptor* m ) {
    if (strcmp(m->getName(), "wdtEnable") == 0) {
    	ESP.wdtEnable(100);
        m->returns(0);
    }
    if (strcmp(m->getName(), "wdtDisable") == 0) {
    	ESP.wdtDisable();
        m->returns(0);
    }

    if (strcmp(m->getName(), "wdtFeed") == 0) {
    	ESP.wdtFeed();
        m->returns(0);
    }
//    if (strcmp(m->getName(), "deepSleep") == 0) {
//    	ESP.deepSleep();
//        m->returns(0);
//    }
    if (strcmp(m->getName(), "reset") == 0) {
    	ESP.reset();
        m->returns(0);
    }
    if (strcmp(m->getName(), "restart") == 0) {
    	ESP.restart();
        m->returns(0);
    }
    if (strcmp(m->getName(), "getVcc") == 0) {
        m->returns(ESP.getVcc());
    }
    if (strcmp(m->getName(), "getFreeHeap") == 0) {
        m->returns(ESP.getFreeHeap());
    }
    if (strcmp(m->getName(), "getChipId") == 0) {
        m->returns(ESP.getChipId());
    }
    if (strcmp(m->getName(), "getSdkVersion") == 0) {
        m->returns(ESP.getSdkVersion());
    }
    if (strcmp(m->getName(), "getBootVersion") == 0) {
        m->returns(ESP.getBootVersion());
    }
    if (strcmp(m->getName(), "getBootMode") == 0) {
        m->returns(ESP.getBootMode());
    }
    if (strcmp(m->getName(), "getCpuFreqMHz") == 0) {
        m->returns(ESP.getCpuFreqMHz());
    }
    if (strcmp(m->getName(), "getFlashChipId") == 0) {
        m->returns(ESP.getFlashChipId());
    }
    if (strcmp(m->getName(), "getFlashChipRealSize") == 0) {
        m->returns(ESP.getFlashChipRealSize());
    }

    if (strcmp(m->getName(), "getFlashChipSize") == 0) {
        m->returns(ESP.getFlashChipSize());
    }
    if (strcmp(m->getName(), "getFlashChipSpeed") == 0) {
        m->returns(ESP.getFlashChipSpeed());
    }
    if (strcmp(m->getName(), "getFlashChipMode") == 0) {
        m->returns(ESP.getFlashChipMode());
    }
//    if (strcmp(m->getName(), "magicFlashChipSize") == 0) {
//        m->returns(ESP.magicFlashChipSize());
//    }
//    if (strcmp(m->getName(), "magicFlashChipSpeed") == 0) {
//        m->returns(ESP.magicFlashChipSpeed());
//    }
//    if (strcmp(m->getName(), "magicFlashChipMode") == 0) {
//        m->returns(ESP.magicFlashChipMode());
//    }
    if (strcmp(m->getName(), "getFlashChipSizeByChipId") == 0) {
        m->returns(ESP.getFlashChipSizeByChipId());
    }
//    if (strcmp(m->getName(), "checkFlashConfig") == 0) {
//        m->returns(ESP.checkFlashConfig());
//    }
    if (strcmp(m->getName(), "getResetReason") == 0) {
    	String s = ESP.getResetReason();
        m->returns(s);
    }
    if (strcmp(m->getName(), "getResetInfo") == 0) {
    	String s = ESP.getResetInfo();
        m->returns(s);
    }
    if (strcmp(m->getName(), "getSketchSize") == 0) {
        m->returns(ESP.getSketchSize());
    }
    if (strcmp(m->getName(), "getFreeSketchSpace") == 0) {
        m->returns(ESP.getFreeSketchSpace());
    }
    if (strcmp(m->getName(), "flashEraseSector") == 0) {
        m->returns(ESP.flashEraseSector(m->getInt(0)));
    }
    if (strcmp(m->getName(), "flashWrite") == 0) {
    	uint32_t data = m->getInt(1);
        m->returns(ESP.flashWrite(m->getInt(0), &data, 1));
    }
    if (strcmp(m->getName(), "flashRead") == 0) {
    	uint32_t data;
    	ESP.flashRead(m->getInt(0), &data, 1);
        m->returns(data);
    }
};

#endif
