#include "list.h"

#include <stdio.h>
#include <stdlib.h>

#include "testListHelpers.h"

// creation d'une nouvelle liste vide
s_node *list_create(void) { return NULL; }

// lire la donnee d'un noeud
void *list_get_data(s_node *node) { return node->value; }

// ecrire la donnee d'un noeud
void list_set_data(s_node *node, void *data) {
    node->value = data;
}

// creation et insertion d'un noeud en tete de liste
//   retourne la tete de liste
s_node *list_insert(s_node *head, void *data) {
    s_node *tmp = (s_node *)malloc(sizeof(s_node));
    if (!tmp) return NULL;
    tmp->value = data;
    tmp->next = head;
    return tmp;
}

// creation et ajout d'un noeud en queue de liste
//   retourne la tete de liste
s_node *list_append(s_node *head, void *data) {
    s_node *tmp = head;
    if (head == NULL) {
        return list_insert(head, data);
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = list_insert(NULL, data);
    return head;
}

// ajout d'un noeud dans une liste ordonnee
// selon le resulat de "compare" ;
// si la donnee existe deja, elle n'est pas ajoutee

s_node *list_orderedAppend(s_node **head, int (*compare)(s_node *, void *),
                           void *data) {
    s_node *tmp = NULL;
    s_node *pt = *head;
    if ((*compare)(pt, data) == 0) {
        return pt;
    }
    while (pt && (*compare)(pt, data) == -1) {
        tmp = pt;
        pt = pt->next;
        if ((*compare)(pt, data) == 0) {
            return pt;
        }
    }
    s_node *elem = malloc(sizeof(s_node));
    if (!elem) exit(EXIT_FAILURE);
    elem->value = data;
    elem->next = pt;
    if (tmp) {
        tmp->next = elem;
        return elem;
    } else {
        *head = elem;
        return elem;
    }
}

// suppression de la premiere instance d'une
// donnee dans la liste, retourne la tete de liste
s_node *list_remove(s_node *head, void *data) {
    s_node *precedent = NULL, *courant = NULL;
    if (head == NULL) return NULL;
    if (head->value == data) {
        return head->next;
    }
    /*
    On considère que le cas de la tête de liste est traitée
    L'état courant est donc head->next et l'état précédent est head.
    */
    precedent = head;
    courant = head->next;
    while (precedent->next != NULL) {
        if (courant->value == data) {
            precedent->next = courant->next;
            free(courant);
            break;
        }
        precedent = courant;
        courant = courant->next;
    }
    return head;
}

// suppression de la tete de liste
// retourne la nouvelle tete de liste
s_node *list_headRemove(s_node *head) {
    if (head == NULL) return NULL;
    s_node *tmp = head->next;
    free(head);
    return tmp;
}

// destruction d'une liste
//  (La liberation des donnees n'est pas prise en charge)
void list_destroy(s_node *head) {
    s_node *tmp = head;
    while (head != NULL) {
        tmp = head->next;
        free(head);
        head = tmp;
    }
}