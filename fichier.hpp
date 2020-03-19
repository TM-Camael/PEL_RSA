#ifndef FICHIER_HPP
#define FICHIER_HPP

#include "cles.hpp"


using namespace std;

int taille_bloc(Entier n);
Entier code(char* buffer, int k);
void decode(Entier m, int k, char* c);

#endif
