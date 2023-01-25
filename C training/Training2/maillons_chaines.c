#include <stdio.h>
#include <stdlib.h>


struct maillon {
    int val;
    struct maillon *suiv;
};

struct maillon premier_maillon

typedef struct maillon* chaine;


chaine insere_tete(int elt, chaine chn);
chaine suppr_tete(chaine chn);
void insere_tete_wifi(int elt, chaine *chn_pntr);
void suppr_tete_wifi(chaine *chn_pntr);
int longueur(chaine chn);
int nieme_elt(int n, chaine chn);
void afficher(chaine chn);
chaine insere_nieme(int n, int elt, chaine chn);


chaine insere_tete(int elt, chaine chn){
    chaine nv_tete = (chaine)malloc(sizeof(struct maillon));
    if(nv_tete == NULL){
        printf("Allocation mémoire impossible\n");
        exit(1);
    }
    else{
        nv_tete->val = elt;
        nv_tete->suiv = chn;

        return nv_tete;
    }
}

chaine suppr_tete(chaine chn){
    if(chn != NULL){
        chaine nv_tete = chn->suiv;
        free(chn);
        return nv_tete;
    }
    else{
        return NULL;
    }
}

void insere_tete_wifi(int elt, chaine *chn_pntr){
    chaine nv_tete = (chaine)malloc(sizeof(struct maillon));
    if(nv_tete == NULL){
        printf("Allocation impossible\n");
        exit(1);
    }
    else{
        nv_tete->val = elt;
        nv_tete->suiv = *chn_pntr;
        *chn_pntr = nv_tete;
    }
}

void suppr_tete_wifi(chaine *chn_pntr){
    if(*chn_pntr != NULL){  // Sinon : reste NULL.
        chaine nv_tete = (*chn_pntr)->suiv;
        free(*chn_pntr);
        *chn_pntr = nv_tete;
    }
}

int longueur(chaine chn){
    int i = 0;
    while(chn != NULL){
        i++;
        chn = chn->suiv;
    }
    return i;
}

int nieme_elt(int n, chaine chn){
    if(n < 1 || n > longueur(chn)){
        printf("Cet élément n'existe pas");
        exit(3);
    }
    else{
        int i = 0;
        while(chn != NULL && i != n-1){
            i++;
            chn = chn->suiv;
        }
        if(i != n-1){
            printf("Cet élément n'existe pas\n");
            exit(3);
        }
        else{
            return chn->val;
        }
    }
}

void afficher(chaine chn){
    printf("|-");
    while(chn != NULL){
        printf("[%d]-", chn->val);
        chn = chn->suiv;
    }
    printf("|\n");
}

chaine insere_nieme(int n, int elt, chaine chn){  // Voir notes dans le main.
    if(n > longueur(chn)+1 || n < 1){
        printf("Cet élément n'existe pas");
        exit(3);
    }
    else{
        chaine nv_tete = (chaine)malloc(sizeof(struct maillon));
        if(nv_tete == NULL){
            printf("Allocation mémoire impossible\n");
            exit(1);
        }
        else{
            int i = 0;
            while(chn != NULL && i != n-1){
                i++;
                chn = chn->suiv;
            }
            if(i != n-1){
                printf("Cet élément n'existe pas\n");
                exit(3);
            }
            else{
                nv_tete->val = elt;
                nv_tete->suiv = chn;

                return nv_tete;
            }
        }
    }
}


int main(int argc, char *argv[]){
    if(argc != 1){
        printf("Présence d'arguments");
        exit(2);
    }

    chaine chn = NULL;
    afficher(chn);
    printf("%d\n", longueur(chn));
    chn = insere_tete(5, chn);
    afficher(chn);
    printf("%d\n", longueur(chn));
    insere_tete_wifi(15, &chn);
    afficher(chn);
    printf("%d\n", longueur(chn));
    // chn = insere_nieme(2, 25, chn);  Marche pas trop ; remplace le n-1e au lieu d'insérer un nieme. Lol.
    // afficher(chn);
    // printf("%d\n", longueur(chn));
    printf("%d\n", nieme_elt(1, chn));
    printf("%d\n", nieme_elt(2, chn));
    // printf("%d\n", nieme_elt(0, chn)); /////
    // printf("%d\n", nieme_elt(3, chn)); /////
    chn = suppr_tete(chn);
    afficher(chn);
    suppr_tete_wifi(&chn);
    afficher(chn);

    return 0;
}
