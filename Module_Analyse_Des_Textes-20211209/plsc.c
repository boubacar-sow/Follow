#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Module_Chargement_Analyse-20212511/fonc.h"
#include "../Module_Chargement_Analyse-20212511/testfonc.h"
#include "../Module_List-20211110/list.h"
#include "../Module_List-20211110/testListHelpers.h"
#include "../Module_Strhash/hash.h"
// Détermine le maximum entre deux nombres
int max(int a, int b) { return (a > b ? a : b); }

// Fonction qui calcule la longueur de la plus longue sous séquence commune
int** lg(int i, int j, token* jetons_chaine1, token* jetons_chaine2) {
    s_node** table = create_table();
    int** mat = malloc(sizeof(int*) * (i + 1));
    for (int k = 0; k <= i; ++k) *(mat + k) = malloc(sizeof(int) * (j + 1));
    if (!mat) return NULL;
    int m = 0, n = 0;
    for (m = 0; m <= i; ++m) {
        printf("ligne %d: ", m);
        for (n = 0; n <= j; ++n) {
            if (m == 0 || n == 0)
                mat[m][n] = 0;
            else {
                if (jetons_chaine1[m - 1].type == SHORT_SPACE ||
                    jetons_chaine2[n - 1].type == SHORT_SPACE) {
                } else {
                    if (jetons_chaine1[m - 1].data.word ==
                        jetons_chaine2[n - 1].data.word)
                        mat[m][n] = 1 + mat[m - 1][n - 1];
                    else
                        mat[m][n] = max(mat[m][n - 1], mat[m - 1][n]);
                }
            }
            printf("%d   ", mat[m][n]);
        }
        printf("\n");
    }
    return mat;
}
// Fonction qui construit la plus longue sous séquence commune à l'aide d'un
// matrice
token* construct_plsc(int** mat, char* chaine1, char* chaine2) {
    s_node** table = create_table();

    token* jetons = malloc(sizeof(token) * 100);
    if (!jetons) return NULL;
    token* jetons_chaine1 = decouper(chaine1, table);
    token* jetons_chaine2 = decouper(chaine2, table);

    int i = 0, j = 0, k = 0;
    token* tmp1 = jetons_chaine1;
    token* tmp2 = jetons_chaine2;
    while (k < 17) {
        if (tmp1[k].type != SHORT_SPACE) i++;
        k++;
    }
    k = 0;
    while (k < 23) {
        if (tmp2[k].type != SHORT_SPACE) j++;
        k++;
    }
    mat = lg(i, j, jetons_chaine1, jetons_chaine2);
    int m = 1;
    while (i >= 0 && j >= 0) {
        if (jetons_chaine1[i].data.word == jetons_chaine2[j].data.word ||
            mat[i - 1][j - 1] >= mat[i][j - 1] ||
            mat[i - 1][j - 1] >= mat[i - 1][j]) {
            jetons[m].type = REPLACE;
            jetons[m].data.word = strdup(jetons_chaine1[m - 1].data.word);
            i--, j--;
        } else if (mat[i - 1][j] >= mat[i][j - 1]) {
            jetons[m].type = INSERT;
            jetons[m].data.word = strdup(jetons_chaine2[m - 1].data.word);
            i--;
        } else {
            jetons[m].type = ERASE;
            jetons[m].data.word = strdup(jetons_chaine1[m - 1].data.word);
            j--;
        }
        m++;
    }
    afficher_table(table);
    return jetons;
}
