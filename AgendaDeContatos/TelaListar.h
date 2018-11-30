#ifndef TELALISTAR_H
#define TELALISTAR_H

#include <QDialog>

namespace Ui {
class TelaListar;
}

class TelaListar : public QDialog
{
    Q_OBJECT
    
public:
    explicit TelaListar(QWidget *parent = 0);
    ~TelaListar();
    
private slots:
    void on_pushButton_Listar_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::TelaListar *ui;
};

#endif // TELALISTAR_H
