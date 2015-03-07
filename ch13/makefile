#cutable files for this directory
OBJECTS = ex13_13 ex13_17 ex13_58 
OTHOBJS = ex13_42 
#	ex13_48 : can not compile successfully!
#	ex13_28 ex13_26 ex13_18 ex13_34_36_37 ex13_44_47 ex13_53 : no main function!  
#	ex13_42_StrVec ex13_49_Message ex13_49_String ex13_49_StrVec : no main function! 
#	ex13_39 ex13_40 : no StrVec.h and correspending header file is useless! 
all:$(OBJECTS) $(OTHOBJS)

#list the header file after cpp file to show the dependency!
ex13_18 : ex13_18.cpp ex13_18.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_26 : ex13_26.cpp ex13_26.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_28 : ex13_28.cpp ex13_28.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_34_36_37 : ex13_34_36_37.cpp ex13_34_36_37.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_39 : ex13_39.cpp ex13_39.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_40 : ex13_40.cpp ex13_40.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_42 : ex13_42.o ex13_42_TextQuery.o ex13_42_StrVec.o ex13_42_TextQuery.h ex13_42_StrVec.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex13_44_47 : ex13_44_47.cpp ex13_44_47.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_48 : ex13_48.cpp ex13_44_47.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13_53 : ex13_53.cpp ex13_53.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<
# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template
