#include "menu.h"


void options(){
printf("\n------------------------------------------------------\n");
    printf("(1): Inserer un article)\n");
    printf("(2): Supprimer un article\n");
    printf("(3): Rechercher le contenu d'un article\n");
    printf("(6): rechercher un article plein texte\n");
    printf("(7): supprimer l'encyclopedie\n");
    printf("(8): Voir le contenu de l'encyclopedie\n");
    printf("(9): quitter\n");
    printf("------------------------------------------------------\n");
}

void first_menu(EncyclopedieTab e){
    int key = 0;
    options();
    while(key != 1  && key != 2 && key != 3 && key != 6 && key !=7 && key != 8 ){
        scanf("%d",&key);
        selection(key,e);
        printf("Incorrect !\n");
    }
}

void selection(int key,EncyclopedieTab e)
{
    unsigned long id;
    char contenu[TAILLE_CONTENU];
    char titre[TAILLE_TITRE];
    int i;
    scanf ( "%*[^\n]" );
    char *contenuRecherche;
    EncyclopedieTab contenue_recherche_plein=creer_encyclopedie();
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
                            //fgets (chaîne , taille , flot-de-données) a utiliser pour le truc de donnee
                            scanf("%s",titre);
                        //Recuperation du contenu
                            printf("Contenu :\n");
                            scanf("%s",contenu);
                        //Verification du contenu
                            printf("Le numero de l'article prit en compte est :  %lu\n",id);
                            printf("Le titre est :  %s\n",titre);
                            printf("Le contenu est :  %s\n",contenu);
                            clock_t fin_ins;
                            clock_t debut_ins=clock();
                        e = inserer(e,id,titre,contenu);
                        fin_ins=clock();
                        AfficherTab(e); //Affiche
                        printf("\n\nTEMPS INSERTION %f - %f = %f\n\n",(double)fin_ins,(double) debut_ins,(double)(fin_ins-debut_ins));
                        first_menu(e);

                    break;

                case 2: //Pour supprimer un article
                        //Recuperation de l'id

                            printf("Id de l'article ?\n");
                            scanf("%lu",&id);
                        clock_t fin_sup;
                        clock_t debut_sup=clock();
                        e= supprimer(e,id);
                        fin_sup=clock();
                        AfficherTab(e); //Affiche
                        printf("\n\nTEMPS SUPPRESSION %f - %f = %f\n\n",(double)fin_sup,(double)debut_sup,(double)(fin_sup-debut_sup));
                        first_menu(e);
                        break;

                case 3: //Pour rechercher un article (contenu)
                        //printf("Bientot disponible\n");
                         printf("Id de l'article ?\n");
                         scanf("%lu",&id);
                        clock_t fin_rech;
                        clock_t debut_rech=clock();
                               contenuRecherche = recherche_article(e,id);
                               fin_rech=clock();
                               printf("\n Le contenu de l'article %lu est : \n %s",id,contenuRecherche);
                               printf("\n\nTEMPS RECHERCHE = %f\n\n",(double)(fin_rech-debut_rech));
                    first_menu(e);
                    break;

                case 6: //Pour rechercher un article plein texte
                    printf("Mot recherche?\n");
                    scanf("%s",mot);
                    clock_t fin_rechpl;
                    clock_t debut_rechpl=clock();
                    contenue_recherche_plein=recherche_article_plein_texte(e,mot);
                    fin_rechpl=clock();
                    AfficherTab(contenue_recherche_plein);
                    detruire_encyclopedie(&contenue_recherche_plein);
                    clock_t time_recherche_plein_texte=fin_rechpl-debut_rechpl;
                    printf("\n\nTEMPS RECHERCHE PLEIN MOT = %f\n\n",(double)(time_recherche_plein_texte));
                    first_menu(e);
                    break;

                case 7: //Pour supprimer encyclopedie
                    e=free_all_char(e);
                    clock_t debut_supp_b=clock();
                    detruire_encyclopedie(&e);
                    clock_t fin_sup_b=clock();
                    printf("\nverification :");
                    AfficherTab(e);
                    printf("\n\nTEMPS SUPPRESSION BIBLIOTHEQUE = %f\n\n",(double)(fin_sup_b-debut_supp_b));
                    first_menu(e);
                    break;

             case 8: //Pour tout afficher test
                    AfficherTab(e);
                    first_menu(e);
                    break;
                case 9: //Pour Quitter
                    e=free_all_char(e);
                    detruire_encyclopedie(&e);
                    exit(0);
                    break;




                default:
                    break;
            }



}

