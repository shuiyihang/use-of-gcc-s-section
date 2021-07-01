#ifndef __MPU6050_API_H__
#define __MPU6050_API_H__

#include "device.h"
typedef struct mpu6050_api
{
    void (*read)(void);
}mpu6050_api_t;


static inline void mpu6050_read_api(struct device *dev)
{
    const struct mpu6050_api  *api = dev->driver_api;
    return api->read();
}


#endif