#include "Agenda.h"
#include<QStringList>
#include<QMessageBox>

namespace TP2{
Agenda::Agenda(QString NomeDoArquivo):
    NomeDoArquivo(NomeDoArquivo)
{
}
void Agenda::Incluir(Contato &Fulano)const{
   try{
    std::fstream ArquivoAgenda;
    ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::app); //Cria o Arquivo , se ja criado , Escreve na Linha Abaixo
    if(!ArquivoAgenda.is_open()){  //Verifica se o Arquivo foi Aberto
        throw QString("Arquivo Nao Foi Aberto ou Criado");
    }
    QString Linha = Fulano.DadosDoContato();
    std::string LinhaDoArquivo = Linha.toStdString();
    int Tamanho = LinhaDoArquivo.length();
    //Conversao Do Dados para Letra Maiscuala
    for(int i=0;i<Tamanho;i++){
       LinhaDoArquivo[i]= toupper(LinhaDoArquivo[i]);
    }
    ArquivoAgenda<<LinhaDoArquivo<<std::endl; // Escrevendo no Arquivo
   ArquivoAgenda.close(); // Fechando Arquivo
    }catch(std::bad_alloc&){
        throw QString("Memoria Insuficiente.");
    }
}
void Agenda::Excluir(QString CPF) const{
 try{
     std::fstream ArquivoAgenda;
     std::stack<Contato> PilhaAux; //Criando uma Pilha de Contatos
     ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::in); //Abre Arquivo para Leitura
     //Verifica se Nao Foi Aberto
     if(!ArquivoAgenda.is_open()){
         throw QString("Arquivo Nao Foi Aberto ou Criado");
     }
         std::string Linha;
         std::getline(ArquivoAgenda,Linha); //Lendo a Linha do Arquivo
          Contato Fulano;
          while(!ArquivoAgenda.eof()){
              QString LinhaAux = QString::fromStdString(Linha); //Conversão da Linha do Arquivo para QString
              QStringList Dados = LinhaAux.split(';');  // A Cada ';' se retorna um Dado
              //Setando os Dados Obtidos na Linha para o Contato
              Fulano.SetNome(Dados[0]);
              Fulano.SetCPF(Dados[1]);
              Fulano.SetTelefone(new TP2::Telefone(Dados[2].toInt(),Dados[3].toInt(),Dados[4].toInt()));
              Fulano.SetEmail(Dados[5]);
              Fulano.SetEndereco(new TP2::Endereco(Dados[6],Dados[7].toInt(),Dados[8].toInt()));
             std::getline(ArquivoAgenda,Linha);
             //Verifica se O CPF do Contato é Diferente Do Informado
             if(CPF != Fulano.GetCPF()){
             PilhaAux.push(Fulano); //Empilhando Contato na Pilha de Contato
             }
         }
        ArquivoAgenda.close(); // Fechando Arquivo
         ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::out); // Abre o Arquivo , deletetando tudo que ele Tinha
         if(!ArquivoAgenda.is_open()){
             throw QString("Arquivo Não Foi Aberto ou Criado");
         }
         // Desempilhando a Pilha e Guardando no Arquivo
         while(!PilhaAux.empty()){
                Contato Fulano;
                Fulano = PilhaAux.top(); //Topo Da Pilha

               ArquivoAgenda<<Fulano.DadosDoContato().toStdString()<<std::endl; //Escrevendo no Arquivo
               PilhaAux.pop();//Proximo Elemento da Pilha
         }
        ArquivoAgenda.close(); // Fechando Arquivo
} catch(std::bad_alloc&){
        throw QString("Memoria Insuficiente.");
    }

}
std::list<Contato>* Agenda::Listar()const{
  try{
    std::fstream ArquivoAgenda;
    ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::in); //Abre Arquivo Para Leitura
    if(!ArquivoAgenda.is_open()){
        throw QString("Arquivo Não Foi Aberto ou Criado");
    }
    std::list<Contato>* ListaDeContatos = new std::list<Contato>; //Criando uma Lista do Tipo Contato
    std::string Linha;
    getline(ArquivoAgenda,Linha); //Lendo a Linha do Arquivo

    while(!ArquivoAgenda.eof()){
         TP2::Contato * Fulano = new TP2::Contato;
         QString LinhaAux = QString::fromStdString(Linha);
         QStringList Dados = LinhaAux.split(';');
         //Setando os Dados
         Fulano->SetNome(Dados[0]);
         Fulano->SetCPF(Dados[1]);
         Fulano->SetTelefone(new TP2::Telefone(Dados[2].toInt(),Dados[3].toInt(),Dados[4].toInt()));
         Fulano->SetEmail(Dados[5]);
         Fulano->SetEndereco(new TP2::Endereco(Dados[6],Dados[7].toInt(),Dados[8].toInt()));
         ListaDeContatos->push_back(*Fulano);
         getline(ArquivoAgenda,Linha);
    }
   ArquivoAgenda.close(); // Fechando Arquivo
    return ListaDeContatos;
    } catch(std::bad_alloc&){
        throw QString("Memoria Insuficiente.");
    }

}
Contato* Agenda::Alterar(QString CPF) const{
try{
  std::fstream ArquivoAgenda;
  std::stack<Contato> PilhaAux;
  Contato *ContatoAlterar = new Contato();
 ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::in);
 if(!ArquivoAgenda.is_open()){
     throw QString("Arquivo Não Foi Aberto ou Criado");
 }
    std::string Linha;
    std::getline(ArquivoAgenda,Linha);
     Contato Fulano;
     while(!ArquivoAgenda.eof()){
         QString LinhaAux = QString::fromStdString(Linha);
         QStringList Dados = LinhaAux.split(';');
         Fulano.SetNome(Dados[0]);
         Fulano.SetCPF(Dados[1]);
         TP2::Telefone *Numero = new TP2::Telefone(Dados[2].toInt(),Dados[3].toInt(),Dados[4].toInt());
         Fulano.SetTelefone(Numero);
         Fulano.SetEmail(Dados[5]);
         Fulano.SetEndereco(new TP2::Endereco(Dados[6],Dados[7].toInt(),Dados[8].toInt()));
        std::getline(ArquivoAgenda,Linha);
        //Se o CPF for igual Do que foi Informado cria se um Contato
        if(CPF == Fulano.GetCPF()){
           ContatoAlterar->SetNome(Fulano.GetNome());
           ContatoAlterar->SetCPF(Fulano.GetCPF());
           ContatoAlterar->SetTelefone(Fulano.GetTelefone());
           ContatoAlterar->SetEndereco(Fulano.GetEndereco());
           ContatoAlterar->SetEmail(Fulano.GetEmail());
        }
        else{
            PilhaAux.push(Fulano); // Senão Empilha o Contato na Pilha Aux
        }
    }
   ArquivoAgenda.close(); // Fechando Arquivo
    ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::out);
    if(!ArquivoAgenda.is_open()){
        throw QString("Arquivo Não Foi Aberto ou Criado");
    }
    while(!PilhaAux.empty()){
           Contato Fulano;
           Fulano = PilhaAux.top(); //Desempilhando a Pilha
          ArquivoAgenda<<Fulano.DadosDoContato().toStdString()<<std::endl; //Escrevendo no Arquivo
          PilhaAux.pop();
    }
   ArquivoAgenda.close(); // Fechando Arquivo
    return ContatoAlterar;
    } catch(std::bad_alloc&){
            throw QString("Memoria Insuficiente.");
        }

}
std::list<Contato>* Agenda::Consultar(QString CPF) const{
     try{
        std::fstream ArquivoAgenda;
        ArquivoAgenda.open(NomeDoArquivo.toStdString().c_str(),std::ios::in);
        if(!ArquivoAgenda.is_open()){
          throw QString("Arquivo Não Foi Aberto Ou Não Foi Criado.");
        }
        std::string Linha;
        std::getline(ArquivoAgenda,Linha);
        Contato Fulano;
        std::list<Contato> * ContatoDaAgenda = new std::list<Contato>();
        while(!ArquivoAgenda.eof()){
              QString LinhaAux = QString::fromStdString(Linha);
              QStringList Dados = LinhaAux.split(';');
              Fulano.SetNome(Dados[0]);
              Fulano.SetCPF(Dados[1]);
              Fulano.SetTelefone(new TP2::Telefone(Dados[2].toInt(),Dados[3].toInt(),Dados[4].toInt()));
              Fulano.SetEmail(Dados[5]);
              Fulano.SetEndereco(new TP2::Endereco(Dados[6],Dados[7].toInt(),Dados[8].toInt()));
              if(CPF == Fulano.GetCPF()){
              ContatoDaAgenda->push_back(Fulano);
              }
              std::getline(ArquivoAgenda,Linha);
        }
       ArquivoAgenda.close(); // Fechando Arquivo
        return ContatoDaAgenda;
    }
    catch(std::bad_alloc&){
            throw QString("Memoria Insuficiente.");
        }
}
}

