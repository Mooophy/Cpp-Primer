#cutable files for this directory
OBJECTS = ex8_02 ex8_04 ex8_05 ex8_09 ex8_10 ex8_11 \
	  #ex8_13
OTHOBJS = ex8_06 ex8_07 ex8_08 	
all:$(OBJECTS) $(OTHOBJS)

ex8_06 : ex8_06.o ../ch07/ex7_26.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^
ex8_07 : ex8_07.o ../ch07/ex7_26.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^
ex8_08 : ex8_08.o ../ch07/ex7_26.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^
# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template

