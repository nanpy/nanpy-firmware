#ifndef MEMS_CLASS
#define MEMS_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

// Default I2C address
#define MEMS_I2CADDR_DEFAULT                0x49

// I2C Register Channels
#define MEMS_CHANNEL_PARKING                0x00
#define MEMS_CHANNEL_1                      0x01
#define MEMS_CHANNEL_2                      0x02
#define MEMS_CHANNEL_3                      0x03
#define MEMS_CHANNEL_4                      0x04

// Commands
#define MEMS_REG_ERROR_CODE                 0x30
#define MEMS_REG_FIRMWARE_VERSION           0x31
#define MEMS_REG_GET_CHANNEL_NUMBER         0x79
#define MEMS_REG_DEVICE_DIMENSIONS          0x70
#define MEMS_REG_SET_CHANNEL_NUMBER         0x78

// Error Codes (Command 30)
#define MEMS_ERROR_COMMAND_INVALID          0x12
#define MEMS_ERROR_VALUE_OUT_OF_RANGE       0x22
#define MEMS_ERROR_COMMAND_EXECUTION_FAILED 0x32
#define MEMS_ERROR_COMMAND_NOT_ALLOWEDD     0x52

// Status Codes (Commands 78 and 79)
#define MEMS_STATUS_READY                   0x00
#define MEMS_STATUS_BUSY                    0x01
#define MEMS_STATUS_ERROR                   0x02

class Wire;

namespace nanpy {
    class MemsClass: public BaseClass {

        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();

    };
}

#endif
