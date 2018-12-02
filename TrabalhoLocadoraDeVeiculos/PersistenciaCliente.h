#ifndef PERSISTENCIACLIENTE_H
#define PERSISTENCIACLIENTE_H
#include"CrudDoCliente.h"
#include<QString>
#include <fstream>
namespace TrabalhoLocadora{
class PersistenciaCliente :public CrudDoCliente
{
private:
     QString NomeDoArquivo;
public:
    PersistenciaCliente(QString NomeDoArquivo);
    void Incluir(Cliente &ClienteNovo)const;
    //void Excluir(QString CPF)const;
    //std::list<Cliente>* Listar()const;
   // std::list<Cliente>* Consultar(QString CPF)const;
};
}
#endif // PERSISTENCIACLIENTE_H
