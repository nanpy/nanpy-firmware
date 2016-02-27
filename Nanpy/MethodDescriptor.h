#ifndef METHOD_DESCRIPTOR
#define METHOD_DESCRIPTOR

#include <Arduino.h>
#include <WString.h>

namespace nanpy {
    class MethodDescriptor {

        private:
            char name[50];
            int objid;
            char classname[50];
            int n_args;
            char **stack;
            static char **stack_pool;
            static int stack_pool_size;

        public:
            MethodDescriptor();
            int getNArgs();
            char* getClass();
            int getObjectId();
            bool getBool(int n);
            int getInt(int n);
            byte getByte(int n);
            float getFloat(int n);
            double getDouble(int n);
            char* getString(int n);
            char* getName();
            void returns(String& val);
            void returns(const char* val);
            void returns(int val);
            void returns(unsigned int val);
            void returns(float val);
            void returns(double val);
            void returns(long val);
            void returns(unsigned long val);

    };
}
#endif
