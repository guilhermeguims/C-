#ifndef CRUDDOCLIENTE_H
#define CRUDDOCLIENTE_H
#include<list>
#include<Cliente.h>

namespace TrabalhoLocadora{
class CrudDoCliente
{
public:
    virtual void Incluir(Cliente &ClienteNovo)const=0;
   // virtual void Excluir(QString CPF)const=0;
    //virtual std::list<Cliente>* Listar()const = 0;
    //virtual std::list<Cliente>* Consultar(QString CPF)const = 0;

};
}
#endif // CRUDDOCLIENTE_H
