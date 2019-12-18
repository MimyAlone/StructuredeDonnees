#include "abrWchar_t.h"
#include <stdio.h>
#include <locale.h>
#include <wctype.h>
#include <assert.h>


int main()
{
	struct abr* racine;
	wstring clef;
    wstring satellite;
    wint_t c;
    FILE* f;
    
    assert(setlocale(LC_ALL,"C.UTF-8") != NULL);
    f = fopen("Esperanto-Francais.utf8","r");
    assert(f != (FILE*)0);
    
    racine = NIL;
    c = fgetwc(f);
    while(c != WEOF)
    {   int i = 0;
        while(c != L':')
        {   clef[i] = c;
            i+=1;
            c = fgetwc(f);
        }
        clef[i] = L'\0';
        c = fgetwc(f);
        i = 0;
        while(c!= L'\n')
        {   satellite[i] = c;
            i+=1;
            c = fgetwc(f);
        }
        satellite[i] = L'\0';
        racine = ajout_abr(clef,satellite,racine);
        c=getwc(f);
    }
    fclose(f);
    
    clear_abr(racine);
    return (0);
}
