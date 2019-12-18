//abr.h
#include <wchar.h>
#define MAXLEN 80
#define NIL (struct abr*)0

typedef wchar_t wstring [MAXLEN];

struct abr{
    wchar_t clef, donneeSat;
	struct abr* droit;
	struct abr* gauche;
};

/* Spécifications de la structure de données :
*	chaque noeud (dont la racine possède une valeur
*	si la valeur suivante est inférieure au noeud actuel, la valeur est placé dans un noeud de l'arbre de gauche et inversement
*/

extern struct abr* ajouter_abr(wchar_t,wchar_t, struct abr*);
extern void afficher_abr(struct abr*);
extern int hauteur_abr(struct abr*);
extern int nombre_noeuds_abr(struct abr*);
extern void clear_abr(struct abr*);
extern wchar_t* recherche_abr(wchar_t,struct abr*);
