#ifndef Menu_h
#define Menu_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAILLE_TITRE      100
#define TAILLE_CONTENU  10000
#define TEXT_MAX      1000000


#include "Encyclopedie.h"



void purger(void);

void options();
void selection(int key,EncyclopedieTab e);
void first_menu(EncyclopedieTab e);



 #endif
