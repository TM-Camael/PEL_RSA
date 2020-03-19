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
    if(p==0){
        return 1;
    }
    
    if(p==1){
        return a%n;
    }

    if(p%2==0){
        Entier d = exp_rapide(a, p/2,n)%n;
        return mulmod(d,d,n);
    }
    else{
        return mulmod(exp_rapide(a, p-1, n),(a%n),n);
    }
}

Entier mulmod(Entier a, Entier b, Entier m) {
    Entier res = 0;
    while (a != 0) {
        if (a & 1) res = (res + b) % m;
        a >>= 1;
        b = (b << 1) % m;
    }
    return res;
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
        //cout<<temoins[i]<<" "<<n<<" "<<n-1;
        if(exp_rapide(temoins[i], n-1, n)!=1) {
            premier = false;
        }
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
/*
int main(){
    cout<<sizeof(Entier)<<endl;
    cout<<exp_rapide(3,3,179321785446597613)<<endl;
    cout<<exp_rapide(27,119547855502053587,179321785446597613)<<endl;
}*/