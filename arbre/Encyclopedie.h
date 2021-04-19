
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
//Param�tre(s) :       Aucun
//Retourne :           Une encyclop�die
//Contenu :            Cr�e une encyclop�die et la retourne
//Pr� Conditions :     Aucune
//Invariants :         Aucun
//Postconditions :     Une encyclop�die est cr��e, existe et est vide
 Encyclopedie Creer_encyclopedie();
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : inserer
//Param�tre(s) :
//                     - e, Une Encyclop�die
//                     - i, un unsigned long (identifiant de l'article
//                     - t, un pointeur vers une chaine de caract�res (titre de l'article)
//                     - c, un pointeur vers une chaine de caract�res (contenu de l'article)
//Retourne :           La nouvelle Encyclop�die
//Contenu :            Renvoie une nouvelle encyclop�die  contenant l'article inser�
//Pr� conditions :     les param�tres i, t, et c sont d�finis et valides.  i doit �tre unique
//                     l'encyclop�die ne contient pas l��l�ment (l'article) � ins�rer
//Invariants :         L'encyclop�die est d�finie
//Post conditions :    L'encyclop�die renvoy�e contient un article d'identifiant i, de titre t et de contenu c, ins�r� � la fin de la liste
//                     renvoie une encyclop�die e

Encyclopedie inserer(Encyclopedie e,unsigned long i,char *t,char *c);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : est_feuille
//Param�tre(s) :       e, une encyclop�die
//Retourne :           un entier (int)
//Contenu :            renvoi 1 si l'�l�ment est une feuille de l'arbre (en l'occurence un article)
//                     renvoi 0 si l'element n'est pas une feuille  de l'arbre
int est_feuille(Encyclopedie e);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : afficher_Encyclopedie_infixe_rec
//Param�tre(s) :
//                     a, une encyclop�die
//                     profondeur, un entier qui indique a quel d�calage sur la droite doit se faire l'�criture
//Retourne :           rien
//Contenu :            Affiche l'arbre dans l'ordre infixe
//
void afficher_Encyclopedie_infixe_rec( Encyclopedie a, int profondeur );
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : supprime2
//Param�tre(s) :
//                     - e, Une Encyclop�die
//                     - i, un unsigned long (identifiant de l'article)
//Retourne :           - l'encyclop�die sans l'�l�ment
//Contenu :            - supprime l'�l�ment e de l'encyclop�die
//Pr� conditions :
//                     - i est d�fini et valide
//                     - L�encyclopedie contient l'article d'identifiant i
//                     - Invariants : L'encyclop�die est d�finie
//Post conditions :
//                     - renvoie l'encyclop�die e qui ne contient plus l'�l�ment i
//Invariants :         - l'encyclop�die est d�finie
Encyclopedie supprime2(Encyclopedie e, unsigned long i);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : minimum
//Param�tre(s) :       e, une encyclopedie
//Retourne :           l'�l�ment (une encyclop�die) pour lequel sont identifiant est le minimum
//
Encyclopedie minimum(Encyclopedie e);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////

//Nom de la fonction : maximum
//Param�tre(s) :       e, une encyclopedie
//Retourne :           l'�l�ment (une encyclop�die) pour lequel sont identifiant est le maximum
//
Encyclopedie maximum(Encyclopedie e);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : rechercher_article
//Param�tre(s) :
//                     - e, Une Encyclop�die
//                     - i, un unsigned long (identifiant de l'article)
//Pr� conditions : l'�l�ment i est d�fini et valide
//Invariants : L'encyclopedie est d�finie
//Post conditions : retourne le contenu de l'article d'indentifiant i de l'encyclop�die e
char* rechercher_article(Encyclopedie e,unsigned long i);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : rechercher_article_pein_texte
//Param�tre(s) :       e, une encyclop�die
//                     char : mot (le mot que l'on recherche)
//Pr� conditions : la chaine de caract�re mot n'est pas vide
//Invariants : L'encyclopedie est d�finie
//Post conditions : Retourne l'encyclop�die e contenant tout les articles contenant l mot mot, � la mani�re d'un moteur de recherche..
Encyclopedie recherche_article_plein_texte(Encyclopedie e,char *mot);
////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////
//Nom de la fonction : supprime_encyclopedie
//Param�tre(s) :       e, une encyclop�die
//Retourne :           rien
//Pr� conditions : L'encyclopedie e est d�finie
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
//Param�tre(s) : Un pointeur vers une chaine de caract�re
//Retourne : Un pointeurs vers NULL
//Utilit� :  vide une chaine de caract�res allou�e avec un malloc
//
char* free_char(char ** free_char);
//----------------------------------------------------------
//Nom de la fonction : free_all_char
//Param�tre(s) : Encyclopedie e
//Retourne : Une encyclopedie sans chaines de caract�re
//Utilit� :  Vide toutes les chaines de caract�res allou�es avec un malloc
//
void free_all_char(Encyclopedie *e); // lib�re la m�moire de tous les chars


 #endif
