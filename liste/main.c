//
//  main.c
//  LISTE_CHAINE_2
//
//  Created by Alexandre Lebas on 16/11/2018.
//  Copyright © 2018 Alexandre Lebas. All rights reserved.
//
#include <stdio.h>
#include <time.h>
#include "Encyclopedie.h"


int main(int argc, const char * argv[]) {
    Encyclopedie Larousse;
    Larousse = Creer_encyclopedie();
    clock_t clock2;
    Encyclopedie Wikipedia; //initialisation
    //Wikipedia = Creer_encyclopedie(); //crÈe l'encyclopedie

    //test(Larousse);
    clock_t clock1=clock();
    Wikipedia = fichier_test();
    clock2=clock();
    printf("TEMPS POUR CHARGER = %f",(double)(clock2-clock1));
    //Wikipedia = initialisation(Wikipedia); test remy
    first_menu(Wikipedia); //lance le menu principal
    return 0;
}
