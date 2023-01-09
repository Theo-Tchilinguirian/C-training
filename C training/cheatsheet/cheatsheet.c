/*
Mettre les %d, %u, %f...
Les tailles en octet, les tableaux les data etc etc...
De vraies fiches mémo du cours.
Et des bouts de code utilisables, copier-collables !
*/

/*
Spécifications de format :
Format          Type du paramètre effectif (conversion en)          Taille (nb octets)      Gamme valeurs

%d              int                                                 4                       [ -2^31 ; 2^31 - 1 ]
%hd             short                                               2                       [ -2^15 ; 2^15 - 1 ]
%ld             long                                                8                       [ -2^63 ; 2^63 - 1 ]
%u              unsigned int                                        4                       [ 0 ; 2^32 - 1 ]
%hu             unsigned short                                      2                       [ 0 ; 2^16 - 1 ]
%lu             unsigned long                                       8                       [ 0 ; 2^64 - 1 ]
%f              float                                               4                       1.2E-38 to 3.4E+38
%lf             double                                              8                       2.3E-308 to 1.7E+308
%c              unsigned char                                       1                       [ 0 ; 2^8 - 1 ]
%s              signed char                                         1                       [ -2^7 ; 2^7 - 1 ]
%p              adresse                                             8                       Hex, surement que pos ? Ptet.
*/