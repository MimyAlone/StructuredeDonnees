#include "abrWchar_t.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define NIL (struct abr*)0

static struct abr* initialiser_abr(wchar_t clef, wchar_t donneSat){
	struct abr* a;
	a = (struct abr*)malloc(sizeof(struct abr));
	wcscpy(&(a->clef),clef);
    wcscpy(&(a->donneeSat),donneeSat);
	a->droit = NIL;
	a->gauche = NIL;
	return a;
}

struct abr* ajouter_abr(wchar_t clef,wchar_t donneeSat, struct abr* r){
	if(r == NIL){
		return initialiser_abr(clef,donneeSat);
	}else{
		if(wcscmp(r->clef,clef)>0){
			r->gauche = ajouter_abr(x,r->gauche);
		}else{
			r->droit = ajouter_abr(x,r->droit);
		}
		return r;
	}
}

void afficher_abr(struct abr* r){
	struct abr* a = r;
	if(a != NIL){
		afficher_abr(a->gauche);
		wprintf(L"%ls:%ls\n", a->clef,a->donneeSat);
		afficher_abr(a->droit);
	}
	wprintf("\n");
}
int isfeuille(struct abr* r){
	if(r->gauche == NIL && r->droit == NIL) return 1;
	else return 0;
}
int hauteur_abr(struct abr* r){
	int h = 0;
	int hg,hd;
	if(r != NIL){
		if(isfeuille(r)) h=1;
		else
		{
			hg = hauteur_abr(r->gauche);
			hd = hauteur_abr(r->droit);
			if(hd > hg) h += hd;
			else h += hg;
		}
	}
	return h;
}

int nombre_noeuds_abr(struct abr* r){
	int n = 0;
	if(r!=NIL){
		n += 1 + nombre_noeuds_abr(r->gauche) + nombre_noeuds_abr(r->droit);
	}
	return n;
}
void clear_abr(struct abr* r){
	if(r != NIL)
	{
		clear_abr(r->gauche);
		clear_abr(r->droit);
		free(r);
	}
}

struct abr* aux(wchar_t donneeSat,struct abr* a){
	if(wcscmp(r->donneeSat,donneeSat)>0){
			r = recherche_abr(donneeSat,r->gauche);
		}else 
        {
            if(wcscmp(r->donneeSat,donneeSat)<0)
            {
                r = recherche_abr(donneeSat,r->droit);
            }
		}
    return r;
}

wchar_t* recherche_abr(wchar_t donneeSat,struct abr* a)
{
    struct abr* r = a;
    if(r == NIL){
		return (wchar_t*)0;
	}else{
		r = aux(donneeSat,r)
		return &(r->clef);
	}
}

// void aux(struct abr* r, FILE* fic){
// 	if(r->gauche != NIL)
// 	{
// 		fprintf(fic, "%d -> %d [label=\"gauche\"];\n", r->valeur, r->gauche->valeur);
// 		aux(r->gauche,fic);
// 	}
// 	if(r->droit)
// 	{
// 		fprintf(fic,"%d -> %d [label=\"droit\"];\n",r->valeur,r->droit->valeur);
// 		aux(r->droit,fic);
// 	}
// }
// 
// void imprimer_abr(struct abr* r)
// {
// 	FILE* fic;
// 	fic = fopen("ABR.dot","w");
// 	assert(fic != NULL);
// 	fprintf(fic, "digraph G {\n");
// 	if(r == NIL)
// 		fprintf(fic,"	NIL;\n");
// 	else if(isfeuille(r))
//     {fprintf(fic, "	%d;\n",r->valeur);}
//     else
//     {aux(r,fic);}
// 	fprintf(fic,"}\n");
// 	fclose(fic);
// 	system("dot -Tpdf ABR.dot -Grankdir=LR -o ABR.pdf");
// 	system("evince ABR.pdf");
// }

