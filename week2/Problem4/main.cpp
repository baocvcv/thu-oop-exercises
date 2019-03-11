#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cstdlib>

#include "Efficient.h"
#include "BruteForce.h"

int main(){
    std::cout << "This program solves the 01 backpack problem.\n";
    std::cout << "The classic algorithm uses dynamic programming and the brute force one uses depth first search.\n";

    Efficient efficient;
    BruteForce brute_force;

    std::vector<int> T;
    std::vector<int> M; // value
    int totalT = 1000; // backpack size
    int N = 106; // total number of items

    // generate input 
    srand(time(0));
    for(int i = 0; i < N; i++){
        int t = rand() % int(totalT * 1.2);
        int m = rand() % (totalT / 2);
        T.push_back(t);
        M.push_back(m);
    }

    // run and record time
    double time_slow, time_fast;
    int res1, res2;
    auto start = std::chrono::high_resolution_clock::now();
    res1 = efficient.solve(T, M, totalT);
    auto end = std::chrono::high_resolution_clock::now();
    time_fast = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_fast *= 1e-9;

    start = std::chrono::high_resolution_clock::now();
    res2 = brute_force.solve(T, M, totalT);
    end = std::chrono::high_resolution_clock::now();
    time_slow = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    time_slow *= 1e-9;

    std::cout << "Here are the results:\n";
    std::cout << "The input contains " << N << " items.\n";
    std::cout << "The efficient algorithm uses " << time_fast << "s\n";
    std::cout << "The brute force algorithm uses " << time_slow << "s\n";
    if(res1 != res2){
        std::cout << "Caution: results differs.\n";
        std::cout << res1 << ' ' << res2 << std::endl;
    }

    return 0;
}