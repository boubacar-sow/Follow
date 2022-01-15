#ifndef _FONC_H_
#define _FONC_H_
#include "../Module_List-20211110/list.h"
#include <stdio.h>
/*Définition d'un type token*/
typedef struct {
    enum { WORD, SHORT_SPACE, SPACE, ERASE, INSERT, REPLACE, EMPTY } type;
    int textOffset;
    union {
        char* word;
        char space[4];
    } data;
} token;

/** Fonction qui calcule
* et retourne la taille d'un fichier
**/
int taille_fichier(FILE* f);



/*Fonction qui charge deux textes dans 2 chaines de caractères*/
void charger_texte(char*, char*, char**,
                   char**);


/*Fonction qui analyse un texte et le découpe en tokens(jetons)
*Les jetons sont rangés dans un tableau de token qui est retourné
*par la fonction.
*/
token* decouper(char*, s_node**);
#endif
