# executable files for this directory
OBJECTS = add_item.exe avg_price.exe \
		  useAccount.exe useDebug.exe useScreen.exe 

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../1

useScreen.exe: Screen.h

Account.o useAccount.o: Account.h
Debug.o useDebug.o: Debug.h

useAccount.exe: Account.o useAccount.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Account.o useAccount.o \
		-o useAccount.exe

useDebug.exe: Debug.o useDebug.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Debug.o useDebug.o -o useDebug.exe

add_item.exe: add_item.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) add_item.o Sales_data.o \
		-o add_item.exe

avg_price.exe: avg_price.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) avg_price.o Sales_data.o \
		-o avg_price.exe
 
