/*  */

#include <stdio.h>

int main(){
    int x = 1;
    int compteur = 0;
    int sum = 0;

    while (x>=0){
        printf("Saissez un entier, positif ou nul pour continuer, négatif pour arrêter : ");
        scanf("%d", &x);
        if (x >= 0)
            {sum += x;
            compteur++;}
    }
    printf("Vous avez entré %d nombres positifs ou nuls", compteur);
    printf("La moyenne des valeurs saisies est %f", (float) sum/compteur);

    return 0;
}