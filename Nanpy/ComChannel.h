#ifndef COM_CHANNEL
#define COM_CHANNEL

#include "cfg.h"

#include <Arduino.h>

namespace nanpy {
    class ComChannel {

        public:
            static const unsigned int MAX_BUFFER_SIZE = 50;
            static char readBuffer[nanpy::ComChannel::MAX_BUFFER_SIZE];
            static bool available();
            static void connect();
            static void println(String& val);
            static void println(const char* val);
            static void println(int val);
            static void println(unsigned int val);
            static void println(float val);
            static void println(double val);
            static void println(long val);
            static void println(unsigned long val);
            static void readLine(char* extbuff);
    };
}

#endif

