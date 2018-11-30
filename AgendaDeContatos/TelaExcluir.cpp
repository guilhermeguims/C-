#include "TelaExcluir.h"
#include "ui_TelaExcluir.h"
#include"Contato.h"
#include"Agenda.h"
#include<QMessageBox>

TelaExcluir::TelaExcluir(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaExcluir)
{
    ui->setupUi(this);
}

TelaExcluir::~TelaExcluir()
{
    delete ui;
}


void TelaExcluir::on_pushButton_Excluir_clicked()
{
    try{
      QString CPF = ui->lineEdit_cpf->text();
      TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
      std::list<TP2::Contato> * ContatoDaAgenda = ContatoNaAgenda.Consultar(CPF);
      //Verificando se a LineEdit Cpf esta Vazia
      if(ContatoDaAgenda->empty()&& CPF==""){
          QMessageBox::information(this, "Erro","Campo CPF Vazio!");
          }
     //Verificando se o Contato Existe
     else if(ContatoDaAgenda->empty()&& CPF!=""){
          QMessageBox::information(this, "Erro","Contato Nao Se Encontra Na Agenda !");
          }
      else{
      //Excluindo o Contato
      ContatoNaAgenda.Excluir(CPF);
      ui->Lista->clearContents();
      QMessageBox::information(this, "Operaçao","Contato Excluido Com Sucesso !");
      }
    }catch(std::bad_alloc&){
        QMessageBox::information(this, "Erro no Sistema","Metodo Excluir nao pode ser execultado");
    }
   }

void TelaExcluir::on_pushButton_clicked()
{
    try{
          TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
          QString CPF = ui->lineEdit_cpf->text();
          std::list<TP2::Contato> * ContatoDaAgenda = ContatoNaAgenda.Consultar(CPF);
          //Verificando se a LineEdit esta Vazia
          if(CPF==""){
              QMessageBox::information(this, "Erro","Campo CPF Vazio !");
              }
          //Verificando se o Contato se Encontra na Agenda
          else if(ContatoDaAgenda->empty()&& CPF!=""){
              QMessageBox::information(this, "Erro","Contato Nao Se Encontra Na Agenda !");
              }
          else{
          ui->Lista->setRowCount(0);
          TP2::Contato Fulano;
          Fulano = ContatoDaAgenda->front();//Contato Recebe o Primeiro da Lista

          //Formatando o Endereço para sair na Lista
          QString Endereco = Fulano.GetEndereco()->getLogradouro();
          Endereco+=" N:";
          Endereco+=QString::number(Fulano.GetEndereco()->getNumero());
          Endereco+=" CEP:";
          Endereco+=QString::number(Fulano.GetEndereco()->getCep());

          //Formatando o Endereço para Sair na Lista
          QString Telefone ="+ ";
          Telefone+=QString::number(Fulano.GetTelefone()->getDDI());
          Telefone+=" (";
          Telefone+=QString::number(Fulano.GetTelefone()->getDDD());
          Telefone+=") ";
          Telefone+=QString::number(Fulano.GetTelefone()->getNumero());

          //Lista
          QTableWidgetItem *ColunaNome = new QTableWidgetItem(Fulano.GetNome());
          QTableWidgetItem *ColunaCPF = new QTableWidgetItem(Fulano.GetCPF());
          QTableWidgetItem *ColunaTelefone = new QTableWidgetItem(Telefone);
          QTableWidgetItem *ColunaEmail = new QTableWidgetItem(Fulano.GetEmail());
          QTableWidgetItem *ColunaEndereco = new QTableWidgetItem(Endereco);
          int Linha;
          Linha = ui->Lista->rowCount();
          ui->Lista->insertRow(Linha);
          ui->Lista->setItem(Linha,0,ColunaNome);
          ui->Lista->setItem(Linha,1,ColunaCPF);
          ui->Lista->setItem(Linha,2,ColunaTelefone);  //Setando os Dados do Contato na Lista
          ui->Lista->setItem(Linha,3,ColunaEmail);
          ui->Lista->setItem(Linha,4,ColunaEndereco);

      }
      }catch(std::bad_alloc&){
          QMessageBox::information(this, "Erro no Sistema","Metodo Excluir nao pode ser execultado");
      }
      //Ajustando a Lista de Acordo com o Tamanho do Contato
      ui->Lista->resizeColumnsToContents();
      ui->Lista->resizeRowsToContents();
   }


void TelaExcluir::on_pushButton_Voltar_clicked()
{
    TelaExcluir::close();
}
