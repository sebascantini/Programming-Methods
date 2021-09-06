#ifndef _HEADERS_HH_
#define _HEADERS_HH_

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <chrono>

using namespace std;

struct info_t {
    int cantidad;
    int limite;
    vector<int> beneficios;
    vector<int> contagios;
};

#endif