#ifndef CLES_HPP
#define CLES_HPP

#include "arithmetique.hpp"
#include "aleatoire.hpp"

class ClePublique {
    private :
        Entier n;
        Entier e;
    
    public : 
        ClePublique(Entier n, Entier e);
        Entier getN() const;
        Entier getE() const;
};

class ClePrivee {
    private :
        Entier n;
        Entier d;
    
    public : 
        ClePrivee(Entier n, Entier d);
        Entier getN() const;
        Entier getD() const;

};

typedef struct {
    ClePublique cle_publique;
    ClePrivee cle_privee;
} Cles;

ostream& operator<<(ostream& os, ClePrivee& cp);
ostream& operator<<(ostream& os, ClePublique& cp);
ostream& operator<<(ostream& os, const Cles& cles);



Cles genere_cles(Entier p,Entier q,Entier e);
Cles genere_cles_aleatoire();

#endif
