#ifndef TELAPRINCIPAL_H
#define TELAPRINCIPAL_H

#include <QMainWindow>

namespace Ui {
class TelaPrincipal;
}

class TelaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit TelaPrincipal(QWidget *parent = 0);
    ~TelaPrincipal();

private slots:
    void on_BotaoCliente_clicked();

private:
    Ui::TelaPrincipal *ui;
};

#endif // TELAPRINCIPAL_H
