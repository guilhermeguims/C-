#include "Telefone.h"
namespace TrabalhoLocadora{
Telefone::Telefone(int DDI ,int DDD ,int numero){
    this->DDI=DDI;
    this->DDD=DDD;
    this->Numero=numero;
}
void Telefone::setDDI(int ddi){
    this->DDI=ddi;
}
int Telefone::getDDI()const{
     return DDI;
}
void Telefone::setDDD(int ddd){
    this->DDD=ddd;
}
int Telefone::getDDD()const{
     return DDD;
}
void Telefone::setNumero(int numero){
    this->Numero=numero;
}
int Telefone::getNumero()const{
    return Numero;
}

}
