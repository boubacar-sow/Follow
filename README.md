# UBO-Projet-Follow
Création d'un petit logiciel de traitement de texte avec interface graphique en C. Le logiciel compare deux textes afin de trouver les différences entre les deux textes.

Le projet est divisé en 6 modules:
Module Liste chainée: 
  Implémentation d'une liste chainée en C avec toutes ses fonctionnalités:
    -Création de la liste.
    -Insérer un noeud en tête de liste.
    -Inserer un noeud en fin de liste.
    -Insertion ordonnée d'un noeud dans la liste.
    -Suppression de la tête de liste.
    -Suppression d'un noeud quelconque dans la liste.
    -Destruction de la liste chainée(La libération des données n'est pas prise en charge).

Module table de hachage:
  Implémentation d'une table de hachage qui est chargée d'accueillir les données de la liste chainée.
  Elle intègre les fonctionnalités suivantes:
    -Création de la table de hachage.
    -Insérer une donnée dans la table.
    -Supression d'une donnée de la table.
    -Libération des données de la table de hachage.
    -Destruction de la table de hachage.
    
Module chargement et analyse des textes:
  Chargement des deux textes à analyser(fichiers) dans des chaines de caractères. Les chaines seront       découpées en token.
  
Module Analyse des deux textes:
  Analyse des deux textes pour en tirer les différences. On s'appuie sur l'algorithme de recherche de   la plus longue sous chaine commune. On trouve donc les mots qui ont été soient remplacés, insérés     ou supprimés.
  
Module Création de l'interface graphique:
  Création de l'interface graphique à l'aide de l'utilitaire Glade(GTK).
  
Module Intégration:
  Intégration de l'ensemble du logiciel.
  
  

    
