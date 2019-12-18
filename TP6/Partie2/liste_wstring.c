#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "liste_wstring.h"

void init_liste_wstring (struct liste_wstring* L)
{
    L->tete = (struct maillon_wstring*)0;
    L->nbelem = 0;
}

void ajouter_en_tete_liste_wstring (struct liste_wstring* L, wstring d, wstring e)
{   struct maillon_wstring* nouveau;

    nouveau = (struct maillon_wstring*)malloc (sizeof (struct maillon_wstring));
    assert (nouveau != (struct maillon_wstring*)0);
/* appeler ici un éventuel constructeur pour nouveau->value */
    wcscpy(nouveau->clef, d);       /* affectation de la valeur */
    wcscpy(nouveau->satellite, e);
    nouveau->next = L->tete;
    L->tete = nouveau;
    L->nbelem += 1;
}

void clear_liste_wstring (struct liste_wstring* L)
{   struct maillon_wstring* courant;
    struct maillon_wstring* suivant;
    int i;

    courant = L->tete;
    for (i = 0; i < L->nbelem; i++)
    {   suivant = courant->next;
/* appeler ici un éventuel destructeur pour nouveau->value */
        free (courant);
        courant = suivant;
    }
}

wchar_t* rechercher_liste_wstring(struct liste_wstring* a,wstring x)
{
    wstring val;
    struct maillon_wstring* m;
    m = a->tete;
    if(m != (struct maillon_wstring*)0)
    {
        wcscpy(val,a->tete->clef);
        m = a->tete->next;
        while(wcscmp(val,x) != 0 && m != (struct maillon_wstring*)0)
        {
            wcscpy(val, m->clef);
            m = m->next;
        }
        if(wcscmp(x,val) == 0) return m->satellite;
        else return (wchar_t*)0;
    }else
        return (wchar_t*)0;
}

void imprimer_liste_wstring (struct liste_wstring* L)
{   struct maillon_wstring* M;
    int i;

    printf ("[");
    M = L->tete;
    for (i = 0; i < L->nbelem; i++)
    {   
        if (i == 0)
        {
            wprintf (L"%ls : %ls", M->clef,M->satellite);
        }
        else
            wprintf (L", %ls : %ls", M->clef,M->satellite);
        M = M->next;
    }
    printf ("]\n");
}
