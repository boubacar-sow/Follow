#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Module_List-20211110/testListHelpers.h"
#include "hash.h"

#define MAX 100


int main() {
    s_node** table = create_table();
    char* var = word_insert(table, &hachage, "machin");
    word_insert(table, &hachage, "machni");
    word_insert(table, &hachage, "prog");
    word_insert(table, &hachage, "programmation");
    afficher_table(table);
    word_delete(table, &hachage, "monday");  
    word_delete(table, &hachage, "prog");  
    afficher_table(table);
   
    
    return EXIT_SUCCESS;
}