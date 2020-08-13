#include "cfg_all.h"

#if USE_DallasTemperature

#include <Arduino.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include "DallasTemperatureClass.h"
#include <stdlib.h>

const char* nanpy::DallasTemperatureClass::get_firmware_id()
{
    return "DallasTemperature";
}

void nanpy::DallasTemperatureClass::elaborate( nanpy::MethodDescriptor* m ) {
        ObjectsManager<DallasTemperature>::elaborate(m);

        if (strcmp(m->getName(),"new") == 0) {
            int prm = 0;
            OneWire* wr = new OneWire(m->getInt(0));
            DallasTemperature* dt = new DallasTemperature(&(*wr));
            v.insert(dt);
            dt->begin();
            m->returns(v.getLastIndex());
        }

        if (strcmp(m->getName(), "setResolution") == 0) {
            v[m->getObjectId()]->setResolution(m->getInt(0));
            m->returns(0);
        }

        if (strcmp(m->getName(), "getResolution") == 0) {
            m->returns(v[m->getObjectId()]->getResolution());
        }

        if (strcmp(m->getName(), "requestTemperatures") == 0) {
            if (m->getNArgs() == 1) {
                m->returns(v[m->getObjectId()]->requestTemperaturesByIndex(m->getInt(0)));
            } else if (m->getNArgs() > 1) {
                byte addr[8];
                for(int i = 0 ; i < m->getNArgs() ; i++) {
                    addr[i] = m->getByte(i);
                }
                m->returns(v[m->getObjectId()]->requestTemperaturesByAddress(addr));
            } else {
                v[m->getObjectId()]->requestTemperatures();
                m->returns(0);
            }
        }

        if (strcmp(m->getName(), "getTempC") == 0) {
            if(m->getNArgs() == 1) {
                m->returns(v[m->getObjectId()]->getTempCByIndex(m->getInt(0)));
            } else {
                byte addr[8];
                for(int i = 0 ; i < m->getNArgs() ; i++) {
                    addr[i] = m->getByte(i);
                }
                m->returns(v[m->getObjectId()]->getTempC(addr));
            }
        }

        if (strcmp(m->getName(), "getTempF") == 0) {
            if(m->getNArgs() == 1) {
                m->returns(v[m->getObjectId()]->getTempFByIndex(m->getInt(0)));
            } else {
                byte addr[8];
                for(int i = 0 ; i < m->getNArgs() ; i++) {
                    addr[i] = m->getByte(i);
                }
                m->returns(v[m->getObjectId()]->getTempF(addr));
            }
        }

        if (strcmp(m->getName(), "getAddress") == 0) {
            byte addr[8];
            String addr_hex = String();
            if(!v[m->getObjectId()]->getAddress(addr, m->getInt(0))) {
                m->returns(1);
                return;
            }
   
            char stmp[3];
            for( int cc = 0; cc < 8; cc++ )
            {
                sprintf(stmp, "%02X", addr[cc]);
                addr_hex.concat( stmp );
                if (cc < 7)
                    addr_hex.concat( "." );
            }
            m->returns(addr_hex);
        }

        if (strcmp(m->getName(), "getDeviceCount") == 0) {
            m->returns(v[m->getObjectId()]->getDeviceCount());
        }
};
#endif
