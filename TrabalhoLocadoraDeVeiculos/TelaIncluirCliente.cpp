#include "TelaIncluirCliente.h"
#include "ui_TelaIncluirCliente.h"
#include"MenuCliente.h"
#include"Cliente.h"
#include"PersistenciaCliente.h"
#include"ValidadeDeDados.h"
#include"Data.h"
#include"CNH.h"
#include"Telefone.h"
#include"Endereco.h"
#include<QMessageBox>
TelaIncluirCliente::TelaIncluirCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaIncluirCliente)
{
    ui->setupUi(this);
    //COMBOBOX DIA 1 A 30
    ui->comboBox_Dia->addItem("");
    for(int i = 1;i<=31;i++){
        ui->comboBox_Dia->addItem(QString::number(i));
    }
     //COMBOBOX Mês 1 ao 12
     ui->comboBox_Mes->addItem("");
     for(int i = 1;i<=12;i++){
         ui->comboBox_Mes->addItem(QString::number(i));
     }
     //COMBOBOX DIA 1940 A 2050
     ui->comboBox_Ano->addItem("");
     for(int i = 2010;i<=2050;i++){
         ui->comboBox_Ano->addItem(QString::number(i));
     }
}

TelaIncluirCliente::~TelaIncluirCliente()
{
    delete ui;
}

void TelaIncluirCliente::on_pushButton_clicked()
{
         //Nome
         QString Nome = ui->lineEdit_Nome->text();
         //Email
         QString Email = ui->lineEdit_Email->text();
         //CPF
         QString CPF = ui->lineEdit_CPF->text();
         //Endereço
         QString Logradouro = ui->lineEdit_Logradouro->text();
         int NumeroEndereco = ui->lineEdit_Numero->text().toInt();
         int CEP = ui->lineEdit_CEP->text().toInt();
         //Telefone
         int DDI = ui->lineEdit_DDI->text().toInt();
         int DDD = ui->lineEdit_DDD->text().toInt();
         int NumeroFone = ui->lineEdit_NumeroFone->text().toInt();
         //Carteira De Habilitação
         QString NumeroCNH = ui->lineEdit_NumeroCNH->text();
         QString Categoria = ui->comboBox_Categoria->currentText();
         int ValidadeDia = ui->comboBox_Dia->currentText().toInt();
         int ValidadeMes = ui->comboBox_Mes->currentText().toInt();
         int ValidadeAno = ui->comboBox_Ano->currentText().toInt();

         int Erro=0;
         //Verificando Campos Vazios que Utilizam QString Obrigatorios
         if(Nome==""||CPF==""||Email==""|| NumeroCNH==""){
             QMessageBox::information(this, "Erro No Sistema","Campo Obrigatorio Vazio");
             Erro++;
         }
         //Verificando Campo Vazio Telefone
         else if((DDI<=0)||(DDD<=0)||(NumeroFone<=0)){
             QMessageBox::information(this, "Erro No Sistema","Campo Obrigatorio Vazio");
             Erro++;
         }
         //Verificando os ComboBox Vazio
         else if(ValidadeDia<=0||ValidadeMes<=0||ValidadeAno<=0||Categoria==""){
             QMessageBox::information(this, "Erro No Sistema","Categoria ou Validade Invalida");
             Erro++;
         }
         int DadosValidos = 0;
         //Verifica o CPF e Email
         TrabalhoLocadora::ValidadeDeDados Verificador;
         //CPF
         if((Verificador.CPFValido(CPF)) == true){
                DadosValidos++;
         }
         else{
             QMessageBox::information(this, "Erro No Sistema","CPF Invalido");
         }
         //Email
         if(Verificador.EmailValido(Email)== true){
             DadosValidos++;
         }
         else{
          QMessageBox::information(this, "Erro No Sistema","Email Invalido");
         }
      if(DadosValidos==2 && Erro==0){
         //Incluindo Cliente na Planilha
         TrabalhoLocadora::Cliente ClienteNovo;
          //Nome
            ClienteNovo.setNome(Nome);
          //Email
            ClienteNovo.setEmail(Email);
          //CPF
            ClienteNovo.setCPF(CPF);
          //Telefone
              TrabalhoLocadora::Telefone *Fone;
                  Fone = new TrabalhoLocadora::Telefone(DDI,DDD,NumeroFone);
            ClienteNovo.setTelefone(Fone);
          //Endereço
               TrabalhoLocadora::Endereco *EnderecoCliente;
                  EnderecoCliente = new TrabalhoLocadora::Endereco(Logradouro,NumeroEndereco,CEP);
            ClienteNovo.setEndereco(EnderecoCliente);
          //Carteira de Habilitação
               TrabalhoLocadora::CNH * CNHDoCliente = new TrabalhoLocadora::CNH;
               CNHDoCliente->setCategoria(Categoria);
               CNHDoCliente->setNumeroCNH(NumeroCNH);
                    TrabalhoLocadora::Data *DataValidade = new TrabalhoLocadora::Data(ValidadeDia,ValidadeMes,ValidadeAno);
               CNHDoCliente->setData(DataValidade);
            ClienteNovo.setCarteira(CNHDoCliente);

            TrabalhoLocadora::PersistenciaCliente PlanilhaCliente("ClientesCadastrados.csv");
            PlanilhaCliente.Incluir(ClienteNovo);
            QMessageBox::information(this, "Informação Do Sistema","Cliente Foi Cadastrado Com Sucesso");
            //Limpando A Tela
            ui->lineEdit_Nome->clear();
            ui->lineEdit_CPF->clear();
            ui->lineEdit_Email->clear();
            ui->lineEdit_Logradouro->clear();
            ui->lineEdit_Numero->clear();
            ui->lineEdit_CEP->clear();
            ui->lineEdit_DDI->clear();
            ui->lineEdit_DDD->clear();
            ui->lineEdit_NumeroFone->clear();
            ui->lineEdit_NumeroCNH->clear();
            ui->comboBox_Ano->clear();
            ui->comboBox_Categoria->clear();
            ui->comboBox_Dia->clear();
            ui->comboBox_Mes->clear();}
}


void TelaIncluirCliente::on_BotaoVoltarMenuCliente_clicked()
{
    TelaIncluirCliente::close();
}
