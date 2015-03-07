# executable files for this directory
OBJECTS = ex12_06 ex12_07 ex12_10 ex12_11 ex12_12 ex12_13 ex12_14 ex12_15 \
		ex12_16 ex12_17_18 ex12_22 ex12_23 ex12_24 ex12_26 ex12_28 ex12_32 ex12_33
OTHOBJS = ex12_20 ex12_27_30_TEST

all:$(OBJECTS) $(OTHOBJS)

ex12_20: ex12_20.o ex12_19.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $^	-o $@

ex12_27_30_TEST: ex12_27_30_TEST.o ex12_27_30.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) $^ -o $@

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template
