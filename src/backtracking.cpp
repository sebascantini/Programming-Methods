#include "backtracking.h"


//n: cantidad de tiendas totales

vector<int> sufijosBeneficio;
// vector<int> sufijosRiesgo;

int mejorBeneficio = 0;

void calcularSufijos(const info_t &info){                     
    //copiamos los vectores de beneficios y contagios   
    sufijosBeneficio = info.beneficios;                 // O(1)
    // sufijosRiesgo = info.contagios;
    //vamos sumando hacia atras los valores
    for(int i = info.cantidad-2; i > 0; --i){           // O(n)
        sufijosBeneficio[i] = sufijosBeneficio[i+1];    // O(1) 
        // sufijosRiesgo[i] = sufijosRiesgo[i+1];
    } 
}                                                       // TOTAL: O(n)



//mode:
//     0: optimalidad
//     1: factibilidad
//     2: factibilidad & optimalidad

int backtracking(const info_t &info, const int mode, int i, int riesgo, int beneficio){
  //caso base

    if(i >= info.cantidad){                                     // O(1)
        //mejorBeneficio = max(beneficio, mejorBeneficio);
        return beneficio;                                       // O(1)
    }
    
  //poda por optimalidad
    if(mode % 2 == 0){                                          // O(1)
        if(i == 0)                                              // O(1)
            calcularSufijos(info);                              // O(n)
        if(beneficio + sufijosBeneficio[i] < mejorBeneficio)    // O(1)
            return -1;                                          // O(1)
    }

  //poda por factibilidad
    if(mode >= 1)                                               // O(1)
        if(riesgo > info.limite)                                // O(1)
            return -1;
  
  //recursion
    int b1,b2;                                                  // O(1)
    b1 = backtracking(info, mode, i+1, riesgo, beneficio); //no nos quedamos con este nodo  // O(n*n) 
    b2 = backtracking(info, mode, i+2, riesgo + info.contagios[i], beneficio + info.beneficios[i]); //si nos quedamos con este nodo // O(n*n)
    return max((riesgo <= info.limite) ? b1 : 0, (riesgo+info.contagios[i] <= info.limite) ? b2 : 0);    // O(1)
}                                                               // O(2^n + n) = O(2^n) (el 2^n+n se debe a que ese n proviene de calcularSufijos, la cual corre solo una vez cuando i = 0 y cuando mode es par)





      