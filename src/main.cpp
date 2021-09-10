#include "headers.h"
#include "bruteForce.h"
#include "backtracking.h"
#include "dinamicPrograming.h"

// void tests();

int main(int argc, char** argv){
   
    string filename, algorithm;

    if(argc >= 2)
        filename = argv[1];
    if(filename == "-h" || filename == "--help"){
        cout << "\n./tp1 file.in -a algorithm -m mode\n\nAlgorithms:\n-bf: Brute Force\n-bt: Backtracking (Optimization & Factibility)\n-bto: Backtracking (Optimization)\n-btf: Backtracking (Factibility)\n-dp: Dinamic Programing\n\n";
        return 0;
    }
    else if(argc == 3)
        algorithm = argv[2];
    if(algorithm != "bf" && algorithm != "bt" && algorithm != "bto" && algorithm != "btf" && algorithm != "dp"){
        cout << "Invalid parameters. Please, refer to ./tp1 -h or ./tp1 --help for more information.\n";
        return 0;
    }
    

    ifstream file;
    file.open(filename);

    if(!file.is_open()){
        cout << "File could not be opened";
        return 0;
    }

    info_t info;
    
    file >> info.cantidad;
    file >> info.limite;

    info.beneficios = vector<int> (info.cantidad);
    info.contagios = vector<int> (info.cantidad);

    for(int i = 0; i < info.cantidad; ++i){
        file >> info.beneficios[i];
        file >> info.contagios[i];
    }

    int ans;

    if(algorithm == "bf")
        ans = bruteForce(info);
    else if(algorithm == "bt")
        ans = backtracking(info, 2);
    else if(algorithm == "bto")
        ans = backtracking(info, 0);
    else if(algorithm == "btf")
        ans = backtracking(info, 1);
    else if(algorithm == "dp")
        ans = dinamicPrograming(info);

    file.close();

    cout << algorithm << ": "<<  ans;
    if(algorithm[1] == 't'){
        string modes[3] = {"Optimization", "Factibility", "Optimization & Factibility"};
        cout << "  (mode: " << modes[4 - algorithm.size() - (algorithm.size() == 3 ? algorithm[2] == 'o' : 0)] << ")";
    }
    cout << endl;
    
    return 0;
}