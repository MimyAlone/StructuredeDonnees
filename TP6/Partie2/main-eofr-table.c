/* main-eofr-table.c */

#include <locale.h>
#include <wctype.h>
#include <assert.h>
#include <stdio.h>
#include "hachage_simple.h"

int hachage_basique (wstring clef)
{   wint_t result;
    int i;
    result = 0;
    for (i = 0; clef [i] != L'\0'; i++)
        result = (result + (wint_t)clef [i]) % (wint_t)N;
    return (int)result;
}

int main ()
{   struct table T;
    wstring clef;
    wstring satellite;
    wint_t c;
    FILE* f;

    assert (setlocale (LC_ALL, "C.UTF-8") != NULL);
//  f = fopen ("Esperanto-Francais.utf8", "r");
    f = fopen ("Esperanto-Francais.demo", "r");
    assert (f != (FILE*)0);
    init_table (&T, &hachage_basique);
    c = fgetwc (f);
    while (c != WEOF)
    {   int i = 0;
        while (c != L':')
        {   clef [i++] = c;
            c = fgetwc (f);
        }
        clef [i] = L'\0';
        c = fgetwc (f);
        i = 0;
        while (c != L'\n')
        {   satellite [i++] = c;
            c = fgetwc (f);
        }
        satellite [i] = L'\0';
//         wprintf(L"%ls : %ls \n", clef,satellite);
        enregistrer_table (&T, clef, satellite);
        c = fgetwc (f);
    }
    fclose (f);
    imprimer_table (&T);
    clear_table (&T);
    return 0;
}

