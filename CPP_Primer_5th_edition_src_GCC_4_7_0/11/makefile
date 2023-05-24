# executable files for this directory
OBJECTS = erasemap.exe map1.exe \
		  multimap.exe pair.exe \
		  restricted_count.exe setOps.exe \
		  unorderedWordCount.exe wcEx.exe \
		  word_count.exe word_transform.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

# directory 7 has Sales_data code, 6 has make_plural function
LOCFLAGS = -I../7 -I../6

map1.exe: map1.o ../7/Sales_data.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) map1.o ../7/Sales_data.o -o map1.exe

