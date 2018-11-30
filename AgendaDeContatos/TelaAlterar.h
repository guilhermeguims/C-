#ifndef TELAALTERAR_H
#define TELAALTERAR_H

#include <QDialog>

namespace Ui {
class TelaAlterar;
}

class TelaAlterar : public QDialog
{
    Q_OBJECT
    
public:
    explicit TelaAlterar(QWidget *parent = 0);
    ~TelaAlterar();
    
private slots:

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_alterar_clicked();

private:
    Ui::TelaAlterar *ui;
};

#endif // TELAALTERAR_H
