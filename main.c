/*TODO:
 * 链接文件,内联汇编,静态动态库的使用
 * 模拟嵌入式里一些RTOS的初始化流程
 * xip
 * 重定位
 * 把某段代码放在特定段里，然后使用段来引用
*/
#include "stdio.h"
#include "device.h"
#include "mpu6050_api.h"
#include "oled_api.h"
#include "sort.h"

void _sys_dev_init()
{
    struct device *info;
    for(info = __device_init_start; info != __device_init_end; info++){
        info->config->init(info);
    }
}

void sort_test()
{
    int a[]={10,6,9,2,1,8,7};
    QuickSort(a,0,6);
    for(int i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}

void fake_main(void)
{
    char cs;
    struct device *dev;
    mpu6050_read_api(device_get_binding("mpu6050"));

    dev = device_get_binding("oled");
    oled_setPixel_api(dev,0,8,1);
    oled_setPixel_api(dev,10,40,0);
    oled_setPixel_api(dev,10,15,1);
    sort_test();
    while(1){
        cs = getchar();
        if(cs == 'q'){
            break;
        }

    }
    
}

void main()
{
    // 在操作系统中放在还没有main之前完成驱动的初始化
    _sys_dev_init();

    __asm__ __volatile__(
        "call *%0 \t\n"
        :
        : "r"(fake_main)
    );

}