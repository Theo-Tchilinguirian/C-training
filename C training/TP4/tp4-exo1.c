/* Théo Tchilinguirian, TP4 exo 1 */

#include <stdio.h>
#include "parfait.h"

/* Note à soi-même ; heure : 22:12. État mental absolu : très instable. Performances relatives : 68%. */

void testeParfait(){
    
    int choix;

    do{
        printf("\n\nProgramme : testeParfait. Si le programme bug, utilisez CTRL+C pour l'arreter. Faites votre choix :\n\
        0 : quitte le programme\n\
        1 : saisit un entier et dit s’il est parfait\n\
        2 : saisit deux entiers a et b et affiche le nombre d’entiers parfait de l’intervalle [a, b]\n\
        3 : saisit un entier n et affiche le ni`eme nombre parfait.\n\
        4 : saisit deux entiers n et d, et affiche le plus proche parfait de n s’il en existe un dans l’intervalle [n − d, n + d] ou un message d’absence sinon.\n\
        Votre choix : ");
        scanf("%d", &choix);

        switch(choix){
            case 1:
                {unsigned int n;
                printf("\nSaisissez un entier naturel pour savoir s'il est parfait : ");
                scanf("%u", &n);
                if(estParfait(n)){printf("%u est parfait.\n", n);}
                else{printf("%d n'est pas parfait.\n", n);}}
                break;
            case 2:
                {unsigned int a, b;
                printf("\nSaisissez deux entiers naturels pour connaitre le nombre d'entiers parfaits entre eux :\n");
                printf("Premier entier : ");
                scanf("%u", &a);
                printf("Deuxième entier : ");
                scanf("%u", &b);

                printf("Il y a %u entiers parfaits en %u et %u.\n", qteParfaits(a, b), a, b);}
                break;
            case 3:
                {unsigned int n;
                printf("\nSaisissez un entier naturel pour obtenir le entiernaturelième nombre parfait : ");
                scanf("%u", &n);
                printf("Le %ueme nombre parfait est : %d.\n", n, nEmeParfait(n));}
                break;
            case 4:
                {printf("Toute peine mérite salaire.\n");}
                break;
            default:
                break;
        }
    }while(choix != 0);
}

/* Note à soi-même ; heure : 22:36. État mental absolu : diminué. Performances relatives : 59%. */


int main(){
    testeParfait();
    return 0;
}

/* Note à soi-même ; J'ai enfin corrigé les problèmes d'importations de modules. heure : 22:57. État mental absolu : stabilisé sur un niveau d'inexistance. Performances relatives : 55%. */
/* Conclusion de la procédure : parfois le café ça peut être utile, en fin de compte. Meilleur drogue légale la plus consommée 😋👌👍👍 */
