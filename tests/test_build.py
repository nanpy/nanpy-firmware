from nose.tools import eq_, ok_
from path import path
from pyavrutils.arduino import Arduino, ArduinoCompileError
from pyavrutils.support import simple_targets
import logging
from nose_ittr import IttrMultiplier, ittr
import tempfile

root = path(__file__).abspath().parent.parent
sample_cfg = root / 'sample_cfg.h'

'''
sudo rm -f /usr/share/arduino/libraries/Robot_Control/Wire.h
'''

EXTERNAL_LIBS = [
    'USE_LiquidCrystal_I2C',
    'USE_OneWire',
    'USE_DallasTemperature',
    'USE_CapacitiveSensor',
    'USE_DHT',
    'USE_TLC5947'
]

MCUs = [
    #      'atmega8',
    #      'atmega48',
    'atmega168',
    'atmega328p',
    #      'atmega640',
    'atmega1280',
    'atmega2560'
]


def tmpdir(dir=None, suffix=''):
    x = tempfile.mkdtemp(suffix=suffix, prefix='nanpy_', dir=dir)
    return path(x)


def get_features():
    ls = []
    print 'reading', sample_cfg
    for l in sample_cfg.lines():
        parts = l.split()
        if len(parts) >= 3:
            if parts[0] == '#define':
                s = parts[1]
                if s.startswith('USE'):
                    if not s.endswith('CONNECTION'):
                        ls.append(s)
    assert len(ls) > 3
    print 'get_features:', ls
    return ls

FEATURES = [f for f in get_features() if f not in EXTERNAL_LIBS]

ZERO_CFG = '\n'.join(['#define %s 0' % x for x in FEATURES])


def test_config():
    known_mcus = [t.mcu for t in simple_targets()]
    for mcu in MCUs:
        assert mcu in known_mcus, 'MCU %s was not found in config %s' % (
            mcu, known_mcus)


class TestFoo(object):
    __metaclass__ = IttrMultiplier

    @ittr(mcu=MCUs, feature=FEATURES)
    def test_build(self):
        tdir = tmpdir()
        try:

            f = self.feature
            scfg = ZERO_CFG + '''
            #undef %s
            #define %s  1
            ''' % (f, f)

            (root / 'Nanpy').copytree(tdir / 'Nanpy')
            ino = tdir / 'Nanpy' / 'Nanpy.ino'
            cfg = tdir / 'Nanpy' / 'cfg.h'

            cfg.write_text(scfg)

            cc = Arduino(mcu=self.mcu)
            print cc.mcu, ino
            cc.build(ino)
            ok_(cc.size().ok)
        finally:
            tdir.rmtree()
