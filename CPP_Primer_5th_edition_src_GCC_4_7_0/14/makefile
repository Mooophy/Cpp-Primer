# executable files for this directory
OBJECTS = absInt.exe add.exe calc.exe directcall.exe \
		  fcnobj.exe newcount-size.exe readStr.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../1 -I../6

add.o directcall.o Sales_data.o: Sales_data.h

add.exe: add.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) add.o Sales_data.o -o add.exe

directcall.exe: directcall.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) directcall.o Sales_data.o -o directcall.exe
