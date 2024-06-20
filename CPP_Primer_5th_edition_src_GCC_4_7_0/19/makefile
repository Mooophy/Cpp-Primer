# executable files for this directory
OBJECTS = bitfields.exe calc.exe dyn_cast.exe enum.exe enum-match.exe \
		  memFN-bind.exe tok2.exe typeid.exe useScreen.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../14

Screen.o useScreen.o: Screen.h

useScreen.exe: useScreen.o Screen.o 
	$(CC) $(CCFLAGS) useScreen.o Screen.o -o useScreen.exe

