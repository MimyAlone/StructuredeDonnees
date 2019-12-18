#if ! defined (LISTE_POINT_H)
#define LISTE_POINT_H 1

/**********************************************************************
 * IMPLANTATION
 * 
 * Spécification de l'implantation
 * 
 * Implantation des listes simplement chaînées de points
 * 
 * Les maillons sont alloués dynamiquement. 
 * Le champ next du dernier maillon vaut (struct maillon_point*)0
 * 
 * Le champ tete d'une liste pointe vers le premier maillon
 * Le champ nbelem est égal au nombre de maillons de la liste
 * La liste vide est codée par (tete, nbelem) = ((struct maillon_point*)0, 0)
 *
 * Des listes distinctes ont des maillons distincts (pas de maillon partagé).
 **********************************************************************/

struct maillon_point
{   struct point* value;
    struct maillon_point* next;
};

struct liste_point
{   struct maillon_point* tete;
    int nbelem;
};

/**********************************************************************
 * PROTOTYPES DES FONCTIONS (TYPE ABSTRAIT)
 **********************************************************************/

/* 
 * Constructeur. Initialise son paramètre à la liste vide 
 */

extern void init_liste_point (struct liste_point*);

/* 
 * Destructeur 
 */

extern void clear_liste_point (struct liste_point*);

/* 
 * Affecte une copie de src à dst 
 */

extern void set_liste_point 
        (struct liste_point* dst, struct liste_point* src);

/* 
 * Ajout d'un point en tête de liste 
 */

extern void ajouter_en_tete_liste_point (struct liste_point*, struct point*);

/* 
 * Affecte à *d la valeur du premier élément de L et supprime cet élément de L. 
 * La liste L est supposée non vide.
 */

extern void extraire_tete_liste_point (struct point* d, struct liste_point* L);

/* 
 * Impression. 
 */

// extern void imprimer_liste_point (struct liste_point*);
#endif
