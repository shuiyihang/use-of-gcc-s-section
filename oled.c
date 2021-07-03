/**
 * 模拟注册设备2
 * 
*/
#include "stdio.h"
#include "device.h"
#include "oled_api.h"

int oled_init(struct device *dev)
{
    printf("oled init\n");
    return 0;
}

void pixel_set(char x,char y, char color)
{
    printf("pos:(x:%d,y:%d) color:%d\t\n",x,y,color);
}

const oled_api_t  spi_oled_api = {
    .write = pixel_set,
};

DEVICE_AND_API_INIT(oled,oled_init,&spi_oled_api);