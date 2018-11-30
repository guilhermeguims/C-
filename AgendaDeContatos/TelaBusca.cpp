#include "TelaBusca.h"
#include "ui_TelaBusca.h"
#include<list>
#include"Agenda.h"
#include"Contato.h"
#include<QMessageBox>

TelaBusca::TelaBusca(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaBusca)
{
    ui->setupUi(this);
}

TelaBusca::~TelaBusca()
{
    delete ui;
}

void TelaBusca::on_pushButton_voltar_clicked()
{
     TelaBusca::close();
}

void TelaBusca::on_pushButton_clicked()
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
        QMessageBox::information(this, "Erro no Sistema","Metodo editar nao pode ser execultado");
    }
    //Ajustando a Lista de Acordo com o Tamanho do Contato
    ui->Lista->resizeColumnsToContents();
    ui->Lista->resizeRowsToContents();
        }
