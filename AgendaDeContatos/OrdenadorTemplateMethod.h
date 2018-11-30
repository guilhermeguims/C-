#ifndef ORDENADORTEMPLATEMETHOD_H
#define ORDENADORTEMPLATEMETHOD_H
#include"Contato.h"
#include<QString>
#include<list>
namespace TP2 {

class OrdenadorTemplateMethod
{
public:
    virtual bool ePrimeiro(Contato X, Contato Y)= 0;
    void ordenarContato(std::list<Contato> &ListaDeContatos);
};
}
#endif // ORDENADORTEMPLATEMETHOD_H
