#include "OrdenarPorCPF.h"
 namespace TP2{
 bool OrdenarPorCPF::ePrimeiro(Contato X, Contato Y) {
       if(X.GetCPF()<=Y.GetCPF()){
           return true;
       }
       else{
           return false;
       }

 }
 }
