#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    if (argc != 2){printf("Erreur commande.\n"); return 1;}

    FILE *fichier = fopen(argv[1], "a+");
    if (fichier == NULL){printf("Erreur ouverture fichier.\n"); return 2;}
    printf("Le fichier %s existe.\n", argv[1]);

    int i = fgetc(fichier);
    int k = fputc('a', fichier);
    printf("%c, %d\n", i, k);
    int h = ungetc('b', fichier);
    printf("%c\n", h);

    if (fclose(fichier) == EOF){printf("Erreur fermeture du fichier.\n"); return 3;}

    return 0;
}

// malloc ou fopen peuvent renvoyer NULL : TESTER LA VAL ! Et aussi tester argc !! Et fclose peut renvoyer EOF.
