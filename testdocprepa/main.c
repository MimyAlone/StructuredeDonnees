//main.c

#include <stdio.h>
#include <string.h>

int main(){
    
    char txt[30];
    int id;
    char gender[10];
    float age;
    long double spnbmd;
    
    if(scanf("%s",txt)>0)
    {
        scanf("%s",txt);
        scanf("%s",txt);
        scanf("%s",txt);
        while(scanf("%d",&id)>0)
        {
            scanf("%f",&age);
            scanf("%s",gender);
            scanf("%Lf",&spnbmd);
            printf("%d %f %s %Lf\n", id,age,gender,spnbmd);
        }
    }
    
    return 0;
}
