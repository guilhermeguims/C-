#include "Data.h"
namespace TrabalhoLocadora{
Data::Data(int dia, int mes, int ano){
    this->Dia=dia;
    this->Mes=mes;
    this->Ano=ano;
}
void Data::setDia(int dia){
     this->Dia=dia;
}
int  Data::getDia()const{
     return Dia;
}
void Data::setMes(int mes){
     this->Mes=mes;
}
int  Data::getMes()const{
     return Mes;
}
void Data::setAno(int ano){
    this->Ano=ano;
}
int  Data::getAno()const{
     return Ano;
}
}
