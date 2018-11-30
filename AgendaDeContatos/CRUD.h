#ifndef CRUD_H
#define CRUD_H
#include"Contato.h"
#include<iostream>
#include<list>
#include<QString>

namespace TP2{
class CRUD
{
public:
    virtual void Incluir(Contato &Fulano)const=0;
    virtual void Excluir(QString CPF)const=0;
    virtual std::list<Contato>* Listar()const = 0;
    virtual Contato* Alterar(QString CPF)const =0;
    virtual std::list<Contato>* Consultar(QString CPF)const = 0;

};
}

#endif // CRUD_H
