CC = g++
CFLAGS = -g -std=c++0x -Wall

objects = $(subst .cc,,$(wildcard *.cc))
.PHONY:all
all:$(objects)

$(objects):%:%.cc TextQuery.h QueryResult.h QueryBase.h WordQuery.h NotQuery.h AndQuery.h OrQuery.h Query.h  
	$(CC) $(CFLAGS) -o $@ $< 

.PHONY:clean
clean:
	rm $(objects)
