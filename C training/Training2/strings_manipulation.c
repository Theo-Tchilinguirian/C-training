#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){

    char *prenom = (char *)malloc(51 * sizeof(char));
    if(prenom == NULL){printf("Alloc imposs.\n"); exit(1);}
    char nom[51];

    scanf("%50s%50s", prenom, nom);
    printf("You are %s %s, right %.3f? (real nb format test)\n", prenom, nom, 1.56);

    free(prenom);
    prenom = NULL;

    return 0;
}

// malloc ou fopen peuvent renvoyer NULL : TESTER LA VAL ! Et aussi tester argc !! Et fclose peut renvoyer EOF.
