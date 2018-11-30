#include "Contato.h"
namespace TP2{
Contato::Contato(){
    Nome = "";
    CPF = "";
    Email= "";
    Fone = new Telefone(0,0,0);
    EnderecoDoContato = new Endereco("",0,0);

}
void Contato::SetNome(QString Nome){
    this->Nome=Nome;
}
void Contato::SetEmail(QString Email){
    this->Email=Email;
}
void Contato::SetTelefone(Telefone* Fone){
    this->Fone=Fone;
}
void Contato::SetCPF(QString CPF){
    this->CPF=CPF;
}
void Contato::SetEndereco(Endereco* EnderecoDoContato){
    this->EnderecoDoContato=EnderecoDoContato;
}

QString Contato::DadosDoContato()const{
    QString Saida;
    Saida= Nome;
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
    Saida+=EnderecoDoContato->getLogradouro();
    Saida+=";";
    Saida+=QString::number(EnderecoDoContato->getNumero());
    Saida+=";";
    Saida+=QString::number(EnderecoDoContato->getCep());
    return Saida;
}

QString Contato::GetNome()const{
    return Nome;
}
QString Contato::GetEmail()const{
    return Email;
}
Telefone* Contato::GetTelefone()const{
    return Fone;
}
QString Contato::GetCPF()const{
    return CPF;
}
Endereco* Contato::GetEndereco()const{
    return EnderecoDoContato;
}
}
