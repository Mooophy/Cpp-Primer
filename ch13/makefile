#cutable files for this directory
OBJECTS = ex13_13 ex13_17 ex13_58 \
		ex13_28 ex13_26 ex13_18 ex13_34_36_37 ex13_39 ex13_40 ex13_44_47 ex13_53
OTHOBJS = ex13_42 ex13_48
#	ex13_49_Message ex13_49_String ex13_49_StrVec 
all:$(OBJECTS) $(OTHOBJS)

ex13_42 : ex13_42.o ex13_42_TextQuery.o ex13_42_StrVec.o ex13_42_TextQuery.h ex13_42_StrVec.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex13_48 : ex13_44_47.cpp ex13_44_47.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template
