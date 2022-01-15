#include <stdlib.h>
#include <stdio.h>
#include "fonc.h"
#include "../Module_Strhash/hash.h"
#include "testfonc.h"
int main() {
    char* t1 = NULL, *t2 = NULL;
    charger_texte("ref.txt", "text2.txt", &t1, &t2);
    char* texte = "But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful. Nor again is there anyone who loves or pursues or desires to obtain pain of itself, because it is pain, but because occasionally circumstances occur in which toil and pain can procure him some great pleasure. To take a trivial example, which of us ever undertakes laborious physical exercise, except to obtain some advantage from it? But who has any right to find fault with a man who chooses to enjoy a pleasure that has no annoying consequences, or one who avoids a pain that produces no resultant pleasure?"; //contenu de ref.txt
    char* texte2 = "Bonjour Mesdames.";
    check_chargement(texte, t1);
    check_chargement(texte2, t2);
    s_node** table_hash = create_table();
    decouper(t1, table_hash);
    decouper(t2, table_hash);
    afficher_table(table_hash);
    stats_table(table_hash, &nombreEntreeListe);
    return 0;
}