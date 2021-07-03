# 首先生成默认链接文件
# 给描述一下编译链接的过程
# ld --verbose > linker.ld
FILE = main.c device.c
FILE += mpu6050.c 
FILE += oled.c

CC = gcc -I lib
static_fw.out:$(FILE) linker.ld
	$(CC) $(FILE) -lsort -L lib -T linker.ld -o $@ -static

dyn_fw.out:$(FILE) linker.ld
	$(CC) $(FILE) -lsort -L lib -T linker.ld -o $@

clean:
	@rm -rf *.out

.PHONY = clean