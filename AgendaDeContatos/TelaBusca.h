#ifndef TELABUSCA_H
#define TELABUSCA_H

#include <QDialog>

namespace Ui {
class TelaBusca;
}

class TelaBusca : public QDialog
{
    Q_OBJECT
    
public:
    explicit TelaBusca(QWidget *parent = 0);
    ~TelaBusca();
    
private slots:
    void on_pushButton_voltar_clicked();

    void on_pushButton_clicked();

private:
    Ui::TelaBusca *ui;
};

#endif // TELABUSCA_H
