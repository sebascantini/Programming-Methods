#include "bruteForce.h"

int bruteForce(const info_t &info, int i, bool valido, bool consecutivo, int riesgo, int beneficio){
  //caso base
  if(i >= info.cantidad)          //O(1)
    return beneficio;             //O(1)

  //recursion
  int b1 = bruteForce(info, i+1, valido, false, riesgo, beneficio); //no nos quedamos con este nodo                                                           // O(1)
  int b2 = bruteForce(info, i+1, valido && !consecutivo, true, riesgo + info.contagios[i], beneficio + info.beneficios[i]); //si nos quedamos con este nodo   // O(1)
  return max((valido && riesgo <= info.limite) ? b1 : 0, (valido && riesgo+info.contagios[i] <= info.limite) ? b2 : 0);                                       // O(1)
}