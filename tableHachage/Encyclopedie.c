//
//  encyclopedie.c
//  Table_hachage
//
//  Created by Alexandre Lebas on 15/11/2018.
//  Copyright © 2018 Alexandre Lebas. All rights reserved.
//


#include "Encyclopedie.h"
#include "menu.h"

unsigned long fonction_hachage (unsigned long i){
    unsigned long ret = 0;
    ret= i%TAILLE;
    return ret;
}

// FONCTION REPRISE DE LA FONCTION INSERER DES LISTES CHAINEES

EncyclopedieTab creer_encyclopedie(){
    EncyclopedieTab tab;
    int i;
    for (i=0;i<TAILLE;i++) {
        tab.tab[i]=NULL;
    }
    return tab;
}

EncyclopedieTab inserer(EncyclopedieTab e,unsigned long i, char *titre,char *contenu){
    if (titre!=NULL && contenu!=NULL) { // verifier si il y a bien un titre et un contenu
        unsigned long hach=fonction_hachage(i); //on recupere un nombre a partir de la fonction de hachage
        e.tab[hach]=inserer_chaine(e.tab[hach],i,titre,contenu); // inserer la liste dans le tableau
    }
    return e;
}

EncyclopedieTab supprimer(EncyclopedieTab e,unsigned long i){
    unsigned long hach;
    hach=fonction_hachage(i);
    e.tab[hach]=supprimer_chaine(e.tab[hach],i); //on reutilise la fonction des listes chainnees
    return e;
}
char* recherche_article(EncyclopedieTab e,unsigned long i){
    unsigned long hach;
    hach=fonction_hachage(i);
    char* ret=rechercher_article_chaine(e.tab[hach],i);
    return ret;
}

EncyclopedieTab recherche_article_plein_texte(EncyclopedieTab e,char *mot){
    unsigned long i;
    unsigned long hach;
    EncyclopedieTab recherche=creer_encyclopedie();
    for (i=0;i<TAILLE;i++) {
        hach=fonction_hachage(i);
        recherche.tab[hach]=rechercher_article_plein_texte_chaine(e.tab[hach],mot);
    }
    return recherche;
}

void detruire_encyclopedie(EncyclopedieTab * e){
    if (e!=NULL) {
        unsigned long i=0;
        for (i=0;i<TAILLE;i++) { //pour toute les cases du tableau
            detruire_bibliotheque_chaine(&(e->tab[i]));
        }
    }
}

EncyclopedieTab free_all_char(EncyclopedieTab e){
    int i=0;
    for(i=0;i<TAILLE;i++){
        e.tab[i]=free_all_char_liste(e.tab[i]);
    }
    return e;
}

void AfficherTab(EncyclopedieTab tab){
    int i;
    for (i=0;i<TAILLE;i++) {
        afficher_liste(tab.tab[i]);
    }
}






Encyclopedie inserer_chaine(Encyclopedie e,unsigned long i,char *t,char *c){// inserer l'élément à la fin de la liste l'élement
    if (i>=0 && t!=NULL && c!=NULL) { // le i>=0 est logique car c'est un unsigned
        if (e==NULL) { // dans le cas ou l'encyclopedie est vide
            e=malloc(sizeof(struct EncyclopedieSt)); // allocation de la mémoire
            if (e!=NULL) {
                e->identifiant=i;
                e->contenu=c;    char* recuperer_id(FILE* fichier){
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

                e->titre=t;
                e->suivant=NULL;
            }
            else{
                exit(1); // arrete immediatement le programme s'il y a un problème de declaration
            }
        }
        else if (e->suivant==NULL && e->identifiant!=i){ // dans la cas ou l'encyclopedie à 1 seul élément
            e->suivant=malloc(sizeof(struct EncyclopedieSt)); // allocation de la memoire pour l'élément suivant
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
                copie->suivant=malloc(sizeof(struct EncyclopedieSt));
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

Encyclopedie supprimer_chaine(Encyclopedie e,unsigned long i){
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
                Copie->suivant->titre=free_char_liste(&(Copie->suivant->titre));
                Copie->suivant->contenu=free_char_liste(&(Copie->suivant->contenu));
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

char* rechercher_article_chaine(Encyclopedie e,unsigned long i){
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

Encyclopedie rechercher_article_plein_texte_chaine(Encyclopedie e,char *mot){
    Encyclopedie recherche=NULL;
    Encyclopedie copie=e;
    char* test=NULL;
    char* test2=NULL;
    if (e!=NULL) {
        while (copie!=NULL) {
            test=strstr(copie->contenu,mot);
            test=strstr(copie->titre,mot);
            // verifie si le mot est bien inclus dans la chaine de caractères et renvoie la position NULL si non inclus
            if (test!=NULL || test2!=NULL) {
                recherche=inserer_chaine(recherche,copie->identifiant,copie->titre,copie->contenu);
            }
            copie=copie->suivant;
        }
    }
    return recherche;
}

void detruire_bibliotheque_chaine(Encyclopedie * e){

    Encyclopedie *copie=e; // Copier l'adresse qui pointe sur l'encyclopedie
    while (e!=NULL && *e!=NULL) { // verifier si l'encyclopedie n'est pas vide
        copie=&(*(e))->suivant; // recuperer l'adresse de l'encycloedie suivante pour pouvoir la supprimer
        free(*e);
        *e=NULL; // mettre à NULL aprés avoir liberer.
        e=copie; // Passer à l'encycloedie suivante
    }

}

void afficher_liste(Encyclopedie e){
    Encyclopedie copie=e;
    while (copie!=NULL) {
        printf("Identifiant = %lu \nTitre = %s \nContenu = %s \n\n",copie->identifiant,copie->titre,copie->contenu);
        copie=copie->suivant;
    }
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


/*
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
}*/

char* recuperer_char(FILE* fichier){
    char caractere_actuel=0;
    char *chaine=NULL;
    unsigned long compt=0;
    caractere_actuel=fgetc(fichier);
    if (caractere_actuel=='|' ||caractere_actuel=='\n'){
        caractere_actuel=fgetc(fichier);
    }
        while(caractere_actuel!='|' && caractere_actuel!='\n' &&caractere_actuel!=EOF){
        compt++;
        caractere_actuel=fgetc(fichier);
    }
     chaine = malloc(sizeof(char)*(compt+2));
     if(chaine!=NULL){
            fseek(fichier,(-compt),SEEK_CUR);
    compt=0;
    caractere_actuel=fgetc(fichier);
    while(caractere_actuel!='|' && caractere_actuel!='\n' &&caractere_actuel!=EOF){
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

EncyclopedieTab fichier_test(){
    EncyclopedieTab e;
    char* contenurecherche;
    e = creer_encyclopedie();
                 //e = NULL;

    FILE *fichier_test = NULL;
    fichier_test = fopen("B46_wikipedia_test.dat","r"); //Windows
    //fichier_test = fopen("B46_wikipedia_500K_sorted.dat","r"); //Windows
    int i=1;
   // Encyclopedie Hachette;
    //Encyclopedie HachetteDouble;
    //Hachette = Creer_encyclopedie;
    char text[TEXT_MAX] = "";
    char text2[TEXT_MAX] = "";
    char *titre, *contenu,*id;
    char *c1;
    unsigned long identif;

    if (fichier_test!=NULL) {
        while (fgets(text,TEXT_MAX ,fichier_test) != NULL){
            id=recuperer_id(fichier_test);
            titre=recuperer_char(fichier_test);
            contenu=recuperer_char(fichier_test);
            //printf("%s\n\n",id);
           identif = (unsigned long)atoll(id);//Converti l'id char en unsigned long
           if(identif!=0){ // cas ou l'identifiant existe
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
    fclose(fichier_test);



return e;}


char* free_char_liste(char ** free_char){
    free(*free_char);
    return NULL;
}
 // libere l'espace memoire alloue pour un article
Encyclopedie free_all_char_liste(Encyclopedie e){
    Encyclopedie copie=e;
    while(copie!=NULL){
        copie->contenu=free_char_liste(&(e->contenu));
        copie->titre=free_char_liste(&(e->titre));
        copie=copie->suivant;
    }
}





