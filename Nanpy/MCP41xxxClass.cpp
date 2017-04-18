#include "cfg.h"

#if USE_MCP41xxx

#include <Arduino.h>
#include <MCP41xxx.h>
#include "MCP41xxxClass.h"
#include "SPI.h"
#include <stdlib.h>

const char* nanpy::MCP41xxxClass::get_firmware_id(){
    return "MCP41xxx";
}

void nanpy::MCP41xxxClass::elaborate( nanpy::MethodDescriptor* m ) {
    ObjectsManager<MCP41xxx>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
        MCP41xxx* pot;
        pot = new MCP41xxx (m->getInt(0));
        pot->begin();
        v.insert(pot);
        m->returns(v.getLastIndex());
    }

    if (strcmp(m->getName(), "analogWrite") == 0) {
    	v[m->getObjectId()]->analogWrite(m->getInt(0), m->getInt(1));
        m->returns(0);
    }
}

#endif
