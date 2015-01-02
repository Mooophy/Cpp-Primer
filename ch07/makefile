#cutable files for this directory
OBJECTS = ex7_01 ex7_03 ex7_07 ex7_11 ex7_13 ex7_27_TEST \
		  ex7_43 
#	
OTHOBJS = ex7_41_TEST ex7_26.o  

all: $(OBJECTS) $(OTHOBJS)
	
ex7_41_TEST:ex7_41_TEST.o ex7_41.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ ex7_41_TEST.o ex7_41.o

ex7_26.o:ex7_26.cpp
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ -c $<
# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template

