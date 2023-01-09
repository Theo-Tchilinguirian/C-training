/* Théo Tchilinguirian, TP3 exo 2 */

#include <stdio.h>

/* Code long pas très commenté. aha aha mauvais. Bonne lekture. */

int centaine(int n){return (int) (n - n%100)/100;}

int dizaine(int n){return (int) (n%100 - n%10)/10;}

int unite(int n){return n%10;}


_Bool testeProp(int n){
    int ctn = centaine(n), dzn = dizaine(n), unt = unite(n);
    if(ctn*ctn*ctn + dzn*dzn*dzn + unt*unt*unt == n){return 1;}
    else{return 0;}
}


void testeTous(){
    for(int i = 2; i < 1000; i++){if(testeProp(i)){printf("%d est en accord avec la PROPRIETE\n", i);}}
}


_Bool testeTriplet(int c, int d, int u){
    int n = c*100 + d*10 + u;

    if(testeProp(n)){return 1;}
    else{return 0;}
}

void testeToutTriplet(int c, int d, int u){
    int n1 = c*100 + d*10 + u;
    int n2 = u*100 + c*10 + d;
    int n3 = d*100 + u*10 + c;
    int n4 = c*100 + u*10 + d;
    int n5 = u*100 + d*10 + c;
    int n6 = d*100 + c*10 + u;

    if(testeProp(n1)){printf("%d a signe l'accord de Paris en 2015\n", n1);} /* Triplet de valeurs toujours fonctionnel : 0, 0, 0 */
    if(testeProp(n2)){printf("%d a vote Remain.\n", n2);}
    if(testeProp(n3)){printf("%d a 56 nationalites et 23 personnalites.\n", n3);}
    if(testeProp(n4)){printf("%d chat vit roti, roti tenta chat, chat mis patte a roti, roti brula patte a chat, chat lecha patte et quitta roti.\n", n4);}
    if(testeProp(n5)){printf("%d, adepte du chauvinisme.\n", n5);}
    if(testeProp(n6)){printf("%d ne finit pas ses\n", n6);}
}


int main(){
    int n;

    printf("SAISISSEZ UN NOMBRE, COMPRIS DE PREFERENCE (OBLIGATOIREMENT) ENTRE 0 ET 999 : ");
    scanf("%d", &n);
    if(n >= 0 && n < 1000){
        printf("OK.\n");
        _Bool res = testeProp(n);
        if(res){printf("RESULTAT : %d EST PARFAIT. C'EST PARFAIT.\n", n);}
        else{printf("RESULTAT DU DIAGNOSTIQUE : NOMBRE SAISI EST IMPARFAIT.\n");}
    }
    else{printf("NOMBRE SAISI INVALIDE. TANT PIS.\n");}

    printf("LANCEMENT DE LA PROCEDURE 'testeTous' . . .\n\n");
    testeTous();
    printf("\n");

    printf("LANCEMENT DE LA PROCEDURE 'testeToutTriplet' . . .\n\n");

    int c, d, u;

    printf("SAISISSEZ c, d, u :\n");
    printf("SAISISSEMENT DE c : ");
    scanf("%d", &c);
    printf("SAISISSATION DE d : ");
    scanf("%d", &d);
    printf("SAISISSAGE DE u : ");
    scanf("%d", &u);
    testeToutTriplet(c, d, u);
    printf("TERMINE.\n");

    return 0;
}