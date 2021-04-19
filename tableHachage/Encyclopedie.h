//
//  encyclopedie.h
//  Table_hachage
//
//  Created by Alexandre Lebas on 15/11/2018.
//  Copyright © 2018 Alexandre Lebas. All rights reserved.
//

#ifndef Encyclopedie_h
#define Encyclopedie_h

#define TAILLE 50
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TAILLE_ID 12

//----------------------------------------------------------
//Nom de la structure : EcyclopedieSt
struct EncyclopedieSt {
    unsigned long identifiant; //identifiant de l'article
    char *titre; //pointeur qui pointe vers titre d'un article
    char *contenu; //pointeur vers le contenu de d'un article
    struct EncyclopedieSt * suivant; //pointeur vers un article "suivant"

};
typedef struct EncyclopedieSt *Encyclopedie;
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la structure : Encyclopedie tab
// Tableau d'encuclopedie
struct EncyclopedieTabST{
    Encyclopedie tab[TAILLE];
};
typedef struct EncyclopedieTabST EncyclopedieTab;
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : Creer_encyclopedie
//Paramètre(s) :       Aucun
//Retourne :           Un tableau d'encyclopédie
//Contenu :            Crée une encyclopédie et la retourne
//Pré Conditions :     Aucune
//Invariants :         Aucun
//Postconditions :     Un tableau d'encyclopedie est créée, existe et est vide
EncyclopedieTab creer_encyclopedie();
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : fonction_hachage
//Paramètre(s) :       i , un unsigned long
//Retourne :           un unsigned long
//Utilité :            c'est la fonction de hachage
unsigned long fonction_hachage (unsigned long i);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : inserer
//Paramètre(s) :
//                     - e, Un tableau d'Encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//                     - t, un pointeur vers une chaine de caractères (titre de l'article)
//                     - c, un pointeur vers une chaine de caractères (contenu de l'article)
//Contenu :            Renvoie un nouveau tableau d'encyclopédie  contenant l'article inseré
//Pré conditions :     les paramètres i, t, et c sont définis et valides.  i doit être unique
//Invariants :         EncyclopedieTab est définie
//Post conditions :    L'encyclopédie renvoyée contient un article d'identifiant i, de titre t et de contenu c, inséré à la fin de la liste
//                     renvoie un tableau d'encyclopédie e
EncyclopedieTab inserer(EncyclopedieTab e,unsigned long i, char *titre,char *contenu);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : supprimer
//Paramètre(s) :
//                     - e, un tableau d'encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//Retourne :           - un tableau d'encyclopédie sans l'élément supprimé
//Contenu :            - supprime l'élément e du tableau d'encyclopédie
//Pré conditions :
//                     - i est défini et valide
//                     - Le tableau d'encyclopedie contient l'article d'identifiant i
//Invariants :          EncyclopedieTab est définie

EncyclopedieTab supprimer(EncyclopedieTab e,unsigned long i);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : recherche_article
//Paramètre(s) :
//                     - e, Un tableau d'encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//Pré conditions : l'élément i est défini et valide
//Invariants :  EncyclopedieTab est définie
//Post conditions : retourne le contenu de l'article d'indentifiant i du tableau d'encyclopedie
char* recherche_article(EncyclopedieTab e,unsigned long i);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : rechercher_article_pein_texte
//Paramètre(s) :       e, une encyclopédieTab
//                     char : mot (le mot que l'on recherche)
//Pré conditions : la chaine de caractère mot n'est pas vide
//Invariants : EncyclopedieTab est définie
//Post conditions : Retourne un tableau d'encyclopedie e contenant tout les articles ayant
//                  le mot recherché, à la manière d'un moteur de recherche..
EncyclopedieTab recherche_article_plein_texte(EncyclopedieTab e,char *mot);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : detruire_encyclopedie
//Paramètre(s) :       e, un tableau d'encyclopedie
//Retourne :           rien
//Pré conditions : Le tableau d'encyclopedie  e est définie
//Invariants : Aucun
//Post conditions : Le tableau d'encyclopedie e n'existe plus
void detruire_encyclopedie(EncyclopedieTab * e);
//----------------------------------------------------------


//----------------------------------------------------------
//Utilité :            affiche l'encyclopedie
void AfficherTab(EncyclopedieTab tab);
//----------------------------------------------------------

EncyclopedieTab free_all_char(EncyclopedieTab e);

// Fonction de la liste_chainé

Encyclopedie inserer_chaine(Encyclopedie e,unsigned long i,char *t,char *c);
Encyclopedie supprimer_chaine(Encyclopedie e,unsigned long i);
char* rechercher_article_chaine(Encyclopedie e,unsigned long i);
Encyclopedie rechercher_article_plein_texte_chaine(Encyclopedie e,char *mot);
void detruire_bibliotheque_chaine(Encyclopedie * e);
void afficher_liste(Encyclopedie e);

//Fonctions supplémentaires
void afficher_liste(Encyclopedie e);
EncyclopedieTab fichier_test();
char* recuperer_char(FILE* fichier);
char* recuperer_id(FILE* fichier);

char* free_char_liste(char ** free_char);
Encyclopedie free_all_char_liste(Encyclopedie e);

#endif /* encyclopedie_h */
