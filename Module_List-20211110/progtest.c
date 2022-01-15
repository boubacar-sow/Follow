#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "testListHelpers.h"
int compare_int(s_node *head, void *param) {
    if(head == NULL) return EXIT_FAILURE;
    int *tmp = (int *)param;
    int *head_val = (int *)head->value;
    if (*head_val == *tmp) {
        return 0;
    } else if (*head_val > *tmp)
        return 1;
    else
        return -1;
    return EXIT_FAILURE;
}
int main(int argc, char *argv[]) {
    char *chaine = "2 -> 3 -> 5 -> null";
    s_node *liste = list_create();
    int i = 5, j = 3, k = 2, l = 1, m = 0;
    char* list;
    /*Test de list_insert*/
    liste = list_insert(liste, &i);
    liste = list_insert(liste, &j);
    liste = list_insert(liste, &k);
    check_list_state(liste, &node_int_to_string, chaine);

    /*Test de liste remove*/
    chaine = "null";
    liste = list_remove(liste, &i);
    liste = list_remove(liste, &j);
    liste = list_remove(liste, &k);
    check_list_state(liste, &node_int_to_string, chaine);

    /*Test de list_insert_append*/
    chaine = "0 -> 2 -> 3 -> 5 -> null";
    list_orderedAppend(&liste, &compare_int, &i);
    list_orderedAppend(&liste, &compare_int, &j);
    list_orderedAppend(&liste, &compare_int, &k);
    list_orderedAppend(&liste, &compare_int, &m);  
    list_orderedAppend(&liste, &compare_int, &m);  
    check_list_state(liste, &node_int_to_string, chaine);

    /*Test de list_head_remove*/
    chaine = "2 -> 3 -> 5 -> null";
    liste = list_headRemove(liste);
    check_list_state(liste, &node_int_to_string, chaine);

    /*Destruction de la liste*/
    list_destroy(liste);
    return 0;
}