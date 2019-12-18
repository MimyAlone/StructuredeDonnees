/*main.c*/

#include <stdio.h>
#include "hachage_simple.h"

int hachage_basique(double d)
{
return (int)d%N;
}

int main()
{
	struct table T;
	double x;

	init_table(&T,&hachage_basique);
	scanf("%lf",&x);    
	while(x != -1)
	{
		enregistrer_table(&T,x);
		imprimer_table(&T);
		scanf("%lf",&x);
	}
    
    if(rechercher_table(&T,4))
    {
        printf("Valeur retrouvé\n");
    }else
    {
        printf("Valeur non trouvé\n");
    }
	clear_table(&T);
	return 0;
}
