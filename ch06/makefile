#cutable files for this directory
OBJECTS = ex6_10 ex6_11 ex6_12 ex6_17 ex6_21 ex6_22 ex6_23 ex6_25_26 \
		  ex6_27 ex6_33 ex6_33_generics_version ex6_42 ex6_44 ex6_47 \
		  ex6_54_55_56 ex6_51 
OTHOBJS = factMain

all:$(OBJECTS) $(OTHOBJS)

factMain: factMain.o fact.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ factMain.o fact.o

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template

