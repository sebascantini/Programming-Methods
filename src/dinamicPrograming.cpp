#include "dinamicPrograming.h"

vector<vector<int>> memo;

int dinamicProgramingAux(const info_t &info, int i = 0, int riesgo = 0){
  //caso base
  if(riesgo > info.limite)        //O(1)
    return -1;                    //O(1)

  if(i >= info.cantidad)          //O(1)
    return 0;                     //O(1)

  if(memo[i][riesgo] != -1)
    return memo[i][riesgo];

  //recursion
  int b1 = dinamicProgramingAux(info, i+1, riesgo); //no nos quedamos con este nodo
  int b2 = dinamicProgramingAux(info, i+2, riesgo + info.contagios[i]); //si nos quedamos con este nodo

  int ans = max(b1, (b2 != -1) ? b2 + info.beneficios[i] : 0);
  
  memo[i][riesgo] = ans;
  
  return ans;                   // O(1)
}

int dinamicPrograming(const info_t &info){
  memo = vector<vector<int>>(info.cantidad, vector<int>(info.limite+1, -1));   // usamos max_contagio+1 para simplificar el uso de indices en la matriz    // O(n*m) 
  return dinamicProgramingAux(info);                                  // O(m*n) debido a que llamamos a los sumo n veces (0<=i<=n) a dinamicProgramming recursivamente, la cual es
}  






















// #include "dinamicPrograming.h"

// vector<vector<int>> memo;

// //n: cantidad de tiendas totales
// //m: maximo de contagios

// void dinamicProgramingAux(const info_t &info, int i){
// //caso base
//   if(i >= info.cantidad)                                                                            //O(1)
//       return;                                                                                       //O(1)

// //guardar en memo

// //IMPORTANTE: vamos a usar solo tres filas para la matriz, por lo que la asignacion de valores sera en la fila modulo 3

// //limpiamos fila actual
// int j = i % 3; // fila                                                                            // O(1)
// memo[j] = vector<int>(info.limite+1, 0);                                                          // O(m)

// //primero guardamos elemento actual
// memo[j][info.contagios[i]] = info.beneficios[i];                                                  // O(1)

// //luego calculamos combinaciones con fila j-2
// int k = (j+1) % 3; // fila j-2 para combinaciones // (seria j-2%3)                                // O(1)
// for(int l = 1; l <= info.limite-info.contagios[i]; ++l)                                           // O(m) 
//   memo[j][l+info.contagios[i]] = memo[k][l] + info.beneficios[i];                                 // O(1)

// //shifteo de la fila j-1 hacia j, quedandonos solo con los elementos mas grandes de la columna
// k = (j+2) % 3;                                    // (seria j-1%3)                                // O(1)
// for(int l = 1; l <= info.limite; ++l)                                                             // O(m)
//   memo[j][l] = max(memo[j][l], memo[k][l]);                                                       // O(1)

// //recursion
//   dinamicProgramingAux(info , i+1); //no nos quedamos con este nodo                                 // O(3m+6) = O(m) 
// }                                                                                                   // TOTAL: O(n*m)

// int dinamicPrograming(const info_t &info){
//   memo = vector<vector<int>>(3, vector<int>(info.limite+1, 0));                                 // usamos max_contagio+1 para simplificar el uso de indices en la matriz             // O(3*m) = O(m)    
//   dinamicProgramingAux(info, 0);                                                                // O(m*n) debido a que llamamos a los sumo n veces (0<=i<=n) a dinamicProgramming recursivamente, la cual es   // O(m)
//   return *max_element(memo[(info.cantidad-1)%3].begin(), memo[(info.cantidad-1)%3].end());      // calcular indice de memo para devolver max de esa fila // O(m)
// }                                                                                               // TOTAL: O(m*n)