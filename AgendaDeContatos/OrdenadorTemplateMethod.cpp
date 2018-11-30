#include "OrdenadorTemplateMethod.h"
namespace TP2{
void OrdenadorTemplateMethod::ordenarContato(std::list<Contato> &ListaDeContatos){
      for(std::list<Contato>::iterator i = ListaDeContatos.begin();i!=ListaDeContatos.end();i++){
            for(std::list<Contato>::iterator j = i;j!=ListaDeContatos.end();j++){
                 if(!ePrimeiro(*i,*j)){
                     Contato *ContatoAui = new Contato;
                     *ContatoAui = *i;
                     *i=*j;
                     *j=*ContatoAui;
                 }

            }
      }
  }
}
