#include"test.h"

void test(){
    unsigned long i1=1,i2=2,i3=3,i4=4;
    char t1[]="alex";
    char t2[]="oceane";
    char t3[]="theo";
    char t4[]="erwan";
    char c1[]="ab";
    char c2[]="ab";
    char c3[]="cd";
    char c4[]="cd";
    Encyclopedie e=Creer_encyclopedie();
    e=supprimer(e,i1);
    e=inserer(e,i1,t1,c1);
    e=inserer(e,i2,t2,c2);
    e=inserer(e,i3,t3,c3);
    e=inserer(e,i4,t4,c4);
    e=supprimer(e,5);
    e=supprimer(e,i1);
    e=inserer(e,i1,t1,c1);
    afficher_liste(e);
    char* test=rechercher_article(e,i1);
    printf("%s \n\n",test);
    test=rechercher_article(e,i2);
    printf("%s \n\n",test);
    test=rechercher_article(e,i3);
    printf("%s \n\n",test);
    test=rechercher_article(e,i4);
    printf("%s \n\n",test);
    Encyclopedie recherche=Creer_encyclopedie();
    char mot1[]="ab";
    char mot2[]="cd";
    char mot3[]="oc";
    recherche=rechercher_article_plein_texte(e, mot1);
    afficher_liste(recherche);
    detruire_bibliotheque(&recherche);
    recherche=Creer_encyclopedie();
    recherche=rechercher_article_plein_texte(e, mot2);
    afficher_liste(recherche);
    detruire_bibliotheque(&recherche);
    recherche=Creer_encyclopedie();
    recherche=rechercher_article_plein_texte(e, mot3);
    afficher_liste(recherche);
    detruire_bibliotheque(&recherche);
    detruire_bibliotheque(&e);
}
