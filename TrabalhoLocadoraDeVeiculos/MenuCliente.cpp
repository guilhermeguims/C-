#include "MenuCliente.h"
#include "ui_MenuCliente.h"
#include"TelaIncluirCliente.h"

MenuCliente::MenuCliente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuCliente)
{
    ui->setupUi(this);
}

MenuCliente::~MenuCliente()
{
    delete ui;
}

void MenuCliente::on_BotaoVoltar_clicked()
{
     MenuCliente::close();
}

void MenuCliente::on_BotaoIncluir_clicked()
{
     TelaIncluirCliente NovaJanela;
     NovaJanela.setModal(true);
     NovaJanela.exec();
}
