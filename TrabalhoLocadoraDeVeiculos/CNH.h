#ifndef CNH_H
#define CNH_H
#include<QString>
#include"Data.h"
namespace TrabalhoLocadora{
class CNH
{
private:
    QString Numero;
    QString Categoria;
    Data * DataDeValidade;
public:
    CNH();
    void setNumeroCNH(QString num);
    QString getNumeroCNH()const;
    void setCategoria(QString categoria);
    QString getCategoria()const;
    void setData(Data * Validade);
    Data* getData()const;
};
}
#endif // CNH_H
