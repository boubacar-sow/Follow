#include "fonc.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Module_List-20211110/list.h"
#include "../Module_List-20211110/testListHelpers.h"
#include "../Module_Strhash/hash.h"

//Fonction qui trouve la taille d'un fichier
int taille_fichier(FILE* f) {
    if (f == NULL) return EXIT_FAILURE;
    fseek(f, 0, SEEK_END);//Déplacement du curseur en fin de fichier
    int size = ftell(f);//Récuperation de la taille
    fseek(f, 0, SEEK_SET);//Remise à 0 du décalage
    return size;
}
/*Fonction qui charge deux textes dans 2 chaines de caractères*/
void charger_texte(char* nom_texte1, char* nom_texte2, char** dest1,
                   char** dest2) {
    FILE* fic1;
    FILE* fic2;
    fic1 = fopen(nom_texte1, "r");
    fic2 = fopen(nom_texte2, "r");
    if (!fic1 || !fic2) {
        fprintf(stderr, "Erreur lors du malloc");
        return;
    }
    *dest1 = malloc(sizeof(char) * taille_fichier(fic1));
    *dest2 = malloc(sizeof(char) * taille_fichier(fic2));
    if (*dest1 == NULL || *dest2 == NULL) {
        fprintf(stderr, "Erreur lors du malloc");
        return;
    }
    fread(*dest1, 1, taille_fichier(fic1), fic1);
    fread(*dest2, 1, taille_fichier(fic2), fic2);
}

/*Fonction qui analyse un texte et le découpe en tokens(jetons)
*Les jetons sont rangés dans un tableau de token qui est retourné
*par la fonction.
*/
token* decouper(char* texte, s_node** table) {
    token* all_token =
        malloc(sizeof(token) * 10);  // Tableau stockant les jetons
    if (!all_token) return NULL;
    int taille = 0;  // Taille du tableau de jetons
    char* tmp = texte;
    char* pt;
    int offset = 0;  // valeur du décalage
    int i, j = 0;
    while (*tmp != '\0' && tmp != NULL) { //Tant la chaine n'est pas nulle et qu'on ne rencontre pas le caractère de fin de chaine
        char* mot = NULL;
        i = 0;
        pt = tmp;
        if (*pt != ' ' && *pt != '\n') {//Détection du début d'un mot
            while (*pt != ' ' && *pt != '\n' && *pt != '\0') {//Le pointeur se déplace tant qu'on est dans un mot
                pt++;
                i++; //Comptage du nombre de lettres constituant le mot
            }
            all_token[j].type = WORD;//Définition du type du mot 
            all_token[j].data.word = malloc(sizeof(char) * i);
            if (!all_token[j].data.word) return NULL;
            mot = malloc(sizeof(char) * i);
            strncpy(mot, tmp, i);//On copie dans "mot" à l'aide du compteur i les i-caractères constituant un mot avec strncpy
            mot[i] = '\0';
            all_token[j].data.word = word_insert(table, &hachage, mot); //Insertion du mot dans la table de hachage et stockage du mot dans la table des jetons.

        } else if (*pt == ' ') {//Si le pointeur pointe sur un espace
            while (*pt == ' ' && *pt != '\0') {//On continue tant qu'il pointe sur un espace et on compte les occurences
                pt++;
                i++;//comptage du nombre d'espaces
            }
            if (i >= 4) {//Si on a plus de 4 espaces successifs
                all_token[j].type = SPACE;
                all_token[j].data.word = malloc(sizeof(char) * i);
                if (!all_token[j].data.word) return NULL;
                mot = malloc(sizeof(char) * i);
                strncpy(mot, tmp, i);
                all_token[j].data.word = word_insert(table, &hachage, mot);
                all_token[j].data.word[i] = '\0';
            } else {
                //Sinon on a un court espace
                all_token[j].type = SHORT_SPACE;
                strncpy(all_token[j].data.space, tmp, i);
                all_token[j].data.space[i] = '\0';
            }
        } else {
            //Si on a des retours à la ligne ou des tabulations
            while (*pt == '\n' && *pt == '\t') {
                pt++;
                i++;
            }
        }
        all_token[j].textOffset = offset; //Mise à jour de l'offset
        offset += i + 1;
        tmp = tmp + i;
        j++;
        taille++;
        //Allocation dynamique du tableau par bloc de 10
        if (taille % 10 == 0)
            all_token = realloc(all_token, sizeof(token) * (taille + 10));
        if (!all_token) return NULL;
    }
    return all_token;
}
