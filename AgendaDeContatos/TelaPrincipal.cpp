#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include"TelaListar.h"
#include<cctype>
#include<fstream>
#include<string>
#include<stack>
#include"Contato.h"
#include<vector>
#include<QMessageBox>
#include"TelaIncluir.h"
#include"TelaExcluir.h"
#include"TelaAlterar.h"
#include"TelaBusca.h"

TelaPrincipal::TelaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaPrincipal)
{
    ui->setupUi(this);
}

TelaPrincipal::~TelaPrincipal()
{
    delete ui;
}
void TelaPrincipal::on_listar_clicked()
{
    TelaListar NovaJanela;
    NovaJanela.setModal(true);
    NovaJanela.exec();

}

void TelaPrincipal::on_Incluir_clicked()
{
    TelaIncluir NovaJanela;
    NovaJanela.setModal(true);
    NovaJanela.exec();
}
void TelaPrincipal::on_pushButton_clicked()
{
    TelaExcluir NovaJanela;
    NovaJanela.setModal(true);
    NovaJanela.exec();
}

void TelaPrincipal::on_pushButton_2_clicked()
{
    TelaAlterar NovaJanela;
    NovaJanela.setModal(true);
    NovaJanela.exec();
}

void TelaPrincipal::on_pushButton_3_clicked()
{
    TelaBusca NovaJanela;
    NovaJanela.setModal(true);
    NovaJanela.exec();
}

void TelaPrincipal::on_pushButton_sairTela_clicked()
{
    TelaPrincipal::close();
}
