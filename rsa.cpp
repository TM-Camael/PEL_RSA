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
    int menu;
    do{
        cout<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        cout<<"1. Créer une clé"<<endl;
        cout<<"2. Chiffrer un fichier en utilisant une clé"<<endl;
        cout<<"3. Déchiffrer un fichier en utilisant une clé"<<endl;
        cout<<"0. Quitter"<<endl<<endl;
        cout<<"Choix : ";
        cin>>menu;
        cout<<endl;
 
        switch(menu){
            case 0 : break;
 
            case 1 : {
                cout<<"Génération des clés en cours.."<<endl;
                init_alea();
                Cles test = genere_cles_aleatoire();
                string nom_cle;
                cout<<"Clés générés. Quel nom de fichier pour vos clés? "<<endl;
                cin>>nom_cle;
                cout<<endl;
                ofstream outputFilepub(nom_cle+".pub");
                ofstream outputFilepri(nom_cle+".pri");
                outputFilepub<<test.cle_publique.getN()<<","<<test.cle_publique.getE()<<endl;
                outputFilepri<<test.cle_privee.getN()<<","<<test.cle_privee.getD()<<endl;
                cout<<"Les clés ont bien été sauvegardés. "<<endl;
            }
            break;
 
            case 2 : {
                // Calcul taille fichier
                string nom_fichier;
                cout<<"Nom du fichier à chiffrer :"<<endl;
                cin>>nom_fichier;
                cout<<endl;
                string nom_fichier_chiffre;
                cout<<"Nom du fichier chiffré :"<<endl;
                cin>>nom_fichier_chiffre;
                cout<<endl;
                string nom_cle;
                cout<<"Entrez le nom du fichier de clé publique (avec extension du fichier)"<<endl;
                cin>>nom_cle;
                cout<<endl;
                ifstream fichier_cle(nom_cle);
                string temp;
                getline(fichier_cle, temp, ',');
                Entier cleN;
                istringstream(temp)>>cleN;
                getline(fichier_cle, temp);
                Entier cleE;
                istringstream(temp)>>cleE;
                ClePublique cle_pub = ClePublique(cleN,cleE);
                ifstream fichier(nom_fichier);
                fichier.seekg(0, fichier.end);
                Entier longueur_fichier = fichier.tellg();
                cout<<"Longueur du fichier :"<<longueur_fichier<<endl;
                fichier.seekg(0, fichier.beg);
                int taille_blocs = taille_bloc(longueur_fichier);
                cout<<"Taille bloc:"<<taille_blocs<<endl;
                ofstream fichier_chiffre(nom_fichier_chiffre);
                fichier_chiffre.write(reinterpret_cast<const char*>(&longueur_fichier), 8);
                fichier_chiffre.write(reinterpret_cast<const char*>(&taille_blocs), 8);
                int nombre_bloc = longueur_fichier/taille_blocs;
                char* buffer_lecture = new char[taille_blocs];
                for(int i=0; i<nombre_bloc; i++){
                    fichier.read(buffer_lecture,taille_blocs);
                    cout<<fichier.tellg()<<endl;
                    Entier convert;
                    string asciied;
                    for(int i=0; i<taille_blocs; i++){
                        asciied += to_string((int) buffer_lecture[i]);
                    }
                    cout<<"Codé:"<<&buffer_lecture[0]<<" FLAT : "<<asciied<<"| Taille bloc"<<taille_blocs<<endl;

                    istringstream(asciied)>>convert;
                    Entier m = code(buffer_lecture, taille_blocs);
                    cout<<"Valeur de M : "<<m<<endl;
                    Entier C = chiffre(cle_pub,m);
                    cout<<"Valeur de C : "<<C<<endl;
                    cout<<"Codé:"<<C<<" FLAT : "<<asciied<<endl;
                    fichier_chiffre.write(reinterpret_cast<const char*>(&C),64);
                }
                fichier.close();
                fichier_chiffre.close();
            }
            break;
 
            case 3 : {
                // Calcul taille fichier
                string nom_fichier;
                cout<<"Nom du fichier à déchiffrer :"<<endl;
                cin>>nom_fichier;
                cout<<endl;
                string nom_fichier_dechiffre;
                cout<<"Nom du fichier déchiffré :"<<endl;
                cin>>nom_fichier_dechiffre;
                cout<<endl;
                string nom_cle;
                cout<<"Entrez le nom du fichier de clé privée (avec extension du fichier)"<<endl;
                cin>>nom_cle;
                cout<<endl;
                ifstream fichier_cle(nom_cle);
                string temp;
                getline(fichier_cle, temp, ',');
                Entier cleN;
                istringstream(temp)>>cleN;
                getline(fichier_cle, temp);
                Entier cleD;
                istringstream(temp)>>cleD;
                ClePrivee cle_pri = ClePrivee(cleN,cleD);
                cout<<cleN<<endl;
                ifstream fichier(nom_fichier);
                int longueur_fichier=0;
                int taille_blocs=0;
                fichier.read(reinterpret_cast<char*>(&longueur_fichier),8);
                fichier.read(reinterpret_cast<char*>(&taille_blocs),8);
                cout<<"Longueur :"<<longueur_fichier<<endl;
                cout<<"Taille :"<<taille_blocs<<endl;
                char * buffer_lecture = new char[taille_blocs];
                int nombre_bloc = longueur_fichier/taille_blocs;
                for(int i=0; i<nombre_bloc; i++){
                    fichier.read(buffer_lecture,64);
                    cout<<int(buffer_lecture[0])<<int(buffer_lecture[1])<<endl;
                    Entier m = code(buffer_lecture,taille_blocs);
                    Entier C = dechiffre(cle_pri,m);
                    cout<<"--"<<C<<"----"<<endl;
                }
                fichier.close();
            }
            break; 
        }
 
    }while (menu!=0);
    
    return 0;
}

