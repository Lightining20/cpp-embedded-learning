#include <stdio.h>
#include <stdint.h>
int main()
{
    typedef struct
    {
        uint8_t address;
        uint32_t last_value;
    } Sensor_t;

    int sensor_read(Sensor_t * s);

    return 0;
}