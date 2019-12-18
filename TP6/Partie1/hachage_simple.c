/*hachage_simple.c*/
#include "hachage_simple.h"
#include <stdlib.h>
#include <stdio.h>



void init_table(struct table* a, fonction_hachage* f)
{
	for(int i=0; i<N;i++)
	{
		init_liste_double(&(a->tab[i].L));
	}
	a->hash = f;
}

void clear_table(struct table* a)
{
	for(int i=0;i<N;i++)
	{
		clear_liste_double(&(a->tab[i].L));
	}
}

void enregistrer_table(struct table* a, double x)
{
	int ind;
	ind = a->hash(x);
	ajouter_en_tete_liste_double(&(a->tab[ind].L),x);
}

bool rechercher_table(struct table* a, double x)
{
	int val,ind;
	struct maillon_double* m;
	ind = a->hash(x);
	if(a->tab[ind].L.tete != NIL)
	{
		val = a->tab[ind].L.tete->value;
		m = a->tab[ind].L.tete->next;
		while(val != x && m != NIL)
		{
			val = m->value;
			m = m->next;
		}
		if(x == val) return true;
		else return false;
	}else
		return false;
}

void imprimer_table(struct table* a)
{
	for(int i=0;i<N;i++)
	{
		imprimer_liste_double(&(a->tab[i].L));
	}
}
