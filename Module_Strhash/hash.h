#if !defined(_HASH_H_)
#define _HASH_H_
#include "../Module_List-20211110/list.h"
int nombreEntreeListe(s_node* noeud);
//Calcul le nombre d'entrée dans la liste

int hachage(char*);
/*Fonction qui se charge de hacher un mot*/

int compare_string(s_node *head, void *param);
/*Fonction qui compare deux chaines de caractères*/

s_node** create_table();
/*Création d'une table de hachage*/

char* search_table(s_node**, int (*hachage)(char*), char*);
/*Recherche d'un mot dans une table de hachage*/

void destruct_table(s_node**);
/*Destruction d'une table de hashage*/

s_node** liberer_table(s_node**);
/*Libération des données enregistrées dans une table de hachage*/

char* word_insert(s_node**, int (*hachage)(char*), char*);
/*Ajout d'un mot dans la table*/

void word_delete(s_node**, int (*hachage)(char*), char*);
/*Suppression d'un mot dans la table*/

void stats_table(s_node**, int (*function)(s_node*));
/*Affichage de données statistiques sur la table de hachage*/
int nombreEntreeListe(s_node* noeud);
void afficher_table(s_node**);
#endif  // _HASH_H_

