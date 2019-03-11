#include <vector>
#include <iostream>
#include "Efficient.h"

int Efficient::solve(std::vector<int> T, std::vector<int> M, int totalT){
    int* p = new int[totalT+1];

    // initial condition
    // for(int i = 0; i <= totalT; i++){
    //     if(i < T[0]){
    //         p[i] = 0;
    //     }else{
    //         p[i] = M[0];
    //     }
    // }
    for(int i = 0; i <= totalT; i++){
        p[i] = 0;
    }

    // dp
    for(unsigned int j = 0; j < M.size(); j++){
        for(int i = totalT; i > 0; i--){
            int v = (i < T[j]) ? 0 : (p[i-T[j]] + M[j]);
            p[i] = (v > p[i]) ? v : p[i];
        }
    }

    int res = p[totalT];
    delete []p;
    return res;
}