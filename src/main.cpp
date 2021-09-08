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
        cout << "\n./tp1 file.in -a algorithm -m mode\n\nAlgorithms:\n-bf: Brute Force\n-bt: Backtracking\n-bto: Backtracking\n-btf: Backtracking\n-dp: Dinamic Programing\n";
        return 0;
    }
    else if(argc == 3)
        algorithm = argv[2];
    if(algorithm != "bf" && algorithm != "bt" && algorithm != "bto" && algorithm != "btf" && algorithm != "pd"){
        cout << "Invalid parameters. Please, refer to ./tp1 -h or ./tp1 --help for more information.\n";
        return 0;
    }
    

    ifstream file;
    file.open(filename);

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

    cout << algorithm << ": "<<  ans;
    if(algorithm[1] == 't'){
        string modes[3] = {"Optimization", "Factibility", "Optimization & Factibility"};
        cout << "  (mode: " << modes[4-algorithm.size() - (algorithm.size() == 3 ? (algorithm[2] == 'o' ? 1 : 0) : 0)] << ")";
    }
    cout << endl;
    
    return 0;
}

// void tests(const info_t &info){
//     cout<< endl;  
//     cout<< "Result: "<<backtracking(info,2)<< endl;
//     cout<< endl;  
//     cout<< "|----------------- Brute Force:"<< endl;
//     for(int i = 0 ; i < 50 ; i++){
//         clock_t begin_time = clock();
//         bruteForce(info); 
//         clock_t end_time = clock();
//         float time = float(end_time - begin_time);
//     }
//     cout<< endl;  

//     cout<< "|----------------- Backtracking (Optimization):"<< endl;
//     for(int i = 0 ; i < 50 ; i++){
//         clock_t begin_time = clock();
//         backtracking(info,0); 
//         clock_t end_time = clock();
//         float time = float(end_time - begin_time);
//         cout<< time <<endl;
//     }
//     cout<< endl;      
//     cout<< "|----------------- Backtracking (Factibility):"<< endl;
//     for(int i = 0 ; i < 50 ; i++){
//         clock_t begin_time = clock();
//         backtracking(info,1);
//         clock_t end_time = clock();
//         float time = float(end_time - begin_time);
//         cout<< time <<endl;
//     }
//     cout<< endl;     
//     cout<< "|----------------- Backtracking (Optimization & Factibility):"<< endl;
//     for(int i = 0 ; i < 50 ; i++){
//         clock_t begin_time = clock();
//         backtracking(info,2);
//         clock_t end_time = clock();
//         float time = float(end_time - begin_time);
//         cout<< time <<endl;
//     }
//     cout<< endl;     

//     cout<< "|----------------- Dinamic Programing:"<< endl;
//     for(int i = 0 ; i < 50 ; i++){
//         clock_t begin_time = clock();
//         dinamicPrograming(info); 
//         clock_t end_time = clock();
//         float time = float(end_time - begin_time);
//         cout<< time <<endl;
//     }
//     cout<< endl;    
// }