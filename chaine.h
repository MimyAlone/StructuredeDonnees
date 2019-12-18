#include "liste_char.h"

//Chaine.h
struct chaine{
	struct liste_char* L;
};

//Spécification
//Le champ doit pointer vers une zone alloué dynamiquement
//0 < pointeurDernierCaractere < longueurChaine 

//Prototypes des fonctions
//Initialise A à un charactère B
extern void init_chaine(struct chaine *A);

//Supprime la chaine A
extern void clear_chaine(struct chaine *A);

//Ajoute un caractère à la fin d'une chaine
extern void ajout_chaine(struct chaine *A, char B);

//Affiche la chaine
extern void print_chaine(struct chaine *A);
