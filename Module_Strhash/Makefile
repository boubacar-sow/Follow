cc = gcc
CCFLAGS = -W -Wall

main : main.o hash.o ../Module_List-20211110/list.o
	$(cc) -o main main.o hash.o ../Module_List-20211110/list.o -lm
main.o : main.c
	$(cc) $(CCFLAGS) -o main.o -c main.c 

hash.o : hash.c hash.h 
	$(cc) $(CCFLAGS) -o hash.o -c hash.c -lm

../Module_List-20211110/list.o : ../Module_List-20211110/list.c ../Module_List-20211110/list.h
	$(cc) $(CCFLAGS) -o ../Module_List-20211110/list.o -c ../Module_List-20211110/list.c

clear : 
	rm -rf *.o