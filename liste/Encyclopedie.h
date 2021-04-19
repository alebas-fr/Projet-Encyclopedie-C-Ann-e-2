//
//  Encyclopedie.h
//  Liste_chaine
//
//  Created by Alexandre Lebas & Océane Deletrez on 14/11/2018.
//  Copyright © 2018 Alexandre Lebas & Océane Deletrez. All rights reserved.
//

#ifndef Encyclopedie_h
#define Encyclopedie_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_ID 12

//----------------------------------------------------------

//Nom de la structure : EcyclopedieSt
struct EncyclopedieSt {
    unsigned long identifiant; //identifiant de l'article
    char *titre; //pointeur qui pointe vers titre d'un article
    char *contenu; //pointeur vers le contenu de d'un article
    struct EncyclopedieSt * suivant; //pointeur vers un article "suivant"

};
typedef struct EncyclopedieSt * Encyclopedie;
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : Creer_encyclopedie
//Paramètre(s) :       Aucun
//Retourne :           Une encyclopédie
//Contenu :            Crée une encyclopédie et la retourne
//Pré Conditions :     Aucune
//Invariants :         Aucun
//Postconditions :     Une encyclopédie est créée, existe et est vide
Encyclopedie Creer_encyclopedie();
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : inserer
//Paramètre(s) :
//                     - e, Une Encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//                     - t, un pointeur vers une chaine de caractères (titre de l'article)
//                     - c, un pointeur vers une chaine de caractères (contenu de l'article)
//Retourne :           La nouvelle Encyclopédie
//Contenu :            Renvoie une nouvelle encyclopédie  contenant l'article inseré
//Pré conditions :     les paramètres i, t, et c sont définis et valides.  i doit être unique
//Invariants :         L'encyclopédie est définie
//Post conditions :    L'encyclopédie renvoyée contient un article d'identifiant i, de titre t et de contenu c, inséré à la fin de la liste
//                     renvoie une encyclopédie e
Encyclopedie inserer(Encyclopedie e,unsigned long i,char *t,char *c);
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : supprimer
//Paramètre(s) :
//                     - e, Une Encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//Retourne :           - l'encyclopédie sans l'élément
//Contenu :            - supprime l'élément e de l'encyclopédie
//Pré conditions :
//                     - i est défini et valide
//                     - L'encyclopedie contient l'article d'identifiant i
//                     - Invariants : L'encyclopédie est définie
//Post conditions :
//                     - renvoie l'encyclopédie e qui ne contient plus l'élément i
//Invariants :         - l'encyclopédie est définie
Encyclopedie supprimer(Encyclopedie e,unsigned long i);
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : rechercher_article
//Paramètre(s) :
//                     - e, Une Encyclopédie
//                     - i, un unsigned long (identifiant de l'article)
//Pré conditions : l'élément i est défini et valide
//Invariants : L'encyclopedie est définie
//Post conditions : retourne le contenu de l'article d'indentifiant i de l'encyclopédie
char* rechercher_article(Encyclopedie e,unsigned long i);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : rechercher_article_pein_texte
//Paramètre(s) :       e, une encyclopédie
//                     char : mot (le mot que l'on recherche)
//Pré conditions : la chaine de caractère mot n'est pas vide
//Invariants : L'encyclopedie est définie
//Post conditions : Retourne l'encyclopédie e contenant tout les articles
//                  ayant le mot recherché, à la manière d'un moteur de recherche..
Encyclopedie rechercher_article_plein_texte(Encyclopedie e,char *mot);
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : detruire_bibliotheque
//Paramètre(s) :       e, une encyclopédie
//Retourne :           rien
//Pré conditions : L'encyclopedie e est définie
//Invariants : Aucun
//Post conditions : L'encyclopedie e n'existe plus
void detruire_bibliotheque(Encyclopedie * e);
//----------------------------------------------------------

// Fonctions supplémentaires //

//----------------------------------------------------------
//Nom de la fonction : afficher_liste
//Paramètre(s) :       e, une encyclopédie
//Retourne :           rien
//Utilité :            affiche l'encyclopedie
void afficher_liste(Encyclopedie e);
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : affiche_Encyclopedie_parliste
//Paramètre(s) :       e, une encyclopédie ; profondeur un entier
//Retourne :           rien
//Utilité :            affiche l'encyclopedie (même utilité que afficher_liste
void afficher_Encyclopedie_parliste( Encyclopedie a, int profondeur );
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : fichier_test
//Paramètre(s) :       aucun
//Retourne :           une encyclopedie
//Utilité :            lecture du fichier wikipedia, recupere les articles (id, titre et leur contenu),
//                      crée une encyclopedie à partir des informations récupérées
Encyclopedie fichier_test();
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : recuperer_char
//Paramètre(s) : fichier de type FILE
//Retourne : une pointeur vers une chaine de caracteres
//Utilité :  recupere une chaine de caractere
//
char* recuperer_char(FILE* fichier);
//----------------------------------------------------------


//----------------------------------------------------------
//Nom de la fonction : recuperer_id
//Paramètre(s) : fichier de type FILE
//Retourne : une pointeur vers une chaine de caracteres
//Utilité :  recupere une chaine de caractere
//
char* recuperer_id(FILE* fichier);

//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : free_char
//Paramètre(s) : Pointeur sur une chaine de caractère
//Retourne : un pointeur vers NULL
//Utilité :  Vide une chaine de caractère qui à été attribué par un malloc
//
char* free_char(char ** free_char);
//----------------------------------------------------------

//----------------------------------------------------------
//Nom de la fonction : vider la mémoire occupé par toutes les chaines de caractères
//Paramètre(s) : Encyclopedie e
//Retourne : Une encyclopedie sans chaines de caractère
//Utilité :  Vide toutes les chaines de caractère alloué avec un malloc
//
Encyclopedie free_all_char(Encyclopedie e);
//----------------------------------------------------------






#endif /* Encyclopedie_h */
