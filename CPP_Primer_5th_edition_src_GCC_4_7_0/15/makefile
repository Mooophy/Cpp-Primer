# executable files for this directory
OBJECTS = andQueryTest.exe and_orQueryTest.exe \
		  Basket_main.exe wordQueryTest.exe \
		  sample.exe scope.exe useQuote.exe \
		  vecBasket.exe virtualsNscope.exe

# tells make to use the file "../GNU_makefile_template", which
# defines general rules for making .o and .exe files
include ../GNU_makefile_template

LOCFLAGS = -I../12 -I../6

sample.o useQuote.o Quote.o: Quote.h
vecBasket.o Basket_main.o Basket.o: Basket.h Quote.h

get_print.o andQueryTest.o and_orQueryTest.o \
wordQueryTest.o Query.o: Query.h ../12/TextQuery.h

wordQueryTest.exe: Query.o wordQueryTest.o ../12/TextQuery.o get_print.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Query.o wordQueryTest.o \
		../12/TextQuery.o get_print.o -o wordQueryTest.exe

andQueryTest.exe: Query.o andQueryTest.o ../12/TextQuery.o get_print.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Query.o andQueryTest.o \
		../12/TextQuery.o get_print.o -o andQueryTest.exe

and_orQueryTest.exe: Query.o and_orQueryTest.o ../12/TextQuery.o get_print.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Query.o and_orQueryTest.o \
		../12/TextQuery.o get_print.o -o and_orQueryTest.exe

useQuote.exe: useQuote.o Quote.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) useQuote.o Quote.o -o useQuote.exe

vecBasket.exe: Basket.o vecBasket.o Quote.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) vecBasket.o Basket.o Quote.o \
			-o vecBasket.exe

Basket_main.exe: Basket.o Basket_main.o Quote.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) Basket_main.o Basket.o Quote.o \
			-o Basket_main.exe

sample.exe: sample.o Quote.o
	$(CC) $(CCFLAGS) $(LOCFLAGS) sample.o Quote.o -o sample.exe

