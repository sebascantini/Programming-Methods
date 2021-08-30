#include "headers.h"
#include "bruteForce.h"
#include "backtracking.h"
#include "dinamicPrograming.h"

int main(int argc, char** argv){
    
    info_t info;

    info.beneficios.push_back(25);
    info.beneficios.push_back(50);
    info.beneficios.push_back(10);
    info.beneficios.push_back(20);
    info.beneficios.push_back(15);
    //[25 50 10 20 15]
    //[10 10 20 30 20]
    info.contagios.push_back(10);
    info.contagios.push_back(10);
    info.contagios.push_back(20);
    info.contagios.push_back(30);
    info.contagios.push_back(20);
    //[25 50 10 20 15]
    //[10 10 20 30 20]
    
    info.cantidad = 5;

    cout << bruteForce(info) << endl;
    return 0;
}