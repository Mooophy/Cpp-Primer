# executable files for this directory
OBJECTS = buf.exe clearIO.exe fileIO.exe add_item.exe \
		  add_itemV2.exe sstream.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../7

add_itemV2.exe: add_itemV2.o ../7/Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) add_itemV2.o ../7/Sales_data.o \
		-o add_itemV2.exe

add_item.exe: add_item.o ../7/Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) add_item.o ../7/Sales_data.o \
		-o add_item.exe
 
