#ifndef ALEATOIRE_HPP
#define ALEATOIRE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <list>
#include "arithmetique.hpp"

using namespace std;

typedef long long int Entier;
extern Entier alea;

Entier prochain_middle_square(Entier x);
Entier periode_middle_square(Entier n);
Entier middle_square(Entier x, Entier n);
Entier prochain_minimal_standard(Entier x);
Entier minimal_standard(Entier x, Entier n);


#endif