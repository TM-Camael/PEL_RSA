#ifndef ARITHMETIQUE_HPP
#define ARITHMETIQUE_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef long long int Entier;

Entier pgcd(Entier a, Entier b);
Entier pgcd_etendu(Entier a, Entier b, Entier *u, Entier *v);
Entier exp_rapide(Entier a, Entier p, Entier n);
Entier inv_modulaire(Entier a, Entier n);
bool est_premier(Entier n);

#endif 
