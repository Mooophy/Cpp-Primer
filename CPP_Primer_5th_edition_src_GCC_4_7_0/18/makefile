# executable files for this directory
OBJECTS = Animal.exe book.exe class.exe \
		  ex-over.exe inherit.exe mi-scope.exe\
		  over.exe over2.exe spec.exe \
		  usingDirective.exe virt-inherit.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../16

Animal.o: Animal.h
book.o: ../16/Sales_data.h bookexcept.h
virt-inherit.o: Animal_virtual_baseVers.h

book.exe: book.o bookexcept.h Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) book.o Sales_data.o -o book.exe
