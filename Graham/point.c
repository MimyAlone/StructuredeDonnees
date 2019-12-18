/*point.c*/
#include "point.h"

void init_point(struct point* p, double x, double y, char id)
{
    p->x = x;
    p->y = y;
    p-> ident = id;
}

int compare_points(const void* p0, const void* q0)
{
    struct point* p = (struct point*) p0;
    struct point* q = (struct point*) q0;
    
    if((((p->x)*(q->y))-((p->y)*(q->x))) < 0) return 1;
    else return -1;
}

bool tourne_a_gauche(struct point* A, struct point* B, struct point* C)
{
    if( (((B->x - A->x)*(C->y - A->y))-((C->x - A->x)*(B->y - A->y))) > 0)
    {
        return true;
    }else
    {
        return false;
    }
}
