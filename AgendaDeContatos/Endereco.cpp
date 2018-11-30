#include "Endereco.h"
namespace TP2{
Endereco::Endereco(QString Logradouro,int numero,int cep){
    this->Logradouro=Logradouro;
    this->Numero=numero;
    this->CEP=cep;
}
void Endereco::setLogradouro(QString Logradouro){
    this->Logradouro=Logradouro;
}
void Endereco::setNumero(int numero){
    this->Numero=numero;
}
void Endereco::setCep(int cep){
    this->CEP=cep;
}
QString Endereco::getLogradouro()const{
    return Logradouro;
}
int Endereco::getNumero()const{
    return Numero;
}
int Endereco::getCep()const{
    return CEP;
}
}
