#ifndef TELAINCLUIR_H
#define TELAINCLUIR_H

#include <QDialog>

namespace Ui {
class TelaIncluir;
}

class TelaIncluir : public QDialog
{
    Q_OBJECT

public:
    explicit TelaIncluir(QWidget *parent = 0);
    ~TelaIncluir();

private slots:

    void on_pushButton_Incluir_clicked();

    void on_pushButton_Voltar_clicked();

private:
    Ui::TelaIncluir *ui;
};

#endif // TELAINCLUIR_H
