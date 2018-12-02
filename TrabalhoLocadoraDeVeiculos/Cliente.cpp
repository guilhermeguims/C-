#include "Cliente.h"
namespace TrabalhoLocadora{
Cliente::Cliente(){
    Nome = "";
    CPF = "";
    Email= "";
    Fone = new Telefone(0,0,0);
    EnderecoDoCliente = new Endereco("",0,0);

}
Cliente::~Cliente(){}
void Cliente::setNome(QString Nome){
    this->Nome = Nome;
}
QString Cliente::getNome()const{
    return Nome;
}
void Cliente::setCarteira(CNH *Carteira){
    this->Carteira=Carteira;
}
CNH* Cliente::getCarteira()const{
    return Carteira;
}

void Cliente::setEmail(QString Email){
    this->Email = Email;
}
QString Cliente::getEmail()const{
    return Email;
}
void Cliente::setTelefone(Telefone* Fone){
    this->Fone = Fone;
}
Telefone* Cliente::getTelefone()const{
    return Fone;
}
void Cliente::setCPF(QString CPF){
    this->CPF = CPF;
}
QString Cliente::getCPF()const{
    return CPF;
}
void Cliente::setEndereco(Endereco* EnderecoDoCliente){
    this->EnderecoDoCliente = EnderecoDoCliente;
}
Endereco* Cliente::getEndereco()const{
    return EnderecoDoCliente;
}
QString Cliente::ClienteDados()const{
    QString Saida;
    Saida+= Nome;
    Saida+=";";
    Saida+=CPF;
    Saida+=";";
    Saida+=QString::number(Fone->getDDI());
    Saida+=";";
    Saida+=QString::number(Fone->getDDD());
    Saida+=";";
    Saida+=QString::number(Fone->getNumero());
    Saida+=";";
    Saida+=Email;
    Saida+=";";
    Saida+=Carteira->getNumeroCNH();
    Saida+=";";
    Saida+=Carteira->getCategoria();
    Saida+=";";
    Saida+=QString::number(Carteira->getData()->getDia());
    Saida+=";";
    Saida+=QString::number(Carteira->getData()->getMes());
    Saida+=";";
    Saida+=QString::number(Carteira->getData()->getAno());
    Saida+=";";
    Saida+=EnderecoDoCliente->getLogradouro();
    Saida+=";";
    Saida+=QString::number(EnderecoDoCliente->getNumero());
    Saida+=";";
    Saida+=QString::number(EnderecoDoCliente->getCep());
    return Saida;
     

}
}
