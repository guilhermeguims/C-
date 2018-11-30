#include "TelaListar.h"
#include "ui_TelaListar.h"
#include<list>
#include"Contato.h"
#include"Agenda.h"
#include<QMessageBox>
#include"OrdenarPorNome.h"
#include"OrdenarPorCPF.h"
#include"OrdenarPorEmail.h"

TelaListar::TelaListar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaListar)
{
    ui->setupUi(this);
}

TelaListar::~TelaListar()
{
    delete ui;
}

void TelaListar::on_pushButton_Listar_clicked()
{
  try{
    TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
    std::list<TP2::Contato>* ListaDosContatos =  ContatoNaAgenda.Listar();
    ui->Lista->setRowCount(0);
    if(ListaDosContatos->empty()){
      QMessageBox::information(this, "Erro","Agenda Sem Contatos !");
    }
    else{
    while(!ListaDosContatos->empty()){
          TP2::Contato Fulano;
          Fulano = ListaDosContatos->front();
          QString Endereco = Fulano.GetEndereco()->getLogradouro();
          Endereco+=" N:";
          Endereco+=QString::number(Fulano.GetEndereco()->getNumero());
          Endereco+=" CEP:";
          Endereco+=QString::number(Fulano.GetEndereco()->getCep());

          QString Telefone ="+ ";
          Telefone+=QString::number(Fulano.GetTelefone()->getDDI());
          Telefone+=" (";
          Telefone+=QString::number(Fulano.GetTelefone()->getDDD());
          Telefone+=") ";
          Telefone+=QString::number(Fulano.GetTelefone()->getNumero());


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
          ui->Lista->setItem(Linha,2,ColunaTelefone);
          ui->Lista->setItem(Linha,3,ColunaEmail);
          ui->Lista->setItem(Linha,4,ColunaEndereco);
          ListaDosContatos->pop_front();
    }

}
    }
    catch(std::bad_alloc&){
            QMessageBox::information(this, "Erro no Sistema","Metodo Listar nao pode ser execultado");
        }
    ui->Lista->resizeColumnsToContents();
    ui->Lista->resizeRowsToContents();
}



void TelaListar::on_pushButton_clicked()
{
    TelaListar::close();
}



void TelaListar::on_comboBox_currentIndexChanged(const QString &arg1)
{
    try{
      TP2::Agenda ContatoNaAgenda("AgendaDeContato.CSV");
      std::list<TP2::Contato>* ListaDosContatos =  ContatoNaAgenda.Listar();
      ui->Lista->setRowCount(0);
      if(ListaDosContatos->empty()){
        QMessageBox::information(this, "Erro","Agenda Sem Contatos !");
      }
      else{
      if(arg1=="Nome"){
      TP2::OrdenarPorNome ListaOrdenada;
      ListaOrdenada.ordenarContato(*ListaDosContatos);
      while(!ListaDosContatos->empty()){
            TP2::Contato Fulano;
            Fulano = ListaDosContatos->front();
            QString Endereco = Fulano.GetEndereco()->getLogradouro();
            Endereco+=" N:";
            Endereco+=QString::number(Fulano.GetEndereco()->getNumero());
            Endereco+=" CEP:";
            Endereco+=QString::number(Fulano.GetEndereco()->getCep());

            QString Telefone ="+ ";
            Telefone+=QString::number(Fulano.GetTelefone()->getDDI());
            Telefone+=" (";
            Telefone+=QString::number(Fulano.GetTelefone()->getDDD());
            Telefone+=") ";
            Telefone+=QString::number(Fulano.GetTelefone()->getNumero());


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
            ui->Lista->setItem(Linha,2,ColunaTelefone);
            ui->Lista->setItem(Linha,3,ColunaEmail);
            ui->Lista->setItem(Linha,4,ColunaEndereco);
            ListaDosContatos->pop_front();
          }
  }
   if(arg1=="CPF"){
          TP2::OrdenarPorCPF ListaOrdenada;
          ListaOrdenada.ordenarContato(*ListaDosContatos);
          while(!ListaDosContatos->empty()){
                TP2::Contato Fulano;
                Fulano = ListaDosContatos->front();
                QString Endereco = Fulano.GetEndereco()->getLogradouro();
                Endereco+=" N:";
                Endereco+=QString::number(Fulano.GetEndereco()->getNumero());
                Endereco+=" CEP:";
                Endereco+=QString::number(Fulano.GetEndereco()->getCep());

                QString Telefone ="+ ";
                Telefone+=QString::number(Fulano.GetTelefone()->getDDI());
                Telefone+=" (";
                Telefone+=QString::number(Fulano.GetTelefone()->getDDD());
                Telefone+=") ";
                Telefone+=QString::number(Fulano.GetTelefone()->getNumero());


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
                ui->Lista->setItem(Linha,2,ColunaTelefone);
                ui->Lista->setItem(Linha,3,ColunaEmail);
                ui->Lista->setItem(Linha,4,ColunaEndereco);
                ListaDosContatos->pop_front();
          }
       }
    if(arg1=="Email"){
           TP2::OrdenarPorEmail ListaOrdenada;
           ListaOrdenada.ordenarContato(*ListaDosContatos);
           while(!ListaDosContatos->empty()){
                 TP2::Contato Fulano;
                 Fulano = ListaDosContatos->front();
                 QString Endereco = Fulano.GetEndereco()->getLogradouro();
                 Endereco+=" N:";
                 Endereco+=QString::number(Fulano.GetEndereco()->getNumero());
                 Endereco+=" CEP:";
                 Endereco+=QString::number(Fulano.GetEndereco()->getCep());

                 QString Telefone ="+ ";
                 Telefone+=QString::number(Fulano.GetTelefone()->getDDI());
                 Telefone+=" (";
                 Telefone+=QString::number(Fulano.GetTelefone()->getDDD());
                 Telefone+=") ";
                 Telefone+=QString::number(Fulano.GetTelefone()->getNumero());


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
                 ui->Lista->setItem(Linha,2,ColunaTelefone);
                 ui->Lista->setItem(Linha,3,ColunaEmail);
                 ui->Lista->setItem(Linha,4,ColunaEndereco);
                 ListaDosContatos->pop_front();
           }
         }
      }
     }
      catch(std::bad_alloc&){
              QMessageBox::information(this, "Erro no Sistema","Metodo Listar nao pode ser execultado");
          }
      ui->Lista->resizeColumnsToContents();
      ui->Lista->resizeRowsToContents();
}


