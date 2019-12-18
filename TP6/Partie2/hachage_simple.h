#include "liste_wstring.h"
#include <stdbool.h>

struct alveole{
	struct liste_wstring L;
};

typedef int fonction_hachage(wstring);

#define N 10

struct table{
	struct alveole tab[N];
	fonction_hachage* hash;
};

extern void init_table(struct table*, fonction_hachage*);
extern void clear_table(struct table*);
extern void enregistrer_table(struct table*,wstring,wstring);
extern bool rechercher_table(struct table*,wstring);
extern void imprimer_table(struct table*);
