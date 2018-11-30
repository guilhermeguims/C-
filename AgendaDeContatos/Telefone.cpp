#include "Telefone.h"
namespace TP2{
Telefone::Telefone(int DDI ,int DDD ,int numero){
    this->DDI=DDI;
    this->DDD=DDD;
    this->Numero=numero;
}
void Telefone::setDDI(int ddi){
    this->DDI=ddi;
}
void Telefone::setDDD(int ddd){
    this->DDD=ddd;
}
void Telefone::setNumero(int numero){
    this->Numero=numero;
}
int Telefone::getDDI()const{
     return DDI;
}
int Telefone::getDDD()const{
     return DDD;
}
int Telefone::getNumero()const{
    return Numero;
}

}
