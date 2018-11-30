#ifndef AGENDA_H
#define AGENDA_H
#include"CRUD.h"
#include<fstream>
#include<iostream>
#include<cctype>
#include<list>
#include<stack>

namespace TP2{
class Agenda:public CRUD
{
private:
    QString NomeDoArquivo;
public:
    Agenda(QString NomeDoArquivo);
    void Incluir(Contato &Fulano)const;
    void Excluir(QString CPF)const;
    std::list<Contato>* Listar()const;
    Contato* Alterar(QString CPF)const;
    std::list<Contato>* Consultar(QString CPF)const;
};
}
#endif // AGENDA_H
