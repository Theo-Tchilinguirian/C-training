/* Théo Tchiling......, TP3 exo 3 */

#include <stdio.h>


_Bool bissextile(unsigned int annee){
    if(annee % 4 == 0){  /* Trad : 'si annee est divisible par 4', ou encore 'si 4 est diviseur de annee', ou encore 'si annee est multiple de 4'. Pratique le modulo. */
        if(annee % 100 != 0){return 1;}
        else{
            if((annee % 100 == annee % 400) == 0){return 1;}
            else{return 0;}
        }
    }
    else{return 0;}
}

_Bool dateValide(unsigned int jour, unsigned int mois, unsigned int annee){
    if(annee > 1582 && mois >= 1 && mois <= 12 && jour < 32 && jour >= 1){
        /*Test pour vérif si le jour choisi rentre dans le mois (utilisation d'un switch pour séparer les cas)*/
        switch(jour){
            case 29:
                if(mois != 2){return 1;}
                else{
                    if(bissextile(annee)){return 1;}  /* Année bissextile : février a 29 jours. (fantastique) */
                    else{return 0;}
                }
                break;
            case 30:
                if(mois != 2){return 1;}
                else{return 0;}
                break;
            case 31:
                if(mois == 1 || mois == 3 || mois == 5 || mois == 7 || mois == 8 || mois == 10 || mois == 12){return 1;}
                else{return 0;}
                break;
            default:
                return 1;
                break;
        }
    }
    else{return 0;}
}

int compteJours(unsigned int jour, unsigned int mois, unsigned int annee){  /* La consigne est pas claire. Choisissez une date dans le passé, ça renvoie la durée en jours entre cette date et le 10/02/2022 (Anniv de Ioannis Charalambopoulos, Alex Comfort, Dominique Pire et Carolane Soucisse) */
    /* Si la date choisie est dans le futur, le programme ne se comportera pas correctement */
    int duree_j = 0;

    for(int i = 2021; i > annee; i--){  /* Durée entre la date et 2022 (incrémentation des années pleines) */
        if(bissextile(i)){duree_j += 365;}
        else{duree_j += 364;}
    }

    duree_j += 42; /* Durée écoulée en 2022 */


    unsigned int duree_ecoulee_annee_choisie_par_utilisateur = 0;

    for(int i = 1; i <= mois; i++){ /* Calcul de duree_ecoulee_annee_choisie_par_utilisateur, la durée ecoulée du début de l'année choisie par utilisateur à la fin de l'année choisie par l'utilisateur. */
        switch(mois){
            case 2:
                if(bissextile(i)){duree_ecoulee_annee_choisie_par_utilisateur += 29;}
                else{duree_ecoulee_annee_choisie_par_utilisateur += 28;}
                break;
            case 4:
                duree_ecoulee_annee_choisie_par_utilisateur += 30;
                break;
            case 6:
                duree_ecoulee_annee_choisie_par_utilisateur += 30;
                break;
            case 9:
                duree_ecoulee_annee_choisie_par_utilisateur += 30;
                break;
            case 11:
                duree_ecoulee_annee_choisie_par_utilisateur += 30;
                break;
            default:
                duree_ecoulee_annee_choisie_par_utilisateur += 31;
                break;
        }
    }

    duree_j += duree_ecoulee_annee_choisie_par_utilisateur;

    duree_j += jour;

    return duree_j;
}

int compteNombreAnneesBissextiles(unsigned int annee){return annee/4 - annee/100 + annee/400 + 2;}

int trouveCodeJourSemaine(unsigned int jour, unsigned int mois, unsigned int annee){return compteJours(1, 1, 1) % 7;}

void afficheJour(unsigned int num){
    switch(num){
        case 0:
            printf("vendredi");
            break;
        case 1:
            printf("samedi");
            break;
        case 2:
            printf("dimanche");
            break;
        case 3:
            printf("lundi");
            break;
        case 4:
            printf("mardi");
            break;
        case 5:
            printf("mercredi");
            break;
        case 6:
            printf("jeudi");
            break;
        case 666:
            printf("Staline est mort.");
            break;
        default:
            printf("Joyeux non-anniversaire !!");
            break;
    }
}

/* Note à soi-même ; état mental : correct. */


int main(){
    unsigned int jour, mois, annee;

    printf("Saisissez une date au format jj/mm/aaaa : ");
    scanf("%u/%u/%u", &jour, &mois, &annee);

    if(dateValide(jour, mois, annee)){afficheJour(trouveCodeJourSemaine(jour, mois, annee));}

    return 0;
}
