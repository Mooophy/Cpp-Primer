#cutable files for this directory
OBJECTS = ex7_01 ex7_03 ex7_07 ex7_11 ex7_13 ex7_27_TEST \
		  ex7_43 	
OTHOBJS = ex7_41_TEST  

all: $(OBJECTS) $(OTHOBJS)
	
ex7_41_TEST:ex7_41_TEST.o ex7_41.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ ex7_41_TEST.o ex7_41.o

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template

