#include "backtracking.h"


//n: cantidad de tiendas totales

//mode:
//     0: optimalidad
//     1: factibilidad
//     2: factibilidad & optimalidad

int mejorBeneficio = 0;

int backtracking(const info_t &info, const int mode, int i, int riesgo, int beneficio, int potencial){
  //caso base
  if(i >= info.cantidad){                                     // O(1)
    beneficio = (riesgo <= info.limite) ? beneficio : 0;      // O(1)
    mejorBeneficio = max(beneficio, mejorBeneficio);          // O(1)
    return beneficio;                                         // O(1)
  }

  if(i == 0)                                              // O(1)
    for(int j = 0; j < info.cantidad; ++j)                // O(n)
      potencial += info.beneficios[j];                    // O(1)
  
  //poda por optimalidad
  potencial -= info.beneficios[i];                     // O(1)
  if(mode % 2 == 0 && beneficio + potencial < mejorBeneficio)       // O(1)
      return -1;                                                    // O(1)
  

  //poda por factibilidad
  if(mode >= 1 && riesgo > info.limite)                  // O(1)
    return -1;                                           // O(1)

  //recursion
  int b1 = backtracking(info, mode, i+1, riesgo, beneficio, potencial); //no nos quedamos con este nodo                                            // O(1)
  int b2 = backtracking(info, mode, i+2, riesgo + info.contagios[i], beneficio + info.beneficios[i], potencial - (potencial != 0)?info.beneficios[i+1]:0); //si nos quedamos con este nodo   // O(1)
  return max(b1, b2);                                                                                                                              // O(1)
}

// O(2^n + n) = O(2^n) (el 2^n+n se debe a que ese n proviene de calcularSufijos, la cual corre solo una vez cuando i = 0 y cuando mode es par)