#include "hash.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../Module_List-20211110/testListHelpers.h"

#define MAX 100000

int compare_string(s_node *head, void *param) {
    if(head == NULL) return EXIT_FAILURE;
    char *tmp = (char *)param;
    char *head_val = (char *)head->value;
    if (strcmp(head_val,tmp) == 0) {
        return 0;
    }else if (strcmp(head_val,tmp) > 0)
         return 1;
    else
        return -1;
    return EXIT_FAILURE;
}
/*Fonction qui se charge de hasher un mot*/
int hachage(char* word) {
    int cle = 0;
    size_t i = 0;
    while (i < strlen(word)) {
        cle = cle * 2 + (int)*(word + i);
        i++;
    }
    cle = cle % MAX;
    return cle;
}

/*Création d'une table de hashage*/
s_node** create_table() {
    s_node** table_hash = malloc(sizeof(s_node*) * MAX);
    if (!table_hash) {
        return NULL;
    }
    for (int i = 0; i < MAX; i++) {
        *(table_hash + i) = list_create();
    }
    return table_hash;
}

/*Recherche d'un mot dans une table de hachage*/
char* search_table(s_node** table_hash, int (*hachage)(char*), char* word) {
    int n = (*hachage)(word);
    s_node* tmp = *(table_hash + n);//table_hash[n]
    while (tmp) {
        char* mot = (char*)tmp->value;
        if (strcmp(mot,word) == 0) {
            return word;
        }
        tmp = tmp -> next;
        }
    return NULL;
}

/*Destruction d'une table de hashage*/
void destruct_table(s_node** table_hash) {
    for (int i = 0; i < MAX; ++i) {
        list_destroy(*(table_hash + i));
    }
    free(table_hash);
}

/*Libération des données enregistrées dans une table de hashage*/
s_node** liberer_table(s_node** table_hash) {
    for (int i = 0; i < MAX; ++i) {
        s_node* tmp = *(table_hash + i);
        while (tmp) {
            list_set_data(tmp, NULL);
            tmp = tmp->next;
        }
    }
    return table_hash;
}

/*Ajout d'un mot dans la table */
char* word_insert(s_node** table_hash, int (*hachage)(char*), char* word) {
    char* cp = strdup(word);
    int n = (*hachage)(word);
    s_node* noeud;
    noeud = list_orderedAppend((table_hash + n), &compare_string, cp);
    return (char*)noeud->value;
}

/*Suppression d'un mot dans la table */
void word_delete(s_node** table_hash, int (*hachage)(char*), char* word) {
    int n = (*hachage)(word);
    *(table_hash + n) = list_remove(*(table_hash + n), word);
}

int nombreEntreeListe(s_node* noeud) {
    int count = 0;
    while (noeud) {
        count++;
        noeud = noeud->next;
    }
    return count;
}
void stats_table(s_node** table_hash, int (*(nombreEntreeListe))(s_node*)) {
    int count = 0, minEntree = MAX, maxEntree = 0, ecartType = 0;
    for (int i = 0; i < MAX; i++) {
        if (*(table_hash + i) != NULL) {
            s_node* tmp = *(table_hash + i);
            while (tmp != NULL) {
                count++;
                tmp = tmp->next;
            }
        };
    }
    for (int i = 0; i < MAX; ++i) {
        if (minEntree > (*nombreEntreeListe)(*(table_hash + i)))
            minEntree = (*nombreEntreeListe)(*(table_hash + i));
        if (maxEntree < (*nombreEntreeListe)(*(table_hash + i)))
            maxEntree = (*nombreEntreeListe)(*(table_hash + i));
    }
    ecartType = sqrt((maxEntree - minEntree)/count);
    printf("===================Statistiques de la table=====================\n");
    printf("Nombre total d'éléments de la table: %d\n", count);
    printf("Nombre minimum d'éntrée de la table: %d\n", minEntree);
    printf("Nombre maximum d'entrée de la table: %d\n", maxEntree);
    printf("Ecart type: %d\n", ecartType);
    printf("=================================================================\n\n");

}

void afficher_table(s_node** table_hash) {
    printf("================Affichage de la table de hachage================\n");
    for (int i = 0; i < MAX; ++i) {
        if (*(table_hash + i) != NULL) {
            s_node* tmp = *(table_hash + i);
            while (tmp != NULL) {
                printf("%s->", (char*)tmp->value);
                tmp = tmp->next;
            }
            printf("null\n");
        }
    }
    printf("=================================================================\n\n");
}