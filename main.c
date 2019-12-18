#include <stdio.h>
#include "chaine.h"
#include <ctype.h>

int main(){
	struct chaine s; int c;
	
	c = getchar();
	init_chaine(&s);
    
	while(! (isspace(c))){
        	ajout_chaine(&s,c);
		c = getchar();
	}
	print_chaine(&s);
	clear_chaine(&s);
	return 0;
}
