#include "arithmetique.hpp"

// - Exercice 1
Entier pgcd(Entier a, Entier b){
    if (a == 0) 
        return b; 
    return pgcd(b % a, a); 
}

// - Exercice 2

Entier pgcd_etendu(Entier a, Entier b, Entier *u, Entier *v){ 
    Entier u1, v1, q, t, i;
    u1 = 0;
    v1 = 1;
    *u = 1;
    *v = 0;
    i = 1;

    while(b!=0){
        
        q = (a-a%b)/b;
        t = a;
        a = b;
        b = t%b;

        t=*u;
        *u= q*(*u)+u1;
        u1 = t;

        t=*v;
        *v= q*(*v)+v1;
        v1 = t;
    
        i++;
        
    }

    if(i%2==0){
        *u = u1;
        *v = -1*v1;
    }
    else{
        *u = -1*u1;
        *v = v1;
    }
    return a;
}

// - Exercice 3
Entier exp_rapide(Entier a, Entier p, Entier n){  
    int b = 1;     
    a = a % n; 
    while (p > 0)  
    {  
        if (p % 2==0) { 
            a = (a*a) % n;
            p=p/2;  
        }
  
        else{
            b = (b*a)%n;
            p--;
        }
    }  
    return b;  
}  

Entier inv_modulaire(Entier a, Entier n){
    Entier x;
    Entier y;
    pgcd_etendu(a, n, &x, &y);
    if(a<n){
        if(y<0){
            y+=n;
        }
        return y;
    }
    else{
        if(x<0){
            x+=n;
        }
        return x;
    }

}

bool est_premier(Entier n){
    Entier temoins [7] = {2,3,5,7,11,13,17};
    bool premier = true;
    int i = 0;
    while(premier && i<7){
        if(exp_rapide(temoins[i], n, n-1)!=1) premier = false;
        i++;
    }

    if (premier){
        string nombre = to_string(n);
        string line;
        ifstream file;
        file.open("./exceptions.txt");
        if(file.is_open()){
            while(!file.eof() && premier){
                getline(file, line);
                if(line == nombre){
                    premier = false;
                }
            }
        }
    }
    return premier; 
}