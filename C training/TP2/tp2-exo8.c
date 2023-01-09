#include <stdio.h>

_Bool perf(unsigned int n){
    unsigned int somme = 0;

    for(unsigned int x = n; x >= 1; x--){
        if(n%x == 0){somme += x;}
    }
    if(somme == 2 * n){return 1;}
    else{return 0;}
}

int main(){
    unsigned int a, b;
    printf("Saisissez deux entiers naturels a et b :\n");
    printf("Valeur de a : ");
    scanf("%u", &a);
    printf("Valeur de b : ");
    scanf("%u", &b);

    unsigned int cpt = 0;
    for(unsigned int x = b; x >= a; x--){
        if(perf(x)){printf("%u est un nombre parfait\n", x); cpt++;}
    }
    printf("Il y a %u nombres parfaits en %u et %u", cpt, a, b);

    return 0;
}