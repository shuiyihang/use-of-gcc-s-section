#ifndef __OLED_API_H__
#define __OLED_API_H__

#include "device.h"
typedef struct oled_api
{
    void (*write)(char x,char y,char color);
}oled_api_t;


static inline void oled_setPixel_api(struct device *dev,char x,char y,char color)
{
    const struct oled_api  *api = dev->driver_api;
    return api->write(x,y,color);
}


#endif