#include "fichier.hpp"

Entier taille_bloc(Entier n){
    Entier i=0;
    while(pow(256,i) <= n){
        i++;
    }
    return i;
}

Entier code(char* buffer, int k){
    Entier result=0;
    for(int i=0; i<k;i++){
        Entier temp;
        temp = buffer[i];
        if(temp<0){
            temp += 256;
        }
        result += temp*pow(256,i);
    }
    return result;
}

void decode(Entier m, int k, char* c){
    Entier result;
    int i=0;
    for(int i=0; i<k; i++){
        int j = m%256;
        c[i] = char(j);
        m= m/256;
    }
}