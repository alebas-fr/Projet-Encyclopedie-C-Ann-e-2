
#ifndef Encyclopedie_h
#define Encyclopedie_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TAILLE_ID 12


//-----------------------------
//Nom de la structure : EcyclopedieSt
//
struct EncyclopedieSt {
    unsigned long identifiant; //identifiant de l'article
    char *titre; //pointeur qui pointe vers titre d'un article
    char *contenu; //pointeur vers le contenu de d'un article
    struct EncyclopedieSt * fils_gauche; //pointeur vers un article "gauche" (fils_gauche)
    struct EncyclopedieSt * fils_droit; // pointeur vers un article "droit" (fils_droit)
};
typedef struct EncyclopedieSt * Encyclopedie;


/////////////////////////////////////////////////////////////
//Nom de la fonction : Creer_encyclopedie
//Paramètre(s) :       Aucun
//Retourne :           Une encyclopédie
//Contenu :            Crée une encyclopédie et la retourne
//Pré Conditions :     Aucune
//Invariants :         Aucun
//Postconditions :     Une encyclopédie est créée, existe et est vide
 Encyclopedie Creer_encyclopedie();
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : inserer
//Paramètre(s) :
//                     - e, Une Encyclopédie
//                     - i, un unsigned long (identifiant de l'article
//                     - t, un pointeur vers une chaine de caractères (titre de l'article)
//                     - c, un pointeur vers une chaine de caractères (contenu de l'article)
//Retourne :           La nouvelle Encyclopédie
//Contenu :            Renvoie une nouvelle encyclopédie  contenant l'article inseré
//Pré conditions :     les paramètres i, t, et c sont définis et valides.  i doit être unique
//                     l'encyclopédie ne contient pas l’élément (l'article) à insérer
//Invariants :         L'encyclopédie est définie
//Post conditions :    L'encyclopédie renvoyée contient un article d'identifiant i, de titre t et de contenu c, inséré à la fin de la liste
//                     renvoie une encyclopédie e

Encyclopedie inserer(Encyclopedie e,unsigned long i,char *t,char *c);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : est_feuille
//Paramètre(s) :       e, une encyclopédie
//Retourne :           un entier (int)
//Contenu :            renvoi 1 si l'élément est une feuille de l'arbre (en l'occurence un article)
//                     renvoi 0 si l'element n'est pas une feuille  de l'arbre
int est_feuille(Encyclopedie e);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : afficher_Encyclopedie_infixe_rec
//Paramètre(s) :
//                     a, une encyclopédie
//                     profondeur, un entier qui indique a quel décalage sur la droite doit se faire l'écriture
//Retourne :           rien
//Contenu :            Affiche l'arbre dans l'ordre infixe
//
void afficher_Encyclopedie_infixe_rec( Encyclopedie a, int profondeur );
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : supprime2
//Paramètre(s) :
//                     - e, Une Encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//Retourne :           - l'encyclopédie sans l'élément
//Contenu :            - supprime l'élément e de l'encyclopédie
//Pré conditions :
//                     - i est défini et valide
//                     - L’encyclopedie contient l'article d'identifiant i
//                     - Invariants : L'encyclopédie est définie
//Post conditions :
//                     - renvoie l'encyclopédie e qui ne contient plus l'élément i
//Invariants :         - l'encyclopédie est définie
Encyclopedie supprime2(Encyclopedie e, unsigned long i);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : minimum
//Paramètre(s) :       e, une encyclopedie
//Retourne :           l'élément (une encyclopédie) pour lequel sont identifiant est le minimum
//
Encyclopedie minimum(Encyclopedie e);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////

//Nom de la fonction : maximum
//Paramètre(s) :       e, une encyclopedie
//Retourne :           l'élément (une encyclopédie) pour lequel sont identifiant est le maximum
//
Encyclopedie maximum(Encyclopedie e);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : rechercher_article
//Paramètre(s) :
//                     - e, Une Encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//Pré conditions : l'élément i est défini et valide
//Invariants : L'encyclopedie est définie
//Post conditions : retourne le contenu de l'article d'indentifiant i de l'encyclopédie e
char* rechercher_article(Encyclopedie e,unsigned long i);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : rechercher_article_pein_texte
//Paramètre(s) :       e, une encyclopédie
//                     char : mot (le mot que l'on recherche)
//Pré conditions : la chaine de caractère mot n'est pas vide
//Invariants : L'encyclopedie est définie
//Post conditions : Retourne l'encyclopédie e contenant tout les articles contenant l mot mot, à la manière d'un moteur de recherche..
Encyclopedie recherche_article_plein_texte(Encyclopedie e,char *mot);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : supprime_encyclopedie
//Paramètre(s) :       e, une encyclopédie
//Retourne :           rien
//Pré conditions : L'encyclopedie e est définie
//Invariants : Aucun
//Post conditions : L'encyclopedie e n'existe plus
//
void supprime_encyclopedie( Encyclopedie * e );
////////////////////////////////////////////////////////////

Encyclopedie fichier_test();
char* rechercher_article_titre(Encyclopedie e,unsigned long i);

unsigned long maximun2(unsigned long a,unsigned long b);
unsigned long hauteur(Encyclopedie a);
void afficher_Encyclopedie_parliste(Encyclopedie a, int profondeur);
char* recuperer_char(FILE* fichier);
//----------------------------------------------------------
//Nom de la fonction : free_char
//Paramètre(s) : Un pointeur vers une chaine de caractère
//Retourne : Un pointeurs vers NULL
//Utilité :  vide une chaine de caractères allouée avec un malloc
//
char* free_char(char ** free_char);
//----------------------------------------------------------
//Nom de la fonction : free_all_char
//Paramètre(s) : Encyclopedie e
//Retourne : Une encyclopedie sans chaines de caractère
//Utilité :  Vide toutes les chaines de caractères allouées avec un malloc
//
void free_all_char(Encyclopedie *e); // libère la mémoire de tous les chars


 #endif
