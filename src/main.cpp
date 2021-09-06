#include "headers.h"
#include "bruteForce.h"
#include "backtracking.h"
#include "dinamicPrograming.h"

// void tests();

int main(int argc, char** argv){

    string firstFlag, secondFlag, algorithm, error = "Invalid parameters. Please, refer to ./tp1 -h or ./tp1 --help for more information.\n";;
    int mode = 2;
    switch(argc){
        case 2:
            firstFlag = argv[1];
            if(firstFlag == "-h" || firstFlag == "--help")
                cout << "\n./tp1 file.in -a algorithm -m mode\n\nAlgorithms:\n-bf: Brute Force\n-bt: Backtracking\n-dp: Dinamic Programing\n\nModes (Exclusive to bt):\n-0: Optimization\n-1: Factibility\n-2: Both\n\nExamples:\n./tp1 text.in -a dp\n./tp1 text.in -a bt\n./tp1 text.in -a bt -m 2\n\n";      
            else
                cout << error;
            return 0;

        case 4:
            firstFlag = argv[2];
            algorithm = argv[3];
            if(firstFlag != "-a" || (algorithm != "bf" && algorithm != "bt" && algorithm != "dp")){
                cout << error;
                return 0;
            }
            break;

        case 6:
            firstFlag = argv[2];
            algorithm = argv[3];
            secondFlag = argv[4];
            mode = atoi(argv[5]);
            if(firstFlag != "-a" || algorithm != "bt" || secondFlag != "-m" || mode < 0 || mode > 2){
                cout << error;
                return 0;
            }
            break;

        default:
            cout << error;
            return 0;
    }

    ifstream file;
    file.open(argv[1]);

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
        ans = backtracking(info, mode);
    else if(algorithm == "dp")
        ans = dinamicPrograming(info);

    cout << algorithm << ": "<<  ans;
    if(algorithm == "bt"){
        string modes[3] = {"Optimization", "Factibility", "Optimization & Factibility"};
        cout << "  (mode: " << modes[mode] << ")";
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