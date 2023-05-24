# executable files for this directory
OBJECTS = FolderMain.exe HasPtrUseCount.exe \
		  HasPtrValueLike.exe copyNoMove.exe \
		  moveHP.exe serial.exe StrFolderMain.exe \
		  useStrVec.exe substr.exe 

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../1 -I../7

Folder.o FolderMain.o: Folder.h
StrFolder.o StrFolderMain.o: StrFolder.h String.h
String.o: String.h
useStrVec.o StrVec.o: String.h StrVec.h

useStrVec.exe: StrVec.o useStrVec.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) StrVec.o useStrVec.o -o useStrVec.exe

FolderMain.exe: Folder.o FolderMain.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Folder.o FolderMain.o -o FolderMain.exe

StrFolderMain.exe: StrFolder.o StrFolderMain.o String.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) StrFolder.o StrFolderMain.o String.o \
		-o StrFolderMain.exe

