#cutable files for this directory
OBJECTS = 13.6.7.8 ex13.14.15.16 ex13.18.19 ex13.20.21.22 ex13.27 ex13.29.30.31.32 ex13.51 \
	ex13.5 ex13.7.8 ex13.9.10.11.13
OTHOBJS = ex13.25.26/main ex13.55/main ex13.56.57.58/main 
all:$(OBJECTS) $(OTHOBJS)

ex13.25.26/main : ex13.25.26/main.cpp  ex13.25.26/StrBlob.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13.55/main : ex13.55/main.cpp ex13.55/StrBlob.h ex13.55/Alan.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

ex13.56.57.58/main : ex13.56.57.58/main.cpp ex13.56.57.58/StrBlob.h ex13.56.57.58/Alan.h
	$(CC) $(CCFLAGS) $(LOCFLAGS) -o $@ $<

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and  files
include ../GNU_makefile_template
