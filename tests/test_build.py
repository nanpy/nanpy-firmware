from nose.tools import eq_, ok_
from path import path
# from pyavrutils import support, arduino
from pyavrutils.arduino import Arduino, ArduinoCompileError
from pyavrutils.support import simple_targets
import logging

root = path(__file__).parent.parent
sample_cfg = root / 'sample_cfg.h'
ino = root / 'Nanpy' / 'Nanpy.ino'
cfg = root / 'Nanpy' / 'cfg.h'

'''
sudo rm -f /usr/share/arduino/libraries/Robot_Control/Wire.h
'''

EXTERNAL_LIBS = [
               'USE_LiquidCrystal_I2C',
               'USE_OneWire',
               'USE_DallasTemperature',
               'USE_CapacitiveSensor',
               'USE_DHT',
               ]

MCUs=[
#      'atmega8', 
#      'atmega48', 
     'atmega168', 
     'atmega328p', 
#      'atmega640', 
     'atmega1280', 
     'atmega2560'
     ]

def get_features():
    ls = []
    print 'reading', sample_cfg
    for l in sample_cfg.lines():
        parts = l.split()
        if len(parts) >= 3:
            if parts[0] == '#define':
                s = parts[1]
                if s.startswith('USE'):
                    ls.append(s)
    assert len(ls) > 3
    print 'get_features:', ls
    return ls

def check_build(ino, mcu):
    cc = Arduino(mcu=mcu)
    print cc.mcu, ino
    cc.build(ino)
    ok_( cc.size().ok )
    
    

def test_config():
    known_mcus=[t.mcu for t in simple_targets()]
    for mcu in MCUs:
        assert mcu in known_mcus, 'MCU %s was not found in config %s'% (mcu, known_mcus)
    
def test_build():
    print 'available MCUs:', [t.mcu for t in simple_targets()]
    for mcu in MCUs:
        print '++++++++++++++++++++++ MCU:', mcu
        for f in get_features():
            if f not in EXTERNAL_LIBS:
                scfg = sample_cfg.text()
#                 scfg=sample_cfg.text().replace(f, '%s 1 \n//' % f)
                scfg+='\n#define %s 1 \n' % f
    #             scfg='#define %s 1' % f
                print '*********** feature:', f
#                 print 'cfg.h:', scfg

                cfg.write_text(scfg)
                check_build(ino, mcu)
#     assert 0
