#ifndef TELEFONE_H
#define TELEFONE_H
#include<QString>
namespace TP2{
class Telefone
{
private:
    int DDD;
    int DDI;
    int Numero;
public:
    Telefone(int ddi,int ddd,int numero);
    void setDDI(int ddi);
    void setDDD(int ddd);
    void setNumero(int numero);
    int getDDI()const;
    int getDDD()const;
    int getNumero()const;

};
}

#endif // TELEFONE_H
