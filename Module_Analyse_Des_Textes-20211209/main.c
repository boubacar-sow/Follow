#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Module_List-20211110/list.h"
#include "../Module_List-20211110/testListHelpers.h"
#include "../Module_Strhash/hash.h"
#include "../Module_Chargement_Analyse-20212511/fonc.h"
#include "../Module_Chargement_Analyse-20212511/testfonc.h"
#include "plsc.h"
int main() {
    char* chaine1 = "Bonjour monsieur";
    char* chaine2 = "Bonjour monsieur Daniel";
    int** mat = NULL;
    token* jetons = construct_plsc(mat, chaine1, chaine2);
    return 0;
}