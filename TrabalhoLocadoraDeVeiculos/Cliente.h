#ifndef CLIENTE_H
#define CLIENTE_H
#include<QString>
#include<QStringList>
#include"Telefone.h"
#include"Endereco.h"
#include"CNH.h"
namespace TrabalhoLocadora{
class Cliente
{
private:
    QString Nome;
    CNH * Carteira;
    Telefone * Fone;
    QString Email;
    QString CPF;
    Endereco * EnderecoDoCliente;
public:
    Cliente();
    ~Cliente();
    void setCarteira(CNH* Carteira);
    CNH* getCarteira()const;
    void setNome(QString Nome);
    QString  getNome()const;
    void setTelefone(Telefone* Fone);
    Telefone* getTelefone()const;
    void setEmail(QString Email);
    QString  getEmail()const;
    void setCPF(QString CPF);
    QString  getCPF()const;
    void setEndereco(Endereco* EnderecoDoCliente);
    Endereco* getEndereco()const;

    QString ClienteDados()const;


};
}
#endif // CLIENTE_H
