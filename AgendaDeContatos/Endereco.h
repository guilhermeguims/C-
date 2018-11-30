#ifndef ENDERECO_H
#define ENDERECO_H
#include<QString>
namespace TP2{
class Endereco
{
private:
    QString Logradouro;
    int Numero;
    int CEP;

public:
    Endereco(QString Logradouro,int numero,int cep);
    void setLogradouro(QString Logradouro);
    void setNumero(int numero);
    void setCep(int cep);
    QString getLogradouro()const;
    int getNumero()const;
    int getCep()const;

};
}
#endif // ENDERECO_H
