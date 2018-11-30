#ifndef TELAEXCLUIR_H
#define TELAEXCLUIR_H

#include <QDialog>

namespace Ui {
class TelaExcluir;
}

class TelaExcluir : public QDialog
{
    Q_OBJECT
    
public:
    explicit TelaExcluir(QWidget *parent = 0);
    ~TelaExcluir();
    
private slots:
    void on_pushButton_Excluir_clicked();

    void on_pushButton_clicked();

    void on_pushButton_Voltar_clicked();

private:
    Ui::TelaExcluir *ui;
};

#endif // TELAEXCLUIR_H
