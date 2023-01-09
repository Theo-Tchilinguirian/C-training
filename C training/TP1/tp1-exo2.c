/* Théo Tchilinguirian 27/01/2022 Exercice 2 du TP 1 */

#include <stdio.h>

int main(){

    printf("Donnez les valeurs de a et b\n");

    short a, b;
    scanf("%hd", &a);
    scanf("%hd", &b);

    printf("L'adresse de a est %p, celle de b est %p", &a, &b);

    return 0;
}