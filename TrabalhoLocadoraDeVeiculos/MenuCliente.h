#ifndef MENUCLIENTE_H
#define MENUCLIENTE_H

#include <QDialog>

namespace Ui {
class MenuCliente;
}

class MenuCliente : public QDialog
{
    Q_OBJECT

public:
    explicit MenuCliente(QWidget *parent = 0);
    ~MenuCliente();

private slots:
    void on_BotaoVoltar_clicked();

    void on_BotaoIncluir_clicked();

private:
    Ui::MenuCliente *ui;
};

#endif // MENUCLIENTE_H
