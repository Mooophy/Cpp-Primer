#cutable files for this directory
OBJECTS = ex14_35 ex14_36 ex14_37 ex14_38_39 ex14_40 ex14_42 ex14_43 ex14_44
OTHOBJS = ex14_02_TEST ex14_05_TEST ex14_07_TEST ex14_15_TEST ex14_22_TEST ex14_23_TEST ex14_45_TEST ex14_49_TEST ex14_27_28_StrBlobTest ex14_30_StrBlobTest \
		ex14_32 ex14_16_StrBlobTest ex14_16_StringMain ex14_16_StrVecMain \
		ex14_18_StrBlobTest ex14_18_StringMain ex14_18_StrVecMain \
		ex14_26_StrBlobTest ex14_26_StringMain ex14_26_StrVecMain ex14_24_TEST
# 
all:$(OBJECTS) $(OTHOBJS)


ex14_02_TEST : ex14_02_TEST.o ex14_02.o ex14_02.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_05_TEST : ex14_05_TEST.o ex14_05.o ex14_05.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_07_TEST : ex14_07_TEST.o ex14_07.o ex14_07.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_15_TEST : ex14_15_TEST.o ex14_15.o ex14_15.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_16_StrBlobTest : ex14_16_StrBlobTest.o ex14_16_StrBlob.o ex14_16_StrBlob.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_16_StringMain : ex14_16_StringMain.o ex14_16_String.o ex14_16_String.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_16_StrVecMain : ex14_16_StrVecMain.o ex14_16_StrVec.o ex14_16_StrVec.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_18_StrBlobTest : ex14_18_StrBlobTest.o ex14_18_StrBlob.o ex14_18_StrBlob.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_18_StringMain : ex14_18_StringMain.o ex14_18_String.o ex14_18_String.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_18_StrVecMain : ex14_18_StrVecMain.o ex14_18_StrVec.o ex14_18_StrVec.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_26_StrBlobTest : ex14_26_StrBlobTest.o ex14_26_StrBlob.o ex14_26_StrBlob.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_26_StringMain : ex14_26_StringMain.o ex14_26_String.o ex14_26_String.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_26_StrVecMain : ex14_26_StrVecMain.o ex14_26_StrVec.o ex14_26_StrVec.h 
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_22_TEST : ex14_22_TEST.o ex14_22.o ex14_22.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_23_TEST : ex14_23_TEST.o ex14_23.o ex14_23.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_24_TEST : ex14_24_TEST.o ex14_24.o ex14_24.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_32 : ex14_32.o  ex14_30_StrBlob.o ex14_32.h ex14_30_StrBlob.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_45_TEST : ex14_45_TEST.o ex14_45.o ex14_45.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_49_TEST : ex14_49_TEST.o ex14_49.o ex14_49.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_27_28_StrBlobTest : ex14_27_28_StrBlobTest.o ex14_27_28_StrBlob.o ex14_27_28_StrBlob.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^

ex14_30_StrBlobTest : ex14_30_StrBlobTest.o ex14_30_StrBlob.o ex14_30_StrBlob.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $^
	
# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template
