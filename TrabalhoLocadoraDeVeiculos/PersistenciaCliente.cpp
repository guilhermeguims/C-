#include "PersistenciaCliente.h"
namespace TrabalhoLocadora{
PersistenciaCliente::PersistenciaCliente(QString NomeDoArquivo):
    NomeDoArquivo(NomeDoArquivo)
   {
   }

void PersistenciaCliente::Incluir(Cliente &Novo)const{
 try{
       std::ofstream ArquivoCliente;
   ArquivoCliente.open(NomeDoArquivo.toStdString().c_str(),std::ios::app); //Cria o Arquivo , se ja criado , Escreve na Linha Abaixo
             if(!ArquivoCliente.is_open()){  //Verifica se o Arquivo foi Aberto
             throw QString("Arquivo Nao Foi Aberto ou Criado");}
      QString Linha = Novo.ClienteDados();
      std::string LinhaDoArquivo = Linha.toStdString();
   ArquivoCliente<<LinhaDoArquivo<<std::endl; // Escrevendo no Arquivo
   ArquivoCliente.close();} // Fechando Arquivo
 catch(std::bad_alloc&){
     throw QString("Memoria Insuficiente.");}
  }

}
