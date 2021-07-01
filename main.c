/*TODO:
 * 链接文件的使用
 * xip
 * 重定位
 * 把某段代码放在特定段里，然后使用段来引用
*/
#include "stdio.h"
#include "device.h"
#include "mpu6050_api.h"

void _sys_dev_init()
{
    struct device *info;
    for(info = __device_init_start; info != __device_init_end; info++){
        info->config->init(info);
    }
}

void main()
{
    _sys_dev_init();

    mpu6050_read_api(device_get_binding("mpu6050"));
    
}