#include "backtracking.h"

//mode:
//     0: sin poda
//     1: por factibilidad
//     2: optimalidad
//     3: factibilidad & optimalidad


vector<int> sufijosBeneficio;
// vector<int> sufijosRiesgo;

int mejorBeneficio = 0;

void calcularSufijos(info_t &info){
    //copiamos los vectores de beneficios y contagios
    sufijosBeneficio = info.beneficios;
    // sufijosRiesgo = info.contagios;
    //vamos sumando hacia atras los valores
    for(int i = info.cantidad-2; i > 0; --i){
        sufijosBeneficio[i] = sufijosBeneficio[i+1];
        // sufijosRiesgo[i] = sufijosRiesgo[i+1];
    } 
}


    //5+495 0 5 +...
    //b[25 50 10 20 15] => [500 120 35 1 95 45 35 15]
    //r[10 10 20 30 20] => [90 80 70 50 20]



int backtracking(info_t &info, int mode, int i, int riesgo, int beneficio){
  //caso base
    if(i >= info.cantidad){
        //mejorBeneficio = max(beneficio, mejorBeneficio);
        return beneficio;
    }
  
  //poda por optimalidad
    if(mode > 1){
        if(i == 0)
            calcularSufijos(info);
        if(beneficio + sufijosBeneficio[i] < mejorBeneficio) 
            return -1;
    }

  //poda por factibilidad
    if(mode % 2 == 1)
        if(riesgo > info.limite)
            return -1;
      
  //recursion
    int b1,b2;
    b1 = backtracking(info, mode, i+1, riesgo, beneficio); //no nos quedamos con este nodo
    b2 = backtracking(info, mode, i+2, riesgo + info.contagios[i], beneficio + info.beneficios[i]); //si nos quedamos con este nodo
    return max(b1, b2);
}



