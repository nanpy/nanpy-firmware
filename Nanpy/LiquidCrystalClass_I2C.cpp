#include "cfg_all.h"

#if USE_LiquidCrystal_I2C

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "LiquidCrystalClass_I2C.h"
#include <stdlib.h>
#include <math.h>

const char* nanpy::LiquidCrystalClass_I2C::get_firmware_id()
{
    return "Lcd_I2C";
}

void nanpy::LiquidCrystalClass_I2C::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<LiquidCrystal_I2C>::elaborate(m);

        if (strcmp(m->getName(), "new") == 0) {       
            int prm = 0;
            // lcd_Addr, En, Rw, Rs, d4, d5, d6, d7
            v.insert(new LiquidCrystal_I2C (
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    m->getInt(prm++),
                    (t_backlighPol)m->getInt(prm++)));
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

        if (strcmp(m->getName(), "setBacklight") == 0) {
            v[m->getObjectId()]->setBacklight(m->getInt(0));
            m->returns(0);
        }
};
#endif
