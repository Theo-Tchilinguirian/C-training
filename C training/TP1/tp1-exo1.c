/* Théo Tchilinguirian 27/01/2022 Exercice 1 du TP 1 */

#include <stdio.h>

int main(){

    printf("Donnez les valeurs de a et b\n");

    short a, b, c, d;
    scanf("%hd", &a);
    scanf("%hd", &b);

    c = a + b;
    d = a * b;

    printf("La valeur de la somme est %hd, la valeur du produit est %hd", c, d);

    return 0;
}