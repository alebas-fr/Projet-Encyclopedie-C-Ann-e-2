//
//  main.c
//  Table_hachage
//
//  Created by Alexandre Lebas on 15/11/2018.
//  Copyright © 2018 Alexandre Lebas. All rights reserved.
//

#include "Encyclopedie.h"


int main(int argc, const char * argv[]) {
    EncyclopedieTab Wikipedia;


    Wikipedia=creer_encyclopedie(); //cr»e l'encyclopedie
    clock_t clock1=clock();
    //test(Larousse);
    Wikipedia = fichier_test();
    clock_t clock2=clock();
    printf("TEMPS POUR CHARGER = %f",(double)(clock2-clock1));
    //Wikipedia = initialisation(Wikipedia); test remy
    first_menu(Wikipedia); //lance le menu principal

    return 0;
}

