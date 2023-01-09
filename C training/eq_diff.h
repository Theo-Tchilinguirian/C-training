/*
Résolveuse d'équations différentielles
*/

#ifndef EQ_DIFF_H
#define EQ_DIFF_H

struct eq_diff = {double coeffs[ordre + 1], double snd_membre};  // snd_membre est une constante scalaire, les coeffs aussi. Ordre 1 : il y a ordre + 1 coeffs.
// Si snd_membre est nul, l'eq diff est homogène.
typedef struct eq_diff eq_diff;  // struct eq_diff alias eq_diff

// Algorithmer les étapes. https://moodle.umontpellier.fr/pluginfile.php/1503560/mod_resource/content/4/CM_Calcul_v7.pdf

#endif