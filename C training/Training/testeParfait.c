#include <stdio.h>
#include "nombres_parfaits.h"

int main(){
    int rep;
    do{
        printf("FAITES?VOTRE?CHOIX??\n 1 pOUR 0 : quitte le programme\
• 1 : saisit un entier et dit s’il est parfait\n\
• 2 : saisit deux entiers a et b et affiche le nombre d’entiers parfait de l’intervalle [a, b]\n\
• 3 : saisit un entier n et affiche le ni`eme nombre parfait.\n\
• 4 : saisit deux entiers n et d, et affiche le plus proche parfait de n s’il en existe un dans l’intervalle\n\
[n − d, n + d] ou un message d’absence sinon.\n\
• autre : ne fait rien\nCHoIX: ");
    scanf("%d", &rep);
    switch(rep){
        case 1:
            {int n; scanf("%d", &n); printf("%d", testeParfait(n));}
            break;
        case 2:
            {int a, b; scanf("%d%d", &a, &b); printf("%d", nbParfaitsIntervalle(a, b));}
            break;
        case 3:
            {int n; scanf("%d", &n); printf("%d", nEmeParfait(n));}
            break;
        case 4:
            {int n, d, x = -1; scanf("%d%d", &n, &d); printf("%d, %d", existParfait(n, d, &x), x);}
            break;
        default:
            printf("test\ntest\n");
            break;
    }
    } while(rep != 0);

    return 0;
}
