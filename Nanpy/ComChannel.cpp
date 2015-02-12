#include "ComChannel.h"
#include <Arduino.h>

char nanpy::ComChannel::read_buffer[MAX_READ_BUFFER_SIZE] = {0};

void readLineFromSerial(char* extbuff) {
    int i=0;
    char ch = '0';
    char* buff = nanpy::ComChannel::read_buffer;
    do {
        ch = Serial.read();
        if(ch < 255 && ch >= 0) {
            buff[i++] = ch;
        }
        if (i == MAX_READ_BUFFER_SIZE - 1) {
            buff[i] = '\0';
            break;
        }
    } while(ch != '\0');
    strcpy(extbuff, buff);
};

bool nanpy::ComChannel::available() {
    if (Serial.available() > 0)
        return true;
    else
        return false;
}

void nanpy::ComChannel::connect() {
    Serial.begin(BAUDRATE);
}

void nanpy::ComChannel::println(String& val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(const char* val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(int val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(unsigned int val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(float val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(double val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(long val) {
    Serial.println(val);
}

void nanpy::ComChannel::println(unsigned long val) {
    Serial.println(val);
}

void nanpy::ComChannel::readLine(char* extbuff) {
    readLineFromSerial(extbuff);
}

