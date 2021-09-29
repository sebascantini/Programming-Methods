#include "backtracking.h"


//n: cantidad de tiendas totales

//mode:
//     0: optimalidad
//     1: factibilidad
//     2: factibilidad & optimalidad

int mejorBeneficio = 0;

int backtrackingAux(const info_t &info, const int mode, int potencial, int i = 0, int riesgo = 0, int beneficio = 0){
  //caso base
  if(i >= info.cantidad){                                     // O(1)
    beneficio = (riesgo <= info.limite) ? beneficio : 0;      // O(1)
    mejorBeneficio = max(beneficio, mejorBeneficio);          // O(1)
    return beneficio;                                         // O(1)
  }
  
  //poda por optimalidad
  if(mode % 2 == 0 && beneficio + potencial < mejorBeneficio)       // O(1)   modo 0 o 2 incluye optimalidad
      return -1;                                                    // O(1)
  
  potencial -= info.beneficios[i];                                  // O(1)
  
  //poda por factibilidad
  if(mode >= 1 && riesgo > info.limite)                  // O(1)              modo 1 y 2 incluye factibilidad
    return -1;                                           // O(1)

  //recursion
  int b1 = backtrackingAux(info, mode, potencial, i+1, riesgo, beneficio); //no nos quedamos con este nodo                                       // O(1)
  int b2 = backtrackingAux(info, mode, potencial - ((potencial != 0)?info.beneficios[i+1]:0), i+2, riesgo + info.contagios[i], beneficio + info.beneficios[i]); //si nos quedamos con este nodo   // O(1)
  return max(b1, b2);                                                                                                                              // O(1)
}

int backtracking(const info_t &info, const int mode){
  int potencial = 0;
  for(int j = 0; j < info.cantidad; ++j)                // O(n)
    potencial += info.beneficios[j];                    // O(1)
  return backtrackingAux(info, mode, potencial);
}

// O(2^n + n) = O(2^n) (el 2^n+n se debe a que ese n proviene de calcularSufijos, la cual corre solo una vez cuando i = 0 y cuando mode es par)