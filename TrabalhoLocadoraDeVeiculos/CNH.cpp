#include "CNH.h"
namespace TrabalhoLocadora{
CNH::CNH()
{
    Numero="";
    Categoria="";
    DataDeValidade = new Data(0,0,0);

}
void CNH::setNumeroCNH(QString num){
      this->Numero=num;
}
QString CNH::getNumeroCNH()const{
      return Numero;
}
void CNH::setData(Data *Validade){
      this->DataDeValidade = Validade;
}
Data* CNH::getData()const{
     return DataDeValidade;
}
void CNH::setCategoria(QString categoria){
     this->Categoria=categoria;
}
QString CNH::getCategoria()const{
     return Categoria;
}


}
