#include "cfg_all.h"

#if USE_LiquidCrystal

#include <Arduino.h>
#include <LiquidCrystal.h>
#include "LiquidCrystalClass.h"
#include <stdlib.h>
#include <math.h>

const char* nanpy::LiquidCrystalClass::get_firmware_id()
{
    return "Lcd";
}

void nanpy::LiquidCrystalClass::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<LiquidCrystal>::elaborate(m);

        if (strcmp(m->getName(), "new") == 0) {
            int prm = 0;
            v.insert(new LiquidCrystal (m->getInt(prm++), m->getInt(prm++),
                            m->getInt(prm++), m->getInt(prm++), m->getInt(prm++), m->getInt(prm++)));
            v[m->getObjectId()]->begin(m->getInt(prm++), m->getInt(prm++));
            m->returns(v.getLastIndex());
        }

        if (strcmp(m->getName(), "printString") == 0) {
            if(m->getNArgs() == 3) {
                v[m->getObjectId()]->setCursor(m->getInt(1), m->getInt(2));
                v[m->getObjectId()]->print(m->getString(0));
            }
            else
                v[m->getObjectId()]->print(m->getString(0));
            m->returns(0);
        }

        if (strcmp(m->getName(), "setCursor") == 0) {
            v[m->getObjectId()]->setCursor(m->getInt(0), m->getInt(1));
            m->returns(0);
        }

        if (strcmp(m->getName(), "autoscroll") == 0) {
            v[m->getObjectId()]->autoscroll();
            m->returns(0);
        }

        if (strcmp(m->getName(), "noAutoscroll") == 0) {
            v[m->getObjectId()]->noAutoscroll();
            m->returns(0);
        }

        if (strcmp(m->getName(), "clear") == 0) {
            v[m->getObjectId()]->clear();
            m->returns(0);
        }

        if (strcmp(m->getName(), "createChar") == 0) {
            byte chr[8];
            for(int i = 0; i < 8; i++) {
                chr[i] = m->getByte(i+1);
            }
            v[m->getObjectId()]->createChar(m->getByte(0), chr);
            m->returns(0);
        }

        if (strcmp(m->getName(), "write") == 0) {
            v[m->getObjectId()]->write(m->getByte(0));
            m->returns(0);
        }
};
#endif
