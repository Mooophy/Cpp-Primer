#cutable files for this directory
OBJECTS = ex17_10 ex17_11_12_13 ex17_1_2 ex17_14_15_16 ex17_17_18 \
	ex17_19_20 ex17_28_29_30 ex17_21 ex17_9 ex17_23 ex17_33 
OTHOBJS = ex17_4_5_6_7_8 
#ex17_3 ex17_3_TextQuery.cpp 

ex17_4_5_6_7_8 : ex17_4_5_6_7_8.o ex17_4_5_6_7_8_SalesData.o 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

#ex17_3 :  ex17_3.o ex17_3_TextQuery.o ex17_3_TextQuery.h
#	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

# 
all:$(OBJECTS) $(OTHOBJS)

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template
