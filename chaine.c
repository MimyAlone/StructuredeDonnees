//Chaine.c

#include <stdio.h>
#include "chaine.h"
#include <stdlib.h>
#include <string.h>

void init_chaine(struct chaine *A){
	A->L =(struct liste_char*)malloc(sizeof(struct liste_char));
	init_liste_char(A->L);
}

void clear_chaine(struct chaine *A){
	clear_liste_char(A->L);
}

void ajout_chaine(struct chaine *A, char B){
	ajouter_en_tete_liste_char(A->L,B);
}

void print_chaine(struct chaine *A){
    imprimer_liste_char(A->L);
}



