#include "OrdenarPorEmail.h"
namespace TP2{
bool OrdenarPorEmail::ePrimeiro(Contato X, Contato Y) {
     if(X.GetEmail()<=Y.GetEmail()){
         return true;
     }
     else{
         return false;
     }
}
}
