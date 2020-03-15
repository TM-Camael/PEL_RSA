#include "rsa.hpp"

Entier chiffre(ClePublique cle, Entier m){
    Entier c = exp_rapide(m, cle.getE(), cle.getN());
    return c;
}
Entier dechiffre(ClePrivee cle, Entier c){
    Entier m = exp_rapide(c, cle.getD(), cle.getN());
    return m;
}

int main(){
    Cles test = genere_cles_aleatoire();
    cout<<test<<endl;
    return 0;
}