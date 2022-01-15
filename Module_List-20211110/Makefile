CCFLAGS = -Wall -w
cc = gcc
progtest: progtest.o list.o testlistHelpers.o
	$(cc) -o progtest progtest.o list.o testlistHelpers.o
progtest.o : progtest.c 
	$(cc) $(CCFLAGS) -o progtest.o -c progtest.c
list.o: list.c list.h
	$(cc) $(CCFLAGS) -o list.o -c list.c 
testlistHelpers.o : testlistHelpers.c testlistHelpers.h 
	$(cc) -o testlistHelpers.o -c testlistHelpers.c 
clear :
	rm -rf *.o
