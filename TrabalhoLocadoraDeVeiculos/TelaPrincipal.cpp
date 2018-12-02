#include "TelaPrincipal.h"
#include "ui_TelaPrincipal.h"
#include"MenuCliente.h"

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

void TelaPrincipal::on_BotaoCliente_clicked()
{
     MenuCliente NovaJanela;
     NovaJanela.setModal(true);;
     NovaJanela.exec();

}
