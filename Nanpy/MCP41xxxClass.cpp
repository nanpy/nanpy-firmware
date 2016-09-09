#include "cfg.h"

#if USE_MCP41xxx

#include <Arduino.h>
#include <MCP41xxx.h>
#include "MCP41xxxClass.h"
#include <stdlib.h>

const char* nanpy::MCP41xxxClass::get_firmware_id()
{
    return "MCP41xxx";
}


void nanpy::MCP41xxxClass::elaborate( MethodDescriptor* m ) 
{
    ObjectsManager<MCP41xxx>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) 
    {
        MCP41xxx* pot;
        Serial1.println("f1")
        pot = new MCP41xxx (m->getInt(0), m->getInt(1), m->getInt(2));
        Serial1.println("f2")
        pot->begin();
        Serial1.println("f3")
        v.insert(pot);
        Serial1.println("f4")
        m->returns(v.getLastIndex());
        Serial1.println("f5")
    }

    if (strcmp(m->getName(), "begin") == 0) 
    {
        m->returns(v[m->getObjectId()]->begin());
    }

    if (strcmp(m->getName(), "analogWrite") == 0) 
    {
        m->returns(v[m->getObjectId()]->analogWrite(m->getInt(0), m->getInt(1)));
    }
}

#endif
