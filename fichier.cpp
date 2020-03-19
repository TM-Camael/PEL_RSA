#include "fichier.hpp"

int taille_bloc(Entier n){
    int i=0;
    while(pow(256,i) <= n){
        i++;
    }
    return i;
}

Entier code(char* buffer, int k){
    Entier result=0;
    for(int i=0; i<k;i++){
        result += int(buffer[i])*pow(256,i);
    }
    return result;
}

void decode(Entier m, int k, char* c){
    Entier result;
    int i=0;
    for(int i=0; i<k; i++){
        c[i] = m/256;
        m/= 256;
    }
}
