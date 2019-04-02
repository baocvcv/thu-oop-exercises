#include "func.h"
#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>

int main(){
    double t_slow, t_fast;

    std::vector<double> coef(10, 5.0);
    double x = 1.5;
    
    std::cout << "This program calculates the same polynomial 1e8 times using two methods.\n";
    std::ios_base::sync_with_stdio(false);

    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 10000; j++){
            polynomial_fast(coef, x);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    t_fast = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    t_fast *= 1e-9; // transform to seconds

    start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < 10000; j++){
            polynomial_slow(coef, x);
        }
    }
    end = std::chrono::high_resolution_clock::now();
    t_slow = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    t_slow *= 1e-9; // transform to seconds
    
    std::cout << "Time fast: " << t_fast << "s" << std::endl;
    std::cout << "Time slow: " << t_slow << "s" << std::endl;

    return 0;    
}
