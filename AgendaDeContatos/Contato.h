#ifndef CONTATO_H
#define CONTATO_H
#include<QString>
#include<QStringList>
#include"Telefone.h"
#include"Endereco.h"
namespace TP2{
class Contato
{
private:
    QString Nome;
    Telefone *Fone;
    QString Email;
    QString CPF;
    Endereco *EnderecoDoContato;
public:
    Contato();
    void SetNome(QString Nome);
    void SetTelefone(Telefone* Fone);
    void SetEmail(QString Email);
    void SetCPF(QString CPF);
    void SetEndereco(Endereco* EnderecoDoContato);
    QString  DadosDoContato()const;
    QString  GetNome()const;
    Telefone* GetTelefone()const;
    QString  GetEmail()const;
    QString  GetCPF()const;
    Endereco* GetEndereco()const;
};
}
#endif // CONTATO_H
