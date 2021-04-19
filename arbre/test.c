
#include "test.h"



 void test(Encyclopedie Larousse){
    Encyclopedie Recherche_element=NULL;
    char *rech;
    char testx[] = "test";
    char testzx[] = "teast";

    Larousse = inserer(Larousse,32,testx,testx);
    Larousse = inserer(Larousse,2,testx,testx);
    //Larousse = inserer(Larousse,1,test,test);
    Larousse = inserer(Larousse,7,testx,testx);
    Larousse = inserer(Larousse,6,testx,testx);
    Larousse = inserer(Larousse,9,testx,testx);
    Larousse = inserer(Larousse,3,testx,testx);
    Larousse = inserer(Larousse,11,testx,testx);
    Larousse = inserer(Larousse,23,testx,testx);
    Larousse = inserer(Larousse,45,testx,testx);
    Larousse = inserer(Larousse,4,testx,testx);
    Larousse = inserer(Larousse,57,testx,testx);
    Larousse = inserer(Larousse,100,testx,testx);
    Larousse = inserer(Larousse,98,testzx,testzx);
    Larousse = inserer(Larousse,25,testx,testx);
    Larousse = inserer(Larousse,26,testx,testx);
    Larousse = inserer(Larousse,43,testx,testx);
    afficher_Encyclopedie_infixe_rec(Larousse,0);
    supprime2(Larousse,2);
    	printf("\nNOUVEAU ARBRE\n\n");
	afficher_Encyclopedie_infixe_rec(Larousse,0);
    supprime2(Larousse,25);
    	printf("\nNOUVEAU ARBRE\n\n");
	afficher_Encyclopedie_infixe_rec(Larousse,0);
    supprime2(Larousse,7);
    	printf("\nNOUVEAU ARBRE\n\n");
	afficher_Encyclopedie_infixe_rec(Larousse,0);
	    supprime2(Larousse,11);
    	printf("\nNOUVEAU ARBRE\n\n");
	afficher_Encyclopedie_infixe_rec(Larousse,0);
	 supprime2(Larousse,45);
    	printf("\nNOUVEAU ARBRE\n\n");
	afficher_Encyclopedie_infixe_rec(Larousse,0);


	//PARTIE 2

/*
     char test1[]="alex";
     char test2[]="erwan";
    Larousse = inserer(Larousse,1,testx,testx);
    Larousse = inserer(Larousse,2,testx,test1);
    //Larousse = inserer(Larousse,1,test,test);
    Larousse = inserer(Larousse,7,testx,testx);
    Larousse = inserer(Larousse,6,testx,testx);
    Larousse = inserer(Larousse,9,testx,testx);
    Larousse = inserer(Larousse,3,testx,testx);
    Larousse = inserer(Larousse,6,testx,testx);
    afficher_Encyclopedie_infixe_rec(Larousse,0);
     Recherche_element=rechercher_article(Larousse,9);
     Recherche_element=rechercher_article(Larousse,10);
     Encyclopedie recherche=NULL;
     recherche=recherche_article_plein_texte(Larousse,testx);
     afficher_Encyclopedie_infixe_rec(recherche,10);
     printf("\n\n");
     recherche=recherche_article_plein_texte(Larousse,test1);
     afficher_Encyclopedie_infixe_rec(recherche,0);
     recherche=recherche_article_plein_texte(Larousse,test2);
     afficher_Encyclopedie_infixe_rec(recherche,0);
     supprime_encyclopedie(&recherche);
     afficher_Encyclopedie_infixe_rec(recherche,0);
     supprime_encyclopedie(&Larousse);
     afficher_Encyclopedie_infixe_rec(Larousse,0);

    */
        rech= rechercher_article(Larousse,98);
    //printf("%s",rech);
   fichier_test();




 }
