cc = gcc
CCFLAGS = -W -Wall -g

main : main.o plsc.o ../Module_List-20211110/list.o ../Module_Strhash/hash.o ../Module_Chargement_Analyse-20212511/fonc.o
	$(cc) -o main main.o plsc.o ../Module_Strhash/hash.o ../Module_List-20211110/list.o ../Module_Chargement_Analyse-20212511/fonc.o -lm
main.o : main.c plsc.h
	$(cc) $(CCFLAGS) -o main.o -c main.c 
plsc.o : plsc.c plsc.h 
	$(cc) $(CCFLAGS) -o plsc.o -c plsc.c 
../Module_Chargement_Analyse-20212511/fonc.o : ../Module_Chargement_Analyse-20212511/fonc.h ../Module_Chargement_Analyse-20212511/fonc.c
	$(cc) $(CCFLAGS) -o ../Module_Chargement_Analyse-20212511/fonc.o -c ../Module_Chargement_Analyse-20212511/fonc.c
../Module_Strhash/hash.o : ../Module_Strhash/hash.c ../Module_Strhash/hash.h
	$(cc) $(CCFLAGS) -o ../Module_Strhash/hash.o -c ../Module_Strhash/hash.c

../Module_List-20211110/list.o : ../Module_List-20211110/list.c ../Module_List-20211110/list.h
	$(cc) $(CCFLAGS) -o ../Module_List-20211110/list.o -c ../Module_List-20211110/list.c

clear : 
	rm -rf *.o