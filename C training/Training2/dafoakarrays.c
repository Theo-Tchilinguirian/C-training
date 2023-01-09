#include <stdio.h>
#include <stdlib.h>


void showt(int *, int);

void showtbidi(int, int (*)[], int);

void showtbididos(int, int *[], int);


void showt(int *t, int n){
    if(n > 0){
        printf("[%d", t[0]);
        for(int i = 1; i < n; i++){
            printf(", %d", t[i]);
        }
        printf("]\n");
    }
    else{
        printf("Erreur : taille tableau <= 0.\n");
        exit(1);
    }
}

void showtbidi(int m, int (*t)[m], int n){
    if(n > 0 && m > 0){
        printf("[");
        for(int i = 0; i < n; i++){
            printf("[%d", t[i][0]);
            for(int j = 1; j < m; j++){
                printf(", %d", t[i][j]);
            }
            (i == n-1) ? printf("]") : printf("],\n");
        }
        printf("]\n");
    }
    else{
        printf("Erreur : taille tableau <= 0.\n");
        exit(1);
    }
}

void showtbididos(int n, int *t[n], int m){
    if(n > 0 && m > 0){
        printf("[");
        for(int i = 0; i < n; i++){
            printf("[%d", t[i][0]);
            for(int j = 1; j < m; j++){
                printf(", %d", t[i][j]);
            }
            (i == n-1) ? printf("]") : printf("],\n");
        }
        printf("]\n");
    }
    else{
        printf("Erreur : taille tableau <= 0.\n");
        exit(1);
    }
}


int main(int argc, char *argv[]){

    int t_stat[10] = {1, 2, 3};
    showt(t_stat, 10);

    int t_stat_bidi[4][4] = {{1, 0, 1}, {0, 1, 0, 1}};
    showtbidi(4, t_stat_bidi, 4);

    printf("\n");

    int l, n, m;
    printf("Choisissez les dimensions :\n");
    int nb = 0;

    do{
        nb = scanf("%d%d%d", &l, &n, &m);
        if(nb != 3){printf("Pas assez.\n");}
    } while(nb != 3);

    int t_vla[l];
    int t_vla_bidi[n][m];
    showt(t_vla, l);
    showtbidi(m, t_vla_bidi, n);

    printf("\n");

    int *t_dyn = (int *)malloc(l * sizeof(int));  // Tableau dynamique à 1 dimension. C'est un pntr donc un certain nb d'octets est alloué. t[i] va de 4 en 4.
    int *t_dyn_bidi[n];  // Tab VLA 1D de taille n, contenant des pntrs de type int.
    // On alloue à chaque pntr une zone mémoire. t[i][j] est possible.
    for(int i = 0; i < n; i++){
        t_dyn_bidi[i] = (int *)malloc(m * sizeof(int));  // On alloue pour chaque pntr du tabVLA de pntrs.
    }

    char *toc[2];
    toc[0] = (char *)malloc(9 * sizeof(char));
    toc[1] = (char *)malloc(9 * sizeof(char));
    toc[0] = "abcdefg";
    toc[1] = "abcd";
    printf("%s---%s---\n", toc[0], toc[1]);

    showt(t_dyn, l);
    printf("%d\n", t_dyn_bidi[0][0]);
    showtbididos(n, t_dyn_bidi, m);

    free(t_dyn);
    t_dyn = NULL;
    for(int i = 0; i < n; i++){
        free(t_dyn_bidi[i]);
        t_dyn_bidi[i] = NULL;
    }


    return 0;
}

// int *tab[lignes]  est un tab de pointeurs. C'est un VLA 1D de n lignes, dont chaque colonne est un pntr qui doit être alloué dynamiquement. Donne un tab dyn 2D.
// int (*tab)[colonnes]  est un tab VLA 2D. Donne un VLA 2D.
