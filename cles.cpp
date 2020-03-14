#include "cles.hpp"

ClePublique::ClePublique(Entier e, Entier n){
    this->n = n;
    this->e = e;
}

Entier ClePublique::getE() const{
    return this->e;
}

Entier ClePublique::getN() const{
    return this->n;
}

ClePrivee::ClePrivee(Entier d, Entier n){
    this->n = n;
    this->d = d;
}

Entier ClePrivee::getD() const{
    return this->d;
}

Entier ClePrivee::getN() const{
    return this->n;
}

ostream& operator<<(ostream& os,const ClePublique& cp){
    Entier e = cp.getE();
    Entier n = cp.getN();
    os<<"("<<e<<","<<n<<")"<<endl;
}
ostream& operator<<(ostream& os,const ClePrivee& cp){
    Entier d = cp.getD();
    Entier n = cp.getN();
    os<<"("<<d<<","<<n<<")"<<endl;
}

ostream& operator<<(ostream& os, const Cles& cles){
    os<<"Cle Publique : "<<cles.cle_publique<<endl;
    os<<"Cle Privee : "<<cles.cle_privee<<endl;
}

Cles genere_cles(Entier p, Entier q, Entier e){
    Entier n = p*q;
    Entier phi_n = (p-1)*(q-1);

    Entier d = inv_modulaire(e,phi_n);
    Cles cles = {ClePublique(e,n), ClePrivee(d,n)};
    return cles;
}

Cles genere_cles_aleatoire(){
    Entier p = 1;
    Entier q = 1;
    Entier n = p*q;
    while(n<256){
        p = premier_aleatoire();
        q = premier_aleatoire();
        n = p*q;
    }
    Entier phi_n = (p-1)*(q-1);
    Entier e = phi_n;

    while(pgcd(e, phi_n)!=1){
        e = premier_aleatoire();
    }
    Entier d = inv_modulaire(e,phi_n);
    Cles cles = {ClePublique(e,n), ClePrivee(e,n)};
    return cles;
}