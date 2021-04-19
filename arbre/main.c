//
//  main.c
//  ABR_19_11_8h23
//
//  Created by Alexandre Lebas on 19/11/2018.
//  Copyright © 2018 Alexandre Lebas & Océane Deletrez. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Encyclopedie.h"
#include "test.h"

int main() {

    // Declaration npour voir combien de temps l'arbre binaire de recherche est créé

    clock_t clock2;
    Encyclopedie Larousse;
    Larousse = Creer_encyclopedie();

    Encyclopedie Wikipedia; //initialisation
    //Wikipedia = Creer_encyclopedie(); //cree l'encyclopedie (pour les test)

    //test(Larousse);
    clock_t clock1=clock();
    Wikipedia = fichier_test();
    clock2=clock();
    printf("TEMPS POUR CHARGER = %f",(double)(clock2-clock1));
    //clock_t test_1=1000; // pour mon systeme correspont à 1 secondes
    //printf("Conversion %f %f\n\n",(double)(test_1/CLOCKS_PER_SEC),(double)test_1);
    first_menu(Wikipedia); //lance le menu principal


    return 0;
}

