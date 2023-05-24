# executable files for this directory
OBJECTS = arrRet.exe count-calls.exe errMsg_initList.exe\
		  fact.exe fcnptrRet.exe good_printmain.exe \
		  inline_shorter.exe mainmath.exe mainret.exe \
		  mk_plural.exe ref-fcn.exe refparms.exe refret-ex.exe  \
		  reset.exe stl-arr-fcns.exe usefcnptr.exe wdebug.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = 

fact.o mainmath.o LocalMath.o: LocalMath.h

fact.exe: fact.o LocalMath.o
	$(CC) $(CCFLAGS) fact.o LocalMath.o -o fact.exe

mainmath.exe: mainmath.o LocalMath.o 
	$(CC) $(CCFLAGS) mainmath.o LocalMath.o -o mainmath.exe

