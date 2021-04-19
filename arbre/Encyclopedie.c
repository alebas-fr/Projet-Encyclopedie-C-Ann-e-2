
#include "Encyclopedie.h"
#include "menu.h"

/*Structure pour l'encyclopédie
 *
 * Champs : valeur - l'entier contenu dans le noeud
 *        fils_gauche - un pointeur vers le fils gauche du noeud de l'encyclopédie
 *        fils_droit - un pointeur vers le fils droit du noeud de l'encyclopédie
 */


Encyclopedie Creer_encyclopedie(){
    return NULL; // retourner une adresse vers NULL qui equivaut à une encyclopedie vide
}

Encyclopedie minimum(Encyclopedie e){
	Encyclopedie t=e;
	if(t->fils_gauche ==NULL){return t;}
	return minimum(t->fils_gauche);
}

Encyclopedie maximum(Encyclopedie e){
	Encyclopedie t=e;
	if(t->fils_droit==NULL){return t;}
	return maximum(t->fils_droit);
}

Encyclopedie inserer(Encyclopedie e,unsigned long i,char *t,char *c){ // inserer l'élément à la fin de la liste l'élement
     Encyclopedie eTmp;
     eTmp = e;
    //cas d'arret
    if (eTmp==NULL) { // dans le cas ou l'encyclopedie est vide
        eTmp=malloc(sizeof(struct EncyclopedieSt)); // allocation de la mémoire
        if(eTmp!=NULL){
            eTmp->identifiant =i;
            eTmp->contenu     =c;
            //printf("\nCONTENU QUE L'on VEUT AJOUTER :%s",c);
            eTmp->titre       =t;
            eTmp->fils_droit  =NULL;
            eTmp->fils_gauche =NULL;
        }
        else{
            exit(1);
        }

    }

    else {
        if (i == eTmp->identifiant){
            printf("\n ERREUR : ID Deja present \n ");
        }
        if (i < eTmp->identifiant){ //se rend au fils gauche
         eTmp->fils_gauche = inserer(eTmp->fils_gauche,i,t,c);
        }
        if (i > eTmp->identifiant){ //se rend au fils droit
         eTmp->fils_droit = inserer(eTmp->fils_droit,i,t,c);
        }
}
        //DEBUG
        /*
        printf("\n-------------------------\n");
        printf("voila ce qui veut etre enregistre");
        printf("\n%lu",i); //On a l'id //Pour afficher tout les id
        printf("\n%s",t); //pour afficher tous les titres -> ok
        printf("\n\n%s",c); //pour afficher tout les contenus
        printf("\n-------------------------\n");
        printf("\nVOILA CE QUI A ETE ENREGISTRE :");
        printf("\n%lu",eTmp->identifiant); //On a l'id //Pour afficher tout les id
        printf("\n%s",eTmp->titre); //pour afficher tous les titres -> ok
        printf("\n\n%s",eTmp->contenu); //pour afficher tout les contenus*/


 return eTmp;
}


Encyclopedie supprime2(Encyclopedie e, unsigned long i){
	Encyclopedie t;
	if(e==NULL){
		return e;
}
//encyclopedie non nulle
	else if(i< e->identifiant){
		e->fils_gauche=supprime2(e->fils_gauche,i);}
	else
	if(i> e->identifiant){
		e->fils_droit=supprime2(e->fils_droit,i);}
	else
	if(e->fils_gauche && e->fils_droit){
		t = maximum(e->fils_gauche);
		t->fils_droit = e->fils_droit;
		e = e->fils_gauche;
	}

	else{t=e;
	if(e->fils_gauche==NULL)
		e=e->fils_droit;
	else if(e->fils_droit==NULL)
		e=e->fils_gauche;
    free(t->contenu);
    free(t->titre);
	free(t);
	}
	return e;
}

char* rechercher_article(Encyclopedie e,unsigned long i){
     char* ret=NULL;
    if (e!=NULL) { // Cas de l'arbre non nul
        if (e->identifiant==i) { // si on trouve l'identifiant
            ret=e->contenu;
        }
        else if(i<e->identifiant){
            ret=rechercher_article(e->fils_gauche,i);
        }
        else{
            ret=rechercher_article(e->fils_droit,i);
        }
    }
    return ret; // On renvoie le pointeur qui contient le maillon avec l'identifiant i, NULL s'il n'existe pas.
}

char* rechercher_article_titre(Encyclopedie e,unsigned long i){
     char* ret=NULL;
    if (e!=NULL) { // Cas de l'arbre non nul
        if (e->identifiant==i) { // si on trouve l'identifiant
            ret=e->titre;
        }
        else{
            ret=rechercher_article_titre(e->fils_gauche,i); // On recherche l'identifiant dans la partie gauche de l'arbre
            if (ret==NULL) {
                ret=rechercher_article_titre(e->fils_droit,i); // Puis dans la partie droite si on ne trouve pas dans la partie gauche.
            }
        }
    }
    return ret; // On renvoie le pointeur qui contient le maillon avec l'identifiant i, NULL s'il n'existe pas.
}


Encyclopedie recherche_article_plein_texte(Encyclopedie e,char *mot){
    Encyclopedie recherche=NULL;
    if (e!=NULL) { // cas de l'arbre non vide
        char *test=strstr(e->contenu,mot);
        char *test1=strstr(e->titre,mot);
        if (test!=NULL || test1!=NULL) {
            recherche=inserer(recherche,e->identifiant,e->titre,e->contenu);
        }
        if (recherche!=NULL) { // dans le cas ou l'encyclopedie recherche n'est pas vide car sinon cela ne marche pas
            recherche->fils_gauche = recherche_article_plein_texte(e->fils_gauche,mot);
            recherche->fils_droit = recherche_article_plein_texte(e->fils_droit,mot);
        }
        if (recherche==NULL) { // cas ou l'encyclopedie est vide il faut donc trouver la racine de l'arbre
            recherche=recherche_article_plein_texte(e->fils_gauche,mot); // on recherche d'abord si le mots est contenue dans la partie gauche de l'arbre
            if (recherche==NULL) {
                recherche=recherche_article_plein_texte(e->fils_droit,mot); // si on ne trouve rien dans la partie gauche de l'arbre alors on recherche dans la partie droite de l'arbre
            }
        }
    }
    return recherche;
}

void supprime_encyclopedie( Encyclopedie * e ) { // Tiré DE LA FONCTION FREE ARBRE DONNEZ EN TP 4 EXERCICE 1

    if ( e != NULL && *e != NULL ) {
        supprime_encyclopedie( &((*e)->fils_gauche ) );
        supprime_encyclopedie( &((*e)->fils_droit ) );
        free( *e );
        *e = NULL;
    }
}
int est_feuille(Encyclopedie e){
    int valeur = 0;
    if ((e!=NULL)&&(e->fils_gauche == NULL )&&(e->fils_droit== NULL )){
        valeur = 1;
    }
return valeur;
}

void afficher_Encyclopedie_infixe_rec( Encyclopedie a, int profondeur ) {

	int i;
	if ( a != NULL ) {

		afficher_Encyclopedie_infixe_rec( a->fils_droit, (profondeur + 1) );
		for ( i = 0 ; i < profondeur ; i++ ) {
			printf( "  " );
		}
		printf( "%lu\n", a->identifiant );
		afficher_Encyclopedie_infixe_rec( a->fils_gauche, (profondeur + 1) );
	}
}

void afficher_Encyclopedie_parliste( Encyclopedie a, int profondeur ) {
	int i;
	if ( a != NULL ) {
		afficher_Encyclopedie_parliste( a->fils_droit, (profondeur) );
		printf("\n------\n");
		printf( "\n%lu\n", a->identifiant );
		printf( "%s\n", a->titre );
		printf( "%s\n", a->contenu );
		afficher_Encyclopedie_parliste( a->fils_gauche, (profondeur) );
	}
}



void afficher_encyclopedie(Encyclopedie a, int profondeur){
    printf("\n------------------------------------------------------\n");
    printf("Affichage de l'encyclopedie)\n");
    printf("------------------------------------------------------\n\n");
    afficher_Encyclopedie_infixe_rec(a,profondeur);
}


unsigned long maximun2(unsigned long a,unsigned long b){ // coder en B23
    unsigned long ret=0;
    if (a<b) {
        ret=b;
    }
    else{
        ret=a;
    }
    return ret;
}


unsigned long hauteur(Encyclopedie a){ // fonction reprise du TD sur les arbres
    unsigned long ret=0;
    if (a!=NULL) {
        if (est_feuille(a)) {
            ret=1; // si on arrive a une feuille alors hauteur =1
        }
        else{
            ret=1+maximun2(hauteur(a->fils_gauche),hauteur(a->fils_gauche)); // on prend la hauteur maximale entre le sous arbre gauche et le sous arbre droit ou on ajoute 1 pour le maillon actuelle.
        }
    }
    return ret;
}


/*
void afficher_article(Encyclopedie a){
    printf("\n------------------------------------------------------\n");
    printf("Affichage de l'article )\n");
    printf("------------------------------------------------------\n\n");
    printf("identifiant de l'article : %u \n",a->identifiant);
    printf("identifiant de l'article : %s \n\n\n",a->titre);
    printf("identifiant de l'article : %s \n",a->contenu);
}*/

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

Encyclopedie fichier_test(){
    Encyclopedie e;
    char* contenurecherche;
    e = Creer_encyclopedie(e);
    int i=1;
                 //e = NULL;

    FILE *fichier_test = NULL;
    //fichier_test = fopen("B46_wikipedia_500K_random.dat","r"); //Windows
    fichier_test = fopen("B46_wikipedia_test.dat","r");
    char text[TEXT_MAX] = "";
    char *titre, *contenu,*id;
    unsigned long identif;

    if (fichier_test!=NULL) {
        while ((fgets(text,TEXT_MAX ,fichier_test) != NULL)&&i){
            id=recuperer_id(fichier_test);
            titre=recuperer_char(fichier_test);
            contenu=recuperer_char(fichier_test);
            identif = (unsigned long)atoll(id);//Converti l'id char en unsigend long
            free(id);
            if(identif!=0){ // cas ou l'identifiant existe
                e = inserer(e,identif,titre,contenu);
            }
            else{ // cas ou on arrive à la fin du fichier
                i=0;
            }
        }
    }
               //afficher_Encyclopedie_infixe_rec(e,0); ok ca va

           //affichage de toute la bibliotheque
           //  printf("\n-------------------------\n");
           //  printf("\nid : %lu",identif); //On a l'id //Pour afficher tout les id
           //  printf("\ntitre: %s",titre); //pour afficher tous les titres -> ok
           //  printf("\n\ncontenu:%s",contenu); //pour afficher tout les contenus
         //contenurecherche = rechercher_article(e,5812967);
        // printf("\n\n%s\n",contenurecherche); //pour tester

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
void free_all_char(Encyclopedie *e){ // ne marche pas è verifier pourquoi.
    if(e!=NULL && *e!=NULL){
        ((*e)->contenu)=free_char(&((*e)->contenu));
        ((*e)->titre)=free_char(&((*e)->titre));
        free_all_char(&((*e)->fils_droit));
        free_all_char(&((*e)->fils_gauche));
    }
}





