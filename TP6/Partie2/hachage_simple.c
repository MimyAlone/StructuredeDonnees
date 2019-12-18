/*hachage_simple.c*/
#include "hachage_simple.h"
#include <stdlib.h>
#include <stdio.h>



void init_table(struct table* a, fonction_hachage* f)
{
	for(int i=0; i<N;i++)
	{
		init_liste_wstring(&(a->tab[i].L));
	}
	a->hash = f;
}

void clear_table(struct table* a)
{
	for(int i=0;i<N;i++)
	{
		clear_liste_wstring(&(a->tab[i].L));
	}
}

void enregistrer_table(struct table* a, wstring x,wstring e)
{
	int ind;
	ind = a->hash(x);
	ajouter_en_tete_liste_wstring(&(a->tab[ind].L),x,e);
}

bool rechercher_table(struct table* a, wstring x)
{
	int ind;
	struct maillon_wstring* m;
	ind = a->hash(x);
    if((rechercher_liste_wstring(&(a->tab[ind].L),x)) == (wchar_t*)0)
    {
        return false;
    }else{
        return true;
    }
}

void imprimer_table(struct table* a)
{
	for(int i=0;i<N;i++)
	{
		imprimer_liste_wstring(&(a->tab[i].L));
	}
}
