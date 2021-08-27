#include "headers.h"
#include "backtracking.h"
#include "bruteForce.h"
#include "dinamicPrograming.h"

int main(int argc, char** argv){
    
    info_t info;

    info.beneficios = {25, 50, 10, 20, 15};
    info.contagios = {10, 10, 20, 30, 20};
    info.limite = 45;
    info.cantidad = 5;
    
    cout << bruteForce(info) << endl;
    return 0;
}