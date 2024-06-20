# executable files for this directory
OBJECTS = Array.exe array-parms4.exe \
		  compare.exe compareDef.exe compareSpec.exe \
		  debug.exe expansion.exe flip.exe multiset.exe \
		  overloaded.exe overSpec.exe qm.exe \
		  SP.exe special.exe specialized.exe \
		  trail-ret.exe typealias.exe \
		  useBlob.exe useChcking.exe \
		  variadic.exe variadic3.exe Vecmain.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = 

SP.o: DebugDelete.h

compareDef.o multiset.o variadic.o variadic3.o Sales_data.o: Sales_data.h

Vecmain.o: Vec.h

compareDef.exe: compareDef.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) compareDef.o Sales_data.o \
			-o compareDef.exe

variadic.exe: variadic.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) variadic.o Sales_data.o \
			-o variadic.exe

variadic3.exe: variadic3.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) variadic3.o Sales_data.o \
			-o variadic3.exe

multiset.exe: multiset.o Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) multiset.o Sales_data.o \
			-o multiset.exe

qm.exe: qm.o build.o 
	$(CC) $(CCFLAGS) $(LOCFLAGS) qm.o build.o -o qm.exe

specialized.exe: debug.cc
	$(CC) -D SPECIALIZED $(CCFLAGS) $(LOCFLAGS) debug.cc -o specialized.exe

overloaded.exe: debug.o
	$(CC) -D OVERCHAR $(CCFLAGS) $(LOCFLAGS) debug.cc -o overloaded.exe

debug.exe: debug.o
	$(CC) -D DEBUG $(CCFLAGS) $(LOCFLAGS) debug.cc -o debug.exe

