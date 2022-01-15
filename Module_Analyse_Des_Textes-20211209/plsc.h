#ifndef _PLSC_H_
#define _PLSC_H_
// Détermine le maximum entre deux nombres
int max(int, int);

// Fonction qui calcule la longueur de la plus longue sous séquence commune
int** lg(int, int, token*, token*);

// Fonction qui construit la plus longue sous séquence commune à l'aide d'un
// matrice
token* construct_plsc(int**, char* , char* );
#endif