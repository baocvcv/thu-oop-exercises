#include <vector>
#include "BruteForce.h"

int BruteForce::solve(std::vector<int> T, std::vector<int> M, int totalT){
    return dfs(T, M, totalT, 0);
}

int BruteForce::dfs(std::vector<int> T, std::vector<int> M, int totalT, int depth){
    // border conditions
    if(totalT <= 0){
        return 0;
    }
    if(depth >= M.size()){
        return 0;
    }
    
    // take the depth(th) item
    int v1;
    if( totalT >= T[depth]){
        v1 = M[depth] + dfs(T, M, totalT - T[depth], depth+1);
    }else{
        v1 = 0;
    } 
    // does not take the depth(th) item
    int v2 = dfs(T, M, totalT, depth+1);

    return (v1 > v2) ? v1: v2;
}