# 首先生成默认链接文件
# 给描述一下编译链接的过程
# ld --verbose > linker.ld
FILE = main.c
FILE += mpu6050.c device.c
fw.out:$(FILE)
	gcc $^ -T linker.ld -o $@

clean:
	@rm -rf *.out

.PHONY = clean