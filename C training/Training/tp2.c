#include <stdio.h>

int max(int a, int b){return (a > b) ? a : b;}
int maxx(int a, int b, int c){return max(max(a, b), c);}

int puisrec(int x, int n){
    // Renvoie à l'écran x à la puissance n
    if(n == 0){return 1;}
    else{return x * puisrec(x, n-1);}
}

void puisite(int x, int n){
    // Affiche à l'écran x à la puissance n
    int puis = x;
    for(int i = 2; i <= n; i++){
        puis *= x;
    }
    printf("%d\n", puis);
}

int main(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf("max : %d\n", maxx(a, b, c));
    int x, n;
    scanf("%d%d", &x, &n);
    printf("x puiss n : %d\n", puisrec(x, n));
    puisite(x, n);
    double s = 0;
    for(int i = 1; i <= 10; i++){s += 1/(double) i;}
    printf("somme des 1/i de 1 à 10 : %lf", s);
}