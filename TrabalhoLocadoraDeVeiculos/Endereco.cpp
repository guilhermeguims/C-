#include "Endereco.h"
namespace TrabalhoLocadora{
Endereco::Endereco(QString Logradouro,int numero,int cep){
    this->Logradouro=Logradouro;
    this->Numero=numero;
    this->CEP=cep;
}
void Endereco::setLogradouro(QString Logradouro){
    this->Logradouro=Logradouro;
}
QString Endereco::getLogradouro()const{
    return Logradouro;
}
void Endereco::setNumero(int numero){
    this->Numero=numero;
}
int Endereco::getNumero()const{
    return Numero;
}
void Endereco::setCep(int cep){
    this->CEP=cep;
}
int Endereco::getCep()const{
    return CEP;
}
}
