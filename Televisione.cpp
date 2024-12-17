// Televisione

/* 
    Creare una classe Televisione sapendo che lo stato di una televisione è caratterizzato
    dal fatto di essere accesa o spenta, dal volume (che è compreso tra 0 e 10), dal canale
    (compreso tra 0 e 99) e dal fatto che sia in modalità silenzioso o meno 
*/

#include <iostream>

using namespace std;

// Dichiarazione costanti
const int e=10;
const int e1=99;

// Definizione classe 
class Televisione{
    private:
        bool stato,silenzioso;
        int vol,can;
    
    public:

        Televisione(){
            stato=0;
            silenzioso=0;
            vol=0;
            can=0;
        }

        bool get_stato();
        bool get_silenzioso();
        int get_vol();
        int get_can();

        bool set_stato(bool);
        bool set_silenzioso(bool);
        int set_vol(int);
        int set_can(int);
};

// Prototipi
int menu(Televisione ogg);
bool controllo(int input, int max_val);


int main(){

    Televisione ogg;
    int s;
    bool c=0;

    do{
        system("cls");

        s=menu(ogg);

        switch(s){

            case 1:{
                cout<<"\tINFORMAZIONI TELEVISIONE"<<endl;
                cout<<"Stato: ";

                if(ogg.get_stato()){
                    cout<<"Accesa"<<endl;
                }
                else{
                    cout<<"Spenta"<<endl;
                }

                cout<<"Silenzioso: ";

                if(ogg.get_silenzioso()){
                    cout<<"Abilitato"<<endl;
                }
                else{
                    cout<<"Disabilitato"<<endl;
                }

                cout<<"Volume: "<<ogg.get_vol()<<endl;
                cout<<"Canale: "<<ogg.get_can()<<endl;

                break;
            }

            case 2:{

                if(!ogg.get_stato()){
                    ogg.set_stato(1);
                }
                else{
                    ogg.set_stato(0);
                }

                cout<<"Stato televisione: ";

                if(ogg.get_stato()){
                    cout<<"Accessa"<<endl;
                }
                else{
                    cout<<"Spenta"<<endl;
                }

                break;
            }

            case 3:{

                if(!ogg.get_silenzioso()){
                    ogg.set_silenzioso(1);
                }
                else{
                    ogg.set_silenzioso(0);
                }

                cout<<"Stato silenzioso: ";

                if(ogg.get_silenzioso()){
                    cout<<"Abilitato"<<endl;
                }
                else{
                    cout<<"Disabilitato"<<endl;
                }

                break;
            }

            case 4:{

                int vol;

                do{
                    cout<<"Inserisci il volume: ";
                    cin>>vol;
                }while(!controllo(vol,e));

                ogg.set_vol(vol);

                cout<<"Volume aggiornato: "<<ogg.get_vol()<<endl;

                break;
            }

            case 5:{

                int can;

                do{
                    cout<<"Inserisci il canale: ";
                    cin>>can;
                }while(!controllo(can,e1));

                ogg.set_can(can);

                cout<<"Canale aggiornato: "<<ogg.get_can()<<endl;

                break;
            }

            case 0:{
                cout<<"Arrivederci"<<endl;
                break;
            }

            default:{
                cout<<"ERRORE: scelta non valida"<<endl;
                break;
            }
        }

        cout<<"\nPremi un tato per continuare... ";
        cin.ignore();
        cin.get();

    }while(s!=0);

    return 0;
}

// Metodi della classe
bool Televisione::get_stato(){
    return stato;
}

bool Televisione::get_silenzioso(){
    return silenzioso;
}

int Televisione::get_vol(){
    return vol;
}

int Televisione::get_can(){
    return can;
}

bool Televisione::set_stato(bool dato){
    
    if(dato==1){
        stato=1; // Televisione accesa
    }
    else{
        stato=0; // Televisione spenta
    }
}

bool Televisione::set_silenzioso(bool dato){

    if(dato==1){
        silenzioso=1; // Silenzioso attivo
    }
    else{
        silenzioso=0; // Silenzioso disattivato
    }
}

int Televisione::set_vol(int dato){
    vol=dato;
}

int Televisione::set_can(int dato){
    can=dato;
}

// Prototipi
int menu(Televisione ogg){

    int s;

    cout<<"\t-----Menu-----"<<endl;
    cout<<"1) Stampa dati televisione"<<endl;
    
    if(!ogg.get_stato()){
        cout<<"2) Accendi televisore"<<endl;
    }
    else{
        cout<<"2) Spegni televisione"<<endl;

        if(!ogg.get_silenzioso()){
            cout<<"3) Metti in silenzioso"<<endl;
        }
        else{
            cout<<"3) Togli il silenzioso"<<endl;
        }
        cout<<"4) Modifica il volume"<<endl;
        cout<<"5) Modifica il canale"<<endl;
    }
    cout<<"0) Esci"<<endl;

    cout<<"\nInserisci scelta: ";
    cin>>s;

    if(!ogg.get_stato() && (s>2 || s<0)){
        return -1;
    }

    cout<<endl;

    return s;
}

bool controllo(int input, int max_val){

    if(input>max_val || input<0){
        cout<<"Inserisci un valore tra 0 e "<<max_val<<"\n"<<endl;
        return 0;
    }
    else{
        return 1;
    }
}