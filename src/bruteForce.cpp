#include "bruteForce.h"


int bruteForce(const info_t &info, int i, int riesgo, int beneficio){
  //caso base
    if(i >= info.cantidad){                                                                                                   // O(1)
        return beneficio;
    }
  //recursion
    int b1,b2;                                                                                                                // O(1)
    b1 = bruteForce(info , i+1, riesgo, beneficio); //no nos quedamos con este nodo                                           // O(1)
    b2 = bruteForce(info, i+2, riesgo + info.contagios[i], beneficio + info.beneficios[i]); //si nos quedamos con este nodo   // O(1)
    return max((riesgo <= info.limite) ? b1 : 0, (riesgo+info.contagios[i] <= info.limite) ? b2 : 0);                         // O(1)
    
}                                                                                                                             // TOTAL: O(2^n)




//------------------------------------- otro ejemplo de brute force mezclando iterativo con recursion


// int respuesta = 0; //esta es la variable que se va quedando con el mejor 

// //en la primer llamada se arranca con actual = -2, riesgo = 0 y beneficio = 0 
// int bruteForce(info_t &info, int riesgo , int beneficio , int actual){

//     if(riesgo <= info.limite) //chequeamos que la instancia actual no se pase del limite de contagios
//       //en el caso de que no se pase, nos fijamos si el beneficio que veniamos calculando es mejor al que tendriamos sumando el beneficio
//       respuesta = max(respuesta, beneficio);

//     for(int i = actual+2; i < info.cantidad; ++i){ //n veces i: selector de la tienda j
//       bruteForce(info, riesgo + info.contagios[i], beneficio + info.beneficios[i], i); //itera entre los distintos j
//       //si bien la funcion devuelve un int, en este caso solo hacmos uso de la llamada recursiva
//       //en cada iteracion bruteForce va modificando la variable global respuesta.
//     }
            
//     return respuesta;
// }
