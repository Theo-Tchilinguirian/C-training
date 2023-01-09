/* Théo Tchilinguirian 27/01/2022 Exercice 3 du TP 1 */

#include <stdio.h>

int main(){

    printf("Donnez une température en degrés farenheit et une en degrés celsius\n");

    double TF;
    scanf("%lf", &TF);

    double TC;
    scanf("%lf", &TC);

    printf("La valeur de %lf°F en degrés Celsius est %lf°C", TF, (double) 5/9*(TF-32));

    printf("La valeur de %lf°C en degrés Farenheit est %lf°F", TC, (double) (9/5)*TC+32);

    return 0;
}