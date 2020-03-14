#include "aleatoire.hpp"
#include "arithmetique.hpp"

Entier alea = 0;

Entier prochain_middle_square(Entier x){
    x = x*x;
    double size=1; 
    int b = 10;

    while(x% int(pow(b,size)) != x){
        size++;
    }

    Entier res = 0;
    for(int i=0;i<2;i++){
        x = x/10;
    }
    
    for(int i = 0;i<=3;i++){
        res += pow(10,i)*(x%b);
        x = x/10;
    }
    return res;
}

Entier periode_middle_square(Entier n){
    list<Entier> previous_numbers;
    bool seen = true;
    previous_numbers.push_back(n);
    Entier i = 0;
    while(seen){
        i++;
        n = prochain_middle_square(n);
        for(Entier x : previous_numbers){
            //cout<<"Boucle"<<endl;
            //cout<<"x "<<x<<endl;
            //cout<<"n "<<n<<endl;
            if(x==n){
                seen = false;
                break;
            }
        }
        previous_numbers.push_back(n);

    }
    return i-1;
}

Entier middle_square(Entier x, Entier n){
    for(int i=0; i<n;i++){
        x = prochain_middle_square(x);
    }
    return x;
}

Entier prochain_minimal_standard(Entier x){
    x = (x * 16807) % 2147483647; 
    return x;
}

Entier minimal_standard(Entier x, Entier n){
    for(int i = 0; i<n;i++){
        x = prochain_minimal_standard(x);
    }
    return x;
}

void init_alea(){
    Entier t = time(NULL);
    Entier s = t%50+3;
    Entier n = middle_square(1111, s);
    alea = minimal_standard(t, n);
}

Entier aleatoire(){
    alea = prochain_minimal_standard(alea);
    return alea;
}

Entier premier_aleatoire(){
    init_alea();
    bool premier = false;
    Entier res = 0;
    while(!premier){
        res = aleatoire();
        cout<<res<<endl;
        if(est_premier(res)){
            premier = true;
        }
    }
    return res;
}

int main(){
    cout<<premier_aleatoire()<<endl;
}