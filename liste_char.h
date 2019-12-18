#include <wchar.h>

#if ! defined (liste_char_H)
#define liste_char_H 1

/**********************************************************************
 * IMPLANTATION
 * 
 * Spécification de l'implantation
 * 
 * Implantation des listes simplement chaînées de chars
 * 
 * Les maillons sont alloués dynamiquement. 
 * Le champ next du dernier maillon vaut (struct maillon_char*)0
 * 
 * Le champ tete d'une liste pointe vers le premier maillon
 * Le champ nbelem est égal au nombre de maillons de la liste
 * La liste vide est codée par (tete, nbelem) = ((struct maillon_char*)0, 0)
 *
 * Des listes distinctes ont des maillons distincts (pas de maillon partagé).
 **********************************************************************/

struct maillon_char
{   wchar_t value;
    struct maillon_char* next;
};

struct liste_char
{   struct maillon_char* tete;
    int nbelem;
};

/**********************************************************************
 * PROTOTYPES DES FONCTIONS (TYPE ABSTRAIT)
 **********************************************************************/

/* 
 * Constructeur. Initialise son paramètre à la liste vide 
 */

extern void init_liste_char (struct liste_char*);

/* 
 * Destructeur 
 */

extern void clear_liste_char (struct liste_char*);

/* 
 * Affecte une copie de src à dst 
 */

extern void set_liste_char 
        (struct liste_char* dst, struct liste_char* src);

/* 
 * Ajout d'un char en tête de liste 
 */

extern void ajouter_en_tete_liste_char (struct liste_char*, char);


extern void ajouter_en_queue_liste_char(struct liste_char*, char);
/* 
 * Affecte à *d la valeur du premier élément de L et supprime cet élément de L. 
 * La liste L est supposée non vide.
 */

extern void extraire_tete_liste_char (char* d, struct liste_char* L);

/* 
 * Impression. 
 */

extern void imprimer_liste_char (struct liste_char*);
#endif
