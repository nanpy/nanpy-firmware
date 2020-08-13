
// const int variables cannot be checked automatically like defines

DEFINE(A0)

#ifdef ARDUINO_ARCH_AVR
    DEFINE(SS)
    DEFINE(MOSI)
    DEFINE(MISO)
    DEFINE(SCK)
#endif


