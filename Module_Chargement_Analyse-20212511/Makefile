cc = gcc
CCFLAGS = -W -Wall -g

main : main.o ../Module_List-20211110/list.o ../Module_Strhash/hash.o fonc.o testfonc.o
	$(cc) -o main main.o ../Module_Strhash/hash.o ../Module_List-20211110/list.o fonc.o testfonc.o -lm
main.o : main.c fonc.h testfonc.h
	$(cc) $(CCFLAGS) -o main.o -c main.c 
fonc.o : fonc.h fonc.c
	$(cc) $(CCFLAGS) -o fonc.o -c fonc.c
testfonc.o : testfonc.h testfonc.c
	$(cc) $(CCFLAGS) -o testfonc.o -c testfonc.c
../Module_Strhash/hash.o : ../Module_Strhash/hash.c ../Module_Strhash/hash.h
	$(cc) $(CCFLAGS) -o ../Module_Strhash/hash.o -c ../Module_Strhash/hash.c

../Module_List-20211110/list.o : ../Module_List-20211110/list.c ../Module_List-20211110/list.h
	$(cc) $(CCFLAGS) -o ../Module_List-20211110/list.o -c ../Module_List-20211110/list.c

clear : 
	rm -rf *.o