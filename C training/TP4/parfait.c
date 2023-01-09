/* Théo Tchilinguirian */

#include "parfait.h"

/* Note à soi-même ; Début boulot : 18:20. heure : 21:42. État mental absolu : instable. Performances relatives : maximales. */

_Bool estParfait(unsigned int n){
    unsigned int somme = 0;

    for(unsigned int x = n; x >= 1; x--){
        if(n%x == 0){somme += x;}
    }
    if(somme == 2 * n){return 1;}
    else{return 0;}
}

/* Note à soi-même ; heure : 21:44. État mental absolu : instable. Performances relatives : maximales. */

unsigned int qteParfaits(unsigned int a, unsigned int b){
    unsigned int cpt = 0;

    for(unsigned int x = b; x >= a; x--){
        if(estParfait(x)){cpt++;}
    }
    return cpt;
}

/* Note à soi-même ; heure : 21:47. État mental absolu : instable. Performances relatives : 96%. */

int nEmeParfait(unsigned int n){
    unsigned int cpt = 0;
    unsigned int nb = 0;
    while(cpt < n){
        nb++;
        if(estParfait(nb)){cpt++;}
    }
    return nb;
}

/* Note à soi-même ; heure : 21:57. État mental absolu : plus qu'instable. Performances relatives : 84%. */

_Bool existParfait(unsigned int n, unsigned int d){  /* Please, n > d, ou que la divinité quelconque que vous idolisez ai pitié de votre âme mortelle. */
    if(qteParfaits(n-d, n+d) > 0){return 1;}
    else{return 0;}  /* La 2e partie de la question (Exo 2 TD 2 fût ignorée pour raison de conservation de la stabilité mentale de l'"""être humain""" qui 'code' sur son 'computer' (moi en l'occurence)) */
    /* Vous êtes prié d'excusez ce léger désagrément, et d'accepter mes plus sincères apologies condoléantes envers votre éminente personne. (╯°□°）╯︵ ┻━┻. */
}

/* Note à soi-même ; heure : 22:08. État mental absolu : indéterminé. Performances relatives : 69%. */
