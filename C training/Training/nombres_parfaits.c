#include "nombres_parfaits.h"

int sommeDiv(int n){
    int somme = 0;
    for(int i = n; i >= 1; i--){
        if(n % i == 0){somme += i;}
    } return somme;
}

_Bool testeParfait(int n){
    return sommeDiv(n) == 2*n;
}

int nbParfaitsIntervalle(int a, int b){
    int cpt = 0;
    for(int i = a; i <= b; i++){
        if(testeParfait(i)){cpt++;}
    } return cpt;
}

int nEmeParfait(int n){
    int cpt = 0;
    int nb = 1;
    while(cpt < n){
        while(!testeParfait(nb)){nb++;}
        cpt++;
    } return nb;
}

_Bool existParfait(int n, int d, int *x){
    int e = 0;
    while(e <= d && !testeParfait(n+e) && !testeParfait(n-e)) e++;
    if(e > d) return 0;
    else{if(testeParfait(n+e)) *x = n+e; else *x = n-e;}
    return 1;
}
