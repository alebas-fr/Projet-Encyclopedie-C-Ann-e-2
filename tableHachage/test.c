
#include"test.h"

void test(){
   printf("%d \n\n",TAILLE);
    Encyclopedie tab[TAILLE];
    int i=0;
    for (i=0;i<TAILLE;i++) {
        tab[i]=NULL;
    }
    unsigned long i1=1,i2=2,i3=3,i4=4;
    char t1[]="alex";
    char t2[]="oceane";
    char t3[]="theo";
    char t4[]="erwan";
    char c1[]="ab";
    char c2[]="ab";
    char c3[]="cd";
    char c4[]="cd";
    char test2[]="aaaaa";
    EncyclopedieTab Tab;
    Tab=creer_encyclopedie();
    // RESTE A VOIR POUR FAIRE LE TABLEAUX CAR PLANTE

    Tab=inserer(Tab,i1,t1,c1);
    Tab=inserer(Tab,i2,t2,c2);
    Tab=inserer(Tab,i3,t3,c3);
    Tab=inserer(Tab,i1,t1,c1);
    Tab=inserer(Tab,i4,t4,c4);
    AfficherTab(Tab);
    printf("1\n\n");
    Tab=supprimer(Tab,i3);
    Tab=supprimer(Tab,6);
    AfficherTab(Tab);
    printf("2\n\n");
    char* test=NULL;
    test=recherche_article(Tab,i1);
    printf("%s\n\n",test);
    test=recherche_article(Tab,i4);
    printf("%s\n\n",test);
    test=recherche_article(Tab,5);
    printf("%s\n\n",test);
    EncyclopedieTab recherche;
    recherche=creer_encyclopedie();
    recherche=recherche_article_plein_texte(Tab,c1);
    AfficherTab(recherche);
    printf("TEST\n\n");
    detruire_encyclopedie(&recherche);
    AfficherTab(recherche);
    recherche=recherche_article_plein_texte(recherche,test2);
    AfficherTab(recherche);
    detruire_encyclopedie(&recherche);
    detruire_encyclopedie(&Tab);
    AfficherTab(Tab);
    printf("Ca a marche \n\n");

}
