#ifndef RSA_HPP
#define HSA_HPP

#include "cles.hpp"
#include "fichier.hpp"

using namespace std;

Entier chiffre(ClePublique cle, Entier m);
Entier dechiffre(ClePrivee cle, Entier c);
#endif