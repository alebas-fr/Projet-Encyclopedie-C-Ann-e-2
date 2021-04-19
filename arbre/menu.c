#include "menu.h"
#include "test.h"


void options(){
printf("\n------------------------------------------------------\n");
    printf("(1): Inserer un article)\n");
    printf("(2): Supprimer un article\n");
    printf("(3): Rechercher le contenu d'un article\n");
    printf("(4): Rechercher le titre d'un article\n");
    printf("(5): afficher la liste des id\n");
    printf("(6): rechercher un article plein texte\n");
    printf("(7): supprimer l'encyclopedie\n");
    printf("(9): quitter\n");
    printf("------------------------------------------------------\n");
}
/*
void purger(void)
{
    int c;

    while ((c= getchar() )!= '\n' && c != EOF ) {

    }
}
*/
void first_menu(Encyclopedie e){
    int key = 0;
    options();
    while(key != 1  && key != 2 && key != 3 && key !=4 && key != 5){
        scanf("%d",&key);
        selection(key,e);
        printf("Incorrect !\n");
    }
}

void selection(int key,Encyclopedie e)
{
    unsigned long id;
    char *contenu;
    char *titre;
    int i;
    scanf ( "%*[^\n]" );
    Encyclopedie contenuRecherche;
    char mot[TAILLE_TITRE];
        //char contenu[TAILLE_CONTENU];
            switch (key) {
                case 1: //Pour inserer un article wikipedia
                    //purger();
                        //Recuperation de l'id

                            printf("Id de l'article ?\n");
                            scanf("%lu",&id);
                       //Recupération du titre
                            printf("Titre :\n");
                            titre=malloc(sizeof(char)*TAILLE_TITRE);
                            //fgets (chaîne , taille , flot-de-données) a utiliser pour le truc de donnee
                            scanf("%s",titre);
                        //Recuperation du contenu
                            printf("Contenu :\n");
                            contenu=malloc(sizeof(char)*TAILLE_CONTENU);
                            scanf("%s",contenu);
                        //Verification du contenu
                            printf("Le numero de l'article prit en compte est :  %lu\n",id);
                            printf("Le titre est :  %s\n",titre);
                            printf("Le contenu est :  %s\n",contenu);
                            clock_t fin_ins;
                            clock_t debut_ins=clock();
                        e = inserer(e,id,titre,contenu);
                        fin_ins=clock();
                        afficher_encyclopedie(e,0); //Affiche l'arbre
                        printf("\n\nTEMPS INSERTION %f - %f = %f\n\n",(double)fin_ins,(double) debut_ins,(double)(fin_ins-debut_ins));
                        first_menu(e);

                    break;

                case 2: //Pour supprimer un article
                        //Recuperation de l'id

                            printf("Id de l'article ?\n");
                            scanf("%lu",&id);
                        e->contenu=free_char(&(e->contenu));
                        e->titre=free_char(&(e->titre));
                        clock_t fin_sup;
                        clock_t debut_sup=clock();
                        e= supprime2(e,id);
                        fin_sup=clock();
                        afficher_encyclopedie(e,0); //Affiche l'arbre
                        printf("\n\nTEMPS SUPPRESSION %f - %f = %f\n\n",(double)fin_sup,(double)debut_sup,(double)(fin_sup-debut_sup));
                        first_menu(e);
                        break;

                case 3: //Pour rechercher un article (contenu)
                        //printf("Bientot disponible\n");
                         printf("Id de l'article ?\n");
                         scanf("%lu",&id);
                        clock_t fin_rech;
                        clock_t debut_rech=clock();
                               contenuRecherche = rechercher_article(e,id);
                               fin_rech=clock();
                               printf("\n Le contenu de l'article %lu est : \n %s",id,contenuRecherche); 
                        printf("\n\nTEMPS RECHERCHE = %f\n\n",(double)(fin_rech-debut_rech));
                    first_menu(e);
                    break;

                case 4:  //pour rechercher un article titre
                    printf("Id de l'article ?\n");
                         scanf("%lu",&id);

                               contenuRecherche = rechercher_article_titre(e,id);
                               printf("\n Le titre de l'article %lu est : \n %s",id,contenuRecherche); 
                    first_menu(e);
                    break;

                case 5: //Pour afficher la liste id
                    afficher_Encyclopedie_infixe_rec(e,0);
                    first_menu(e);
                    break;

                case 6: //Pour rechercher un article pein texte
                    printf("Mot recherche?\n");
                    scanf("%s",mot);
                    clock_t fin_rechpl;
                    clock_t debut_rechpl=clock();
                    contenuRecherche = recherche_article_plein_texte(e,mot);
                    afficher_Encyclopedie_parliste(contenuRecherche,0);
                    fin_rechpl=clock();
                    supprime_encyclopedie(&contenuRecherche);
                    clock_t time_recherche_plein_texte=fin_rechpl-debut_rechpl;
                    printf("\n\nTEMPS RECHERCHE PLEIN MOT = %f\n\n",(double)(time_recherche_plein_texte));
                    first_menu(e);
                    break;

                case 7: //Pour supprimer encyclopedie
                    free_all_char(&e);
                    clock_t debut_supp_b=clock();
                    supprime_encyclopedie(&e);
                    clock_t fin_sup_b=clock();
                    printf("\nverification :");
                    afficher_Encyclopedie_infixe_rec(e,0);
                    afficher_Encyclopedie_parliste(e,0);
                    printf("\n\nTEMPS SUPPRESSION BIBLIOTHEQUE = %f\n\n",(double)(fin_sup_b-debut_supp_b));
                    first_menu(e);
                    break;

             case 8: //Pour tout afficher test
                    afficher_Encyclopedie_parliste(e,0);
                    first_menu(e);
                    break;

                case 9: //Pour Quitter
                    free_all_char(&e);
                    supprime_encyclopedie(&e);
                    printf("Au revoir \n");
                    getchar();
                    exit(0);
                    break;




                default:
                    break;
            }



}

