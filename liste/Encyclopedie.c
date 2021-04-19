//
//  Encyclopedie.c
//  Liste_chaine
//
//  Created by Alexandre Lebas & Océane Deletrez on 14/11/2018.
//  Copyright © 2018 Alexandre Lebas & Océane Deletrez. All rights reserved.
//

#include "Encyclopedie.h"
#include "menu.h"

Encyclopedie Creer_encyclopedie(){
    return NULL; // retourne une adresse vers NULL qui equivaut à une encyclopedie vide
}

/*

 Fonction : Insere l'élement dans l'encyclopedie

 Paramètres : e : encyclopedie ou on veut inserer l'élément, i : identifiant de l'élément, *t pointeur vers le titre à inserer, *c pointeur vers le contenu à inserer.

 Effets : Renvoie l'encyclopedie avec l'élément inserer à la fin,

*/


// fonction faite ne iteratif


Encyclopedie inserer(Encyclopedie e,unsigned long i,char *t,char *c){// inserer l'élément à la fin de la liste l'élement
    if (i>=0 && t!=NULL && c!=NULL) { // le i>=0 est logique car c'est un unsigned
        if (e==NULL) { // dans le cas ou l'encyclopedie est vide
            e=(Encyclopedie)malloc(sizeof(struct EncyclopedieSt)); // allocation de la mémoire
            if (e!=NULL) {
                e->identifiant=i;
                e->contenu=c;
                e->titre=t;
                e->suivant=NULL;

            }
            else{
                exit(1); // arrete immediatement le programme s'il y a un problème de declaration
            }
        }
        else if (e->suivant==NULL && e->identifiant!=i){ // dans la cas ou l'encyclopedie à 1 seul élément
            e->suivant=(Encyclopedie)malloc(sizeof(struct EncyclopedieSt)); // allocation de la memoire pour l'élément suivant
            if (e->suivant!=NULL) {
                e->suivant->identifiant=i;
                e->suivant->contenu=c;
                e->suivant->titre=t;
                e->suivant->suivant=NULL;
            }
            else{
                exit(1); // arrete immediatement le programme
            }

        }
        else { // dans le cas general
            Encyclopedie copie=e;
            int verif=1;
            int verif1=1;
            while (copie!=NULL && verif && verif1) {
                if (copie->identifiant==i) {
                    verif=0;
                }
                if (copie->suivant!=NULL) {
                    copie=copie->suivant;
                }
                else{
                    verif1=0;
                }

            }
            if (verif) {
                copie->suivant=(Encyclopedie)malloc(sizeof(struct EncyclopedieSt));
                if (copie->suivant!=NULL) {
                    copie->suivant->identifiant=i;
                    copie->suivant->contenu=c;
                    copie->suivant->titre=t;
                    copie->suivant->suivant=NULL;
                }
                else{
                    exit(1);
                }
            }

        }
    }


    return e;
}

/*

 Fonction : Supprime l'élément de l'encyclopedie

 Paramètres : e : encyclopedie ou on veut supprimer l'élément, i : identifiant de l'élément

 Effets : Renvoie l'encyclopedie avec l'élément supprime

 */

Encyclopedie supprimer(Encyclopedie e,unsigned long i){
    if (e==NULL) {
        printf("PAS DE LISTE\n\n");
    }

    else if (e->suivant==NULL && e->identifiant==i) { // dans le cas ou on a une encyclopedie avec 1 seul élément et que l'on à l'identifiant
        free(e);
        e=NULL;
    }

    else{
        Encyclopedie Copie=e;
        Encyclopedie temps=NULL;
        int verif=1;
        while (Copie->suivant!=NULL && verif) {
            if (Copie->suivant->identifiant==i) {
                temps=Copie->suivant->suivant;
                Copie->suivant->titre=free_char(&(Copie->suivant->titre));
                Copie->suivant->contenu=free_char(&(Copie->suivant->contenu));
                free(Copie->suivant);
                Copie->suivant=temps;
                verif=0;
            }
            if (Copie->suivant!=NULL) {
                Copie=Copie->suivant;
            }
        }
    }
    return e;

}

/*

 Fonction : Recherche un contenu d'article

 Paramètres : e : Encyclopedie ou on recherche le contenu i, i : Element que l'on recherche

 Effets : Renvoie un pointeur vers la chaine de caractère qui contient le contenu de i

 */

char* rechercher_article(Encyclopedie e,unsigned long i){
    Encyclopedie Copie=e;
    char* ret =NULL;
    int test=1;
    while (Copie!=NULL && test) {
        if (Copie->identifiant==i) {
            ret=Copie->contenu;
            test=0;
        }
        Copie=Copie->suivant;
    }
    return ret;
}

/*

 Fonction : Recherche et crée une encyclopedie avec les article qui contiennent le mots

 Paramètres : e : Encyclopedie ou on recherche le mot mot : Pointeur sur le mot que l'on recherche

 Effets : Retourne une encyclopedie ou apparaisent les éléments i qui ont le mot dans leurs Contenu

 */

Encyclopedie rechercher_article_plein_texte(Encyclopedie e,char *mot){
    Encyclopedie recherche=NULL;
    Encyclopedie copie=e;
    char* test=NULL;
    char* test2=NULL;
    if (e!=NULL) {
        while (copie!=NULL) {
            test=strstr(copie->contenu,mot);// verifie si le mot est bien inclu dans la chaine de caractères et renvoi la position NULL si non inclus
            test2=strstr(copie->titre,mot);
            if (test!=NULL || test2!=NULL) {

                recherche=inserer(recherche,copie->identifiant,copie->titre,copie->contenu);
            }
            copie=copie->suivant;
        }
    }
    return recherche;
}


/*

 Fonction : Detruit la bibliothéque

 Paramètres : e : Encyclopedie à detruire

 Effets : Libére la memoire occupé par l'encyclopedie en mémoire

 */



void detruire_bibliotheque(Encyclopedie * e){ // Derivé de la fonction free_arbre en TP

    Encyclopedie *copie=e; // Copier l'adresse qui pointe sur l'encyclopedie
    while (e!=NULL && *e!=NULL) { // verifier si l'encyclopedie n'est pas vide
        copie=&(*(e))->suivant; // recuperer l'adresse de l'encycloedie suivante pour pouvoir la supprimer
        free(*e);
        *e=NULL; // mettre à NULL aprés avoir liberer.
        e=copie; // Passer à l'encycloedie suivante
    }
}



// Fonctions qui sont utile pour le test du TAD

void afficher_liste(Encyclopedie e){
    Encyclopedie copie=e;
    while (copie!=NULL) {
        printf("Identifiant = %lu \nTitre = %s \nContenu = %s \n\n",copie->identifiant,copie->titre,copie->contenu);
        copie=copie->suivant;
    }
}


void afficher_Encyclopedie_parliste( Encyclopedie a, int profondeur ) {
	int i;
	if ( a != NULL ) {
		afficher_Encyclopedie_parliste( a->suivant, (profondeur) );
		printf("\n------\n");
		printf( "\n%lu\n", a->identifiant );
		printf( "%s\n", a->titre );
		printf( "%s\n", a->contenu );
	}
}

    char* recuperer_char(FILE* fichier){
    int caractere_actuel=0;
    char *chaine=NULL;
    chaine = malloc(sizeof(char)*TEXT_MAX);
    unsigned long compt=0;
    caractere_actuel=fgetc(fichier);
    if (caractere_actuel=='|' ||caractere_actuel=='\n'){
        caractere_actuel=fgetc(fichier);
    }
    while(caractere_actuel!='|' && caractere_actuel!='\n'){
        chaine[compt]=caractere_actuel;
        compt++;
        caractere_actuel=fgetc(fichier);
        if (caractere_actuel=='|' || caractere_actuel=='\n'){
            chaine[compt]=0;
        }
    }
    return chaine;
}

    char* recuperer_id(FILE* fichier){
    char caractere_actuel=0;
    char *chaine=NULL;
    chaine = malloc(sizeof(char)*TAILLE_ID);
    unsigned long compt=0;
    caractere_actuel=fgetc(fichier);
     if(chaine!=NULL){
    while(caractere_actuel!='|' && caractere_actuel!='\n' && caractere_actuel!=EOF){
        chaine[compt]=caractere_actuel;
        compt++;
        caractere_actuel=fgetc(fichier);
        if (caractere_actuel=='|' || caractere_actuel=='\n'){
            chaine[compt]=0;
        }







    }
     }
    else{
        exit(1);
    }
    return chaine;
}

Encyclopedie fichier_test(){
    Encyclopedie e;
    char* contenurecherche;
    e = Creer_encyclopedie(e);
    int i=1;
                 //e = NULL;

    FILE *fichier_test = NULL;
    //fichier_test = fopen("B46_wikipedia_500K_sorted.dat","r"); //Windows
    fichier_test = fopen("B46_wikipedia_test.dat","r");
   // Encyclopedie Hachette;
    //Encyclopedie HachetteDouble;
    //Hachette = Creer_encyclopedie;
    char text[TEXT_MAX] = "";
    char *titre, *contenu,*id;
    unsigned long identif;

    if (fichier_test!=NULL) {
        while ((fgets(text,TEXT_MAX ,fichier_test) != NULL)&&i){
            id=recuperer_id(fichier_test);
            printf("chaine = %s\n\n",id);
            titre=recuperer_char(fichier_test);
            printf("%s\n\n",titre);
            contenu=recuperer_char(fichier_test);
            printf("%s\n\n",contenu);
            identif = (unsigned long)atoll(id);//Converti l'id char en unsigend long
            free(id);
            printf("%lu\n\n",identif);
            if(identif!=0){ // cas ou l'identifiant existe
                printf("identifiant = %lu\n\n",identif);
                e = inserer(e,identif,titre,contenu);
            }
            else{ // cas ou on arrive à la fin du fichier
                i=0;
            }

           //afficher_Encyclopedie_infixe_rec(e,0); ok ca va

           //affichage de toute la bibliotheque

           //  printf("\n-------------------------\n");
           //  printf("\nid : %lu",identif); //On a l'id //Pour afficher tout les id
           //  printf("\ntitre: %s",titre); //pour afficher tous les titres -> ok
           //  printf("\n\ncontenu:%s",contenu); //pour afficher tout les contenus
        }
         //contenurecherche = rechercher_article(e,5812967);
        // printf("\n\n%s\n",contenurecherche); //pour tester

    }
    else{
        printf("Impossible d'ouvrir le fichier");
    }
    fclose(fichier_test);



return e;}


char* free_char(char ** free_char){
    free(*free_char);
    return NULL;
}
 // libère l'espace mémoire alloué pour un article
Encyclopedie free_all_char(Encyclopedie e){
    Encyclopedie copie=e;
    while(copie!=NULL){
        copie->contenu=free_char(&(e->contenu));
        copie->titre=free_char(&(e->titre));
        copie=copie->suivant;
    }
}







