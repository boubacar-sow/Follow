#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fonc.h"

void check_chargement(char* t1, char* t2) {
    printf("Texte 1: \n%s\n", t1);
    printf("Texte 2: \n%s\n", t2);
    if (strcmp(t1, t2) == 0)
        printf("Les deux textes sont égaux\n");
    else
        printf("Les textes ne sont pas égaux\n");
}

