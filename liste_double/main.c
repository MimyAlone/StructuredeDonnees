#include "liste_double.h"

int main ()
{   struct liste_double A;

    init_liste_double (&A);

    ajouter_en_tete_liste_double (&A, -0.1);
    ajouter_en_tete_liste_double (&A, 0.0);
    ajouter_en_tete_liste_double (&A, 3.14);

    imprimer_liste_double (&A);

    clear_liste_double (&A);
    return 0;
}
