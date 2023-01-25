#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

    // But : faire taper au singe devant l'écran 'to be or not to be'.

    char *tbontb[6];
    tbontb[0] = (char *)malloc(3 * sizeof(char));
    tbontb[1] = (char *)malloc(3 * sizeof(char));
    tbontb[2] = (char *)malloc(3 * sizeof(char));
    tbontb[3] = (char *)malloc(4 * sizeof(char));
    tbontb[4] = (char *)malloc(3 * sizeof(char));
    tbontb[5] = (char *)malloc(3 * sizeof(char));

    _Bool cont = 1;
    do{
        printf("ECRIVEZ \"TO BE OR NOT TO BE\" :\n");
        scanf("%2s%2s%2s%3s%2s%2s", tbontb[0], tbontb[1], tbontb[2], tbontb[3], tbontb[4], tbontb[5]);
        printf("Voyons... %s %s %s %s %s %s, ", tbontb[0], tbontb[1], tbontb[2], tbontb[3], tbontb[4], tbontb[5]);
        if(strcmp(tbontb[0], "TO") == 0 && strcmp(tbontb[1], "BE") == 0 && strcmp(tbontb[2], "OR") == 0 && strcmp(tbontb[3], "NOT") == 0 && strcmp(tbontb[4], "TO") == 0 && strcmp(tbontb[5], "BE") == 0){
            printf("CORRECT !\n");
            cont = 0;
        }
        else{
            printf("INCORRECT !\n");
        }
    } while(cont != 0);
    // Un peu broken si on met pas 6 mots, mais bon, à part ça, ça marche.
    return 0;
}
