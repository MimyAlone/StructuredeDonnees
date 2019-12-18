#include "abrValeurEntiere.h"
#include <stdio.h>
#define NIL (struct abr*)0

int main()
{
	struct abr* racine;
	int x;
	racine = NIL;
	scanf("%d",&x);
	while (x!= -1)
	{
		racine = ajouter_abr(x,racine);
		afficher_abr(racine);
		scanf("%d",&x);
	}
	printf("la hauteur de l'ABR est %d\n", hauteur_abr(racine));
	printf("le nombre de noeuds de l'ABR est %d\n", nombre_noeuds_abr(racine));
	imprimer_abr(racine);
	clear_abr(racine);
	return 0;
}
