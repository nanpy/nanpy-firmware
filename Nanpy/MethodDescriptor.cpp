#include "MethodDescriptor.h"
#include <stdlib.h>
#include <math.h>
#include "ComChannel.h"
#include "consts.h"

char** nanpy::MethodDescriptor::stack_pool = 0;
int nanpy::MethodDescriptor::stack_pool_size = 3;

nanpy::MethodDescriptor::MethodDescriptor() {

    char buff[MAX_READ_BUFFER_SIZE];

    ComChannel::readLine(this->classname);

    ComChannel::readLine(buff);
    this->objid = atoi(buff);

    ComChannel::readLine(buff);
    this->n_args = atoi(buff);

    ComChannel::readLine(this->name);

    if (this->n_args > nanpy::MethodDescriptor::stack_pool_size) {
        if(nanpy::MethodDescriptor::stack_pool != 0) {
            for(int n = 0; n < nanpy::MethodDescriptor::stack_pool_size; n++) {
                delete(nanpy::MethodDescriptor::stack_pool[n]);
            }
            delete(nanpy::MethodDescriptor::stack_pool);
        }
        nanpy::MethodDescriptor::stack_pool = 0;
        nanpy::MethodDescriptor::stack_pool_size = this->n_args;
    }

    if (nanpy::MethodDescriptor::stack_pool == 0) {
        nanpy::MethodDescriptor::stack_pool = (char**)malloc(sizeof(char*) * nanpy::MethodDescriptor::stack_pool_size);
        for(int i = 0; i < nanpy::MethodDescriptor::stack_pool_size; i++) {
            nanpy::MethodDescriptor::stack_pool[i] = (char*)malloc(sizeof(char) * MAX_READ_BUFFER_SIZE);
        }
    }

    this->stack = nanpy::MethodDescriptor::stack_pool;

    for(int n = 0; n < this->n_args; n++) {
        ComChannel::readLine(this->stack[n]);
    }
};

int nanpy::MethodDescriptor::getNArgs() {
    return this->n_args;
};

bool nanpy::MethodDescriptor::getBool(int n) {
    return strcmp(this->stack[n], "True") == 0 ? true : false;
};

int nanpy::MethodDescriptor::getInt(int n) {
    return atoi(this->stack[n]);
};

byte nanpy::MethodDescriptor::getByte(int n) {
    return byte(getInt(n));
};

float nanpy::MethodDescriptor::getFloat(int n) {
    return atof(this->stack[n]);
};

double nanpy::MethodDescriptor::getDouble(int n) {
    return atof(this->stack[n]);
};

char* nanpy::MethodDescriptor::getString(int n) {
    return this->stack[n];
};

char* nanpy::MethodDescriptor::getClass() {
    return this->classname;
};

int nanpy::MethodDescriptor::getObjectId() {
    return this->objid;
};

char* nanpy::MethodDescriptor::getName() {
    return this->name;
};

void nanpy::MethodDescriptor::returns(String& val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(const char* val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(int val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(unsigned int val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(float val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(double val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(long val) {
    ComChannel::println(val);
}

void nanpy::MethodDescriptor::returns(unsigned long val) {
    ComChannel::println(val);
}

