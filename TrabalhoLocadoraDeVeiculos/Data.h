#ifndef DATA_H
#define DATA_H

namespace TrabalhoLocadora {
class Data
{
private:
     int Dia;
     int Mes;
     int Ano;
public:
    Data(int dia,int mes,int ano);
    void setDia(int dia);
    int  getDia()const;
    void setMes(int mes);
    int  getMes()const;
    void setAno(int ano);
    int  getAno()const;
};
}
#endif // DATA_H
