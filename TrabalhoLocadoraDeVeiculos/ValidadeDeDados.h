#ifndef VALIDADEDEDADOS_H
#define VALIDADEDEDADOS_H
#include<QString>

namespace TrabalhoLocadora{
class ValidadeDeDados
{
public:
    ValidadeDeDados();
    bool CPFValido(QString CPF);
    bool EmailValido (QString Email);

};
}
#endif // VALIDADEDEDADOS_H
