#include <iostream>
#include <string.h>

using namespace std;
struct pereche{
   string nume;
   int an;
};
class Mormant{
private:
    static int contorId;
    const int idMormant;
    int nrPredecesori;
    string numePosesor;
    float arie;
    bool ocupat;
    pereche *mortEx;
public:
//Constructori
    
    Mormant();// Constructor fara parametrii
    Mormant(string numePosesor, float arie,int nrPredecesori, pereche* mortEx, bool ocupat);//Constructor cu parametrii
    Mormant(string numePosesor, float arie);
    Mormant(int nrPredecesori, pereche* mortEx);
    
    Mormant(const Mormant& obj);//Constructor de copiere

//Operatori
    Mormant& operator = (const Mormant&);
    friend istream& operator >>(istream& in, Mormant& obj);
    friend ostream& operator <<(ostream& out, const Mormant& obj);
    
//Metode
    void afisare();
    
//Get+Set
    int getIdMormant(){ return idMormant; }
    string getNumePosesor(){return numePosesor;}
    
//Destructori
    ~Mormant();
};
int Mormant::contorId = 1000;

Mormant::Mormant(): idMormant(contorId++){
    numePosesor = "mormânt fără posesor";
    arie = 0;
    ocupat = 0;
    nrPredecesori=0;
    mortEx=nullptr;
    
}
Mormant::Mormant(string numePosesor, float arie,int nrPredecesori, pereche mortEx[], bool ocupat): idMormant(contorId++){
    this ->numePosesor = numePosesor;
    this-> arie = arie;
    this->nrPredecesori=nrPredecesori;
    this->mortEx=new pereche[nrPredecesori];
    for(int i = 0; i<nrPredecesori; i++){
        this->mortEx[i].an = mortEx[i].an;
        this->mortEx[i].nume = mortEx[i].nume;
    }
}
Mormant::Mormant(const Mormant& obj): idMormant(contorId++){
    this ->numePosesor = obj.numePosesor;
    this-> arie = obj.arie;
    this->nrPredecesori= obj.nrPredecesori;
    this->mortEx = new pereche[nrPredecesori];
    for(int i = 0; i<obj.nrPredecesori; i++){
        this->mortEx[i].an = obj.mortEx[i].an;
        this->mortEx[i].nume = obj.mortEx[i].nume;
    }
}
Mormant& Mormant::operator = (const Mormant& obj){
    if(this != &obj){
        this->numePosesor = obj.numePosesor;
        this->arie = obj.arie;
        this->nrPredecesori=obj.nrPredecesori;
        for(int i = 0; i<obj.nrPredecesori; i++){
            this->mortEx[i].an = obj.mortEx[i].an;
            this->mortEx[i].nume = obj.mortEx[i].nume;
        }
        this->ocupat = obj.ocupat;
    }
    return *this;
}

istream& operator>>(istream& in, Mormant& obj){
    cout<<"Introdu numele proprietarului: ";
    getline(in, obj.numePosesor);
    cout<<"Introdu aria locului(metrii pătrați): ";
    in >> obj.arie;
    cout<<"Introdu numarul persoanelor care au fost inmormantate in acest mormânt: ";
    in >> obj.nrPredecesori;
    if(obj.mortEx != nullptr){
        delete [] obj.mortEx;
        obj.mortEx = nullptr;
        
    }
        
    if(obj.nrPredecesori!=0){
        obj.mortEx = new pereche[obj.nrPredecesori];
        cout<<"Intordu datele persoanelor care au fost inmormantate aici:"<<endl;
    }
    
    for(int i = 0; i<obj.nrPredecesori; i++){
        cout<<"\t"<<"Numele persoanei nr."<<i+1<<": ";
        in.ignore();
        getline(in, obj.mortEx[i].nume);
        cout<<"\t"<<"Anul înmormantarii persoanei "<<obj.mortEx[i].nume<<": ";
        in>>obj.mortEx[i].an;
    }
    
    return in;
}
ostream& operator<<(ostream& out, const Mormant& obj){
    out<<"Numele proprietarului: "<<obj.numePosesor<<endl;
    out<<"Aria mormântului este: "<<obj.arie<<endl;
    if(obj.nrPredecesori==0){
        out<<"În acest mormânt nu a mai fost înmormantat nimeni."<<endl;
    }
    else
        out<<"Persoanele înmormântate in acest loc: "<<endl;
    for (int i = 0; i<obj.nrPredecesori; i++){
        out<<"\t"<<"În anul "<<obj.mortEx[i].an<<": "<< obj.mortEx[i].nume<<endl;
    }
    return out;
}
void Mormant::afisare(){
    
    cout<<"Posesorul acestui loc de veci este: "<<this->numePosesor<<endl;
    cout<<"ID Mormant: "<<this->idMormant<<endl;
    cout<<"Aria locului: "<<this->arie<<endl;
    if(this->mortEx==nullptr)//verific daca in mormant a fost cineva inmormantat vreodata
        cout<<"Acest loc de veci este nou-nout"<<endl;
    else{
        cout<<"In acest loc au mai fost înmormântate "<<nrPredecesori<<" persoane:"<<endl;
        for(int i = 0; i<this->nrPredecesori; i++)
            cout<<"\t" <<"Din anul "<<this->mortEx[i].an<<" se odihneste: "<<this->mortEx[i].nume<< endl;
    }
    if(ocupat)
        cout<<"Loc ocupat in momentul de fata"<<endl;
    else cout<<"Loc liber in momentul de fata"<<endl;
}
Mormant::~Mormant(){
    if(this->mortEx!=nullptr){
        
        delete[] mortEx;}
}
int main()
{
//    pereche a[5];
//    a[0].nume="Marian";
//    a[0].an=1400;
//    a[1].nume="Martin";
//    a[1].an=1503;
//    a[2].nume="Marius";
//    a[2].an=1640;
//    Mormant B("Florin Maniac", 4.5 ,3, a, true);
    Mormant X;
    cin>>X;
    cout<<X;
    
    return 0;
}

