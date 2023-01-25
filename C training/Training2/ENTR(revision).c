#include <stdio.h>
#include <stdlib.h>
#include "mdl.h"


/* Déclaration des fonctions */

void cpt_fois();

int som_car_rec(int, int);

void shotabent(int*, int);  // Show unidimensional array

void shotabidi(int, int, int (*)[]);  // Show bidimensional array

void incr_bidi(int, int, int (*t)[]);  // ou (?) void incr_bidi(int*[], int); Pareil ? int[][] ??


/* Définition des fonctions */

void cpt_fois(){
    static int i = 0;
    printf("Cette fonction compte le nombre de fois où elle a été appelée.\n");
    i++;
    printf("Cette fonction a été appelée %d fois.\n", i);
}


int som_car_rec(int m, int n){
    // Renvoie la somme des carrés de m à n.
    return (m>n) ? 0 : m*m+som_car_rec(m+1, n);
}

void shotabent(int *tab, int n){
    printf("[");
    for(int i = 0; i < n; i++){
        printf(", %d", tab[i]);
    }
    printf("]\n");
}

void shotabidi(int n, int m, int (*tab)[m]){
    for(int i = 0; i < n; i++){
        printf("[");
        for(int j = 0; j < m; j++){
            printf(", %d", tab[i][j]);
            if(j == m-1){printf("]\n");}
        }
    }
}

void incr_bidi(int n, int m, int (*tab)[m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            tab[i][j]++;
        }
    }
}


/* Fonction principale */

int main(int argc, int *argv[]){
    
    /*
    Si on déclare : int *p;
    Alors on a p + i = p + i*sizeof(int) en adresses.
    Donc p++ = &(t[1]) si p = &(t[0])
    et t[i] = *(p+i)
    */

    int k;

    printf("Donnez la taille du tableau d'entiers : ");
    scanf("%d", &k);

    int tab_ent[k];

    printf("Initialisez les éléments :\n");
    for(int i = 0; i < k; i++){
        scanf("%d", &tab_ent[i]);
    }

    int i = 0;
    while (i < k && tab_ent[i] != 5){
        tab_ent[i] = 0;
        i++;
    }
    if (i == k){printf("Pas de 5. Tableau réinitialisé.\n");}
    else{printf("Le premier 5 est à l'indice %d. C'est le %deme élément.\nLes éléments précédents ont été réinitialisés.\n", i, i+1);}
    shotabent(tab_ent, k);

    int n = 2, m = 2;
    int t[n][m];
    t[0][0] = 1;
    t[0][1] = 2;
    t[1][0] = 3;
    t[1][1] = 4;
    printf("%d\n", t[1][0]);
    printf("%p\n", t[0]);
    printf("%p\n", t[1]);
    incr_bidi(n, m, t);
    shotabidi(n, m, t);

    // Une structure peut contenir des tableaux statiques.

    int *p = (int*)malloc(1 * sizeof(int));
    if (p == NULL){printf("Alloc imposs\n"); return 1;}  // Test de verif.
    printf("--%d--\n", p[0]);
    p[0] = 5000;
    printf("----------%p-----%p-----%p-----%p\n", p, &(p[0]), p+1, &(p[1]));
    printf("--%d--\n", p[0]);
    *(p+1) = 5;
    printf("--%d--\n", p[1]);
    p[0] = 3;
    printf("--%d--\n", p[0]);
    free(p);
    p = NULL;
    printf("%p\n", p);


    // Création d'une structure chaînée :
    struct maillon{  // La structure : un scalaire et un pointeur.
        int valeur;
        struct maillon *suivant;
    };

    typedef struct maillon *liste;  // On typedef le pointeur de la structure.

    liste l = NULL;  // Le dernier élément (dernière queue). liste est un type pointeur.
    
    // Fonction pour ajouter une tête : On malloc dans la fonction (le malloc touche direct la mémoire). La fonction renvoie le pntr (l'adresse) de la nv liste crée.
    /*
    liste add_tete(int elt, liste lst){
        liste li = (liste)malloc(sizeof(struct maillon));
        if(li == NULL){
            printf("Erreur : plus de mémoire\n");
            exit(1);  // On sort du programme, depuis la fonction.
        }
        li->valeur = elt;
        li->suivant = lst;
        return li
    }
    */
    // l = add_tete(8, l);
    // free(l);
    // l = add_tete(8, add_tete(5, NULL));
    // free(l);

    char s[3] = "ab";
    char ss[3] = {'c', 'd', '\0'};

    char nom[21];
    printf("Votre nom : ");
    scanf("%20s", nom);  // Adresse du 1er elt. Le 20 limite le string reçu à 20 char. C'est prc ça que le tab en fait 21.
    printf("Bonjour, %s.\n", nom);
    printf("%f\n", 1.56);
    printf("%.3f\n", 1.56);
    printf("%.1f\n", 1.56);

    return 0;
}


/*
VLAs bidim :

Déclaration fonction :
void shotabidi(int, int, int (*)[]);  Aucun paramètre nommé.
Ou :
void shotabidi(int, int, int (*t)[]);  Tableau nommé.
Ou :
void shotabidi(int, int m, int (*t)[m]);  nbCol nommé. Avec ou sans t nommé.


Définition fonction :
void shotabidi(int n, int m, int (*tab)[m]){}

Déclaration VLA : (ne peut PAS être initialisé !)
int n = ..., m = ...;
int t[n][m];

Appel fonction :
shotabidi(n, m, t);
*/

/*
Allocation dynamique : déf dans stdlib.h
À utiliser quand la taille / durée d'utilisation des données dépend de paramètres externes au programme. --> que pointeurs.

La fonction malloc(taille) renvoie une adresse (de la zone allouée) de type void, ou NULL (pointeur vide) si pas assez d'espace mém / taille nulle. NULL imp pr les tests.
Il faut contenir cette adresse dans un pointeur : void *p = malloc(4);
p contient l'adresse du début de la zone mémoire allouée. La taille est en octets.

free permet de libérer un pointeur qui contient une adresse allouée par un malloc : free(p);
Une erreur se produit si : l'adresse est NULL, ou zone mémoire pas actuellement allouée (déjà libérée, ou pas un malloc.)
On peut free que si ct alloué par un malloc ! (Appartient au TAS)

Appel général à malloc : Avec conversion implicite de void* en type*.
type *pntr = (type *)malloc(n * sizeof(type));
Avec n le nb de données de type type à stocker.

--> Manipulable comme un tableau de type type et de taille n.

Un truc malloc peut être renvoyé comme résultat d'une fonction (adresse de la zone allouée, malloc à l'intérieur de la fonction).

Arithmétique sur les pntr : p[i] = *(p+i). L'écart entre les données vaut la taille du type de p, calculée automatiquement.

Il faut faire attention à plusieurs choses :
 1. On manipule des pointeurs : verif que la zone a bien été allouée (pas NULL), et que l'on ne déborde PAS de la zone.
if(p = NULL){printf("échec de l'alloc\n", return 1...);}
 2. Il faut initialiser soi-même la zone mémoire :
for(int i = 0; i < n; i++){p[i] = 0;...}
 3. La mémoire doit absolument être libérée par le dev !!
free(p);
On remet ensuite immédiatement les pointeurs à NULL : (pr éviter de free plusieurs fois la mémoire)
p = NULL;

L'opérateur de déréférencement pour afficher une adresse / un pntr est %p.

Créer un tableau dynamique :
Allocation ds un pointeur du nb de cases du tableau
Verif de la réussite de l'alloc
/!\ :  Pas de décla avec init sur ces tableaux !! (Comme VLA)

*/
