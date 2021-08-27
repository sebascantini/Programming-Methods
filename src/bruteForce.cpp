#include "bruteForce.h"

int respuesta = 0; //esta es la variable que se va quedando con el mejor 

//en la primer llamada se arranca con actual = -2, riesgo = 0 y beneficio = 0 (mirar .h)
int bruteForce(info_t &info, int riesgo , int beneficio , int actual){

    if(riesgo <= info.limite) //chequeamos que la instancia actual no se pase del limite de contagios
      //en el caso de que no se pase, nos fijamos si el beneficio que veniamos calculando es mejor al que tendriamos sumando el beneficio
      respuesta = max(respuesta, beneficio);

    for(int i = actual+2; i < info.cantidad; ++i){
      bruteForce(info, riesgo + info.contagios[i], beneficio + info.beneficios[i], i);
      //si bien la funcion devuelve un int, en este caso solo hacmos uso de la llamada recursiva
      //en cada iteracion bruteForce va modificando la variable global respuesta.
    }

    return respuesta;
}