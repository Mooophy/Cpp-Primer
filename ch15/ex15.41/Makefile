# 每增加一个.c文件，就可以make自动化生成
# 对应的可执行文件。

CC = g++
CFLAGS = -g -std=c++0x -Wall

#将所有的.c文件去掉后缀，作为所目标文件
#的文件名。
objects = $(subst .cc,,$(wildcard *.cc))

#为了使每一个目标文件都有一个生成规则，
#定义伪目标，伪目标的依赖文件为上面所
#得到的目标文件名。
.PHONY:all
all:$(objects)

#目标文件依赖于对应的.c文件，使用静态
#模式设定，并用自动化变量展开。
$(objects):%:%.cc TextQuery.h QueryResult.h QueryBase.h WordQuery.h NotQuery.h BinaryQuery.h AndQuery.h OrQuery.h Query.h
	$(CC) $(CFLAGS) -o $@ $< 

.PHONY:clean
clean:
	rm $(objects)
