#include <stdio.h>

int main(){
    unsigned int n;
    
    printf("Saisissez un entier naturel : ");
    scanf("%u", &n);

    unsigned int somme = 0;
    for(unsigned int x = n; x >= 1; x--){
        if(n%x == 0){somme += x;}
    }
    if(somme == 2 * n){printf("%u est parfait", n);}
    else{printf("%u n'est pas parfait", n);}

    return 0;
}