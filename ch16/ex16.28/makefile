OBJS = main.cpp
CC = g++ 
CFLAGS = -g --std=c++11
out: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY:
	clean
clean:
	rm out *.o *.gch
