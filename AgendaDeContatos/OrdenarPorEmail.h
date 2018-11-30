#ifndef ORDENARPOREMAIL_H
#define ORDENARPOREMAIL_H
#include"OrdenadorTemplateMethod.h"
namespace TP2{
class OrdenarPorEmail :public OrdenadorTemplateMethod
{
public:
    bool ePrimeiro(Contato X, Contato Y) ;
};
}
#endif // ORDENARPOREMAIL_H
