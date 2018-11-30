#include "OrdenarPorNome.h"
 namespace TP2{
 bool OrdenarPorNome::ePrimeiro(Contato X, Contato Y) {
      if(X.GetNome()<=Y.GetNome())
          return true;

      else
          return false;

 }
 }
