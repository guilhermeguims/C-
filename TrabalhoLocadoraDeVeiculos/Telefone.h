#ifndef TELEFONE_H
#define TELEFONE_H
#include<QString>
namespace TrabalhoLocadora{
class Telefone
{
private:
    int DDD;
    int DDI;
    int Numero;
public:
    Telefone(int ddi,int ddd,int numero);
    void setDDI(int ddi);
    int getDDI()const;
    void setDDD(int ddd);
    int getDDD()const;
    void setNumero(int numero);
    int getNumero()const;

};
}

#endif // TELEFONE_H
