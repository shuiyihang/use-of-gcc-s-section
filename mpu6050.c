/**
 * 模拟注册设备1
 * 
*/
#include "stdio.h"
#include "device.h"
#include "mpu6050_api.h"

int mpu6050_init(struct device *dev)
{
    printf("mpu6050 init\n");
    return 0;
}

void mpu6050_read(void)
{
    printf("mpu6050 ax:%d ay:%d az:%d\t\n",120,60,0);
}

const mpu6050_api_t  iic_6050_api = {
    .read = mpu6050_read,
};

DEVICE_AND_API_INIT(mpu6050,mpu6050_init,&iic_6050_api);