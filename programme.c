#include <stdio.h>
#include "chaine.h"
#include <ctype.h>

int main(){
	struct chaine s; int c;
	
	c = getchar();
    init_chaine(&s,c);
    
	while(! (isspace(c))){
        c = getchar();
		ajout_chaine(&s,c);
	}
	print_chaine(&s);
	clear_chaine(&s);
	return 0;
}
