#ifndef TELAINCLUIRCLIENTE_H
#define TELAINCLUIRCLIENTE_H

#include <QDialog>

namespace Ui {
class TelaIncluirCliente;
}

class TelaIncluirCliente : public QDialog
{
    Q_OBJECT

public:
    explicit TelaIncluirCliente(QWidget *parent = 0);
    ~TelaIncluirCliente();

private slots:
    void on_pushButton_clicked();

    void on_BotaoVoltarMenuCliente_clicked();

private:
    Ui::TelaIncluirCliente *ui;
};

#endif // TELAINCLUIRCLIENTE_H
