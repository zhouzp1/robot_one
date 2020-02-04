target = it
#由于 .c文件在不同的文件下，那么匹配模式 要匹配不同文件下的%.c文件

SRC_PATH = ./
DIRS = $(shell find $(SRC_PATH) -maxdepth 3 -type d)

src1 = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.c))
src2 = $(wildcard ./*.c)
obj1 = $(patsubst %.c,%.o,$(src1))
obj2 = $(patsubst %.c,%.o,$(src2))
src = ./file/

$(target):$(obj1) $(obj2)
	gcc $^ -o $@ -lm
#	gcc $(obj) -o $(target)
#编译 src下的.c文件 为.o文件
%.o:$(src)%.c
	gcc -c -ggdb $< -o $@
#编译 当前文件下的main.c文件
%.o:%.c
	gcc -c $< -o $@
.PHONY:clean #防止 外面有clean文件 阻止执行clean
clean:
	#-mkdir /root/aaa  #在命令前添加 - 当前命令出错，仍然可以往后面执行
	-rm $(target) $(obj1) $(obj2) -f
hello:
	echo "hello world"
