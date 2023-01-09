/*
*/

#include <stdio.h>

int main(){
    int n;
    
    printf("Saisissez un entier : ");
    scanf("%d", &n);

    if(n <= 1)
        {printf("%d n'est pas premier : il est inférieur ou égal à 1.", n);}
    else{
        int cpt = 0;
        int x = n;
        while(x>0){
            if(n%x == 0){cpt++; x--;}
            else{x--;}
            printf("%d ", cpt);}
        if(cpt > 2){printf("%d n'est pas premier", n);}
        else{printf("%d est premier : il a moins de 2 diviseurs.", n);}
    }
    return 0;
}