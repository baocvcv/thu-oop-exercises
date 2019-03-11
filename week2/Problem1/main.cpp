#include <iostream>
#include <vector>
#include <chrono>
#include <time.h>

double power(double x, int n){
    double res = 1.0;
    for(int i = 0; i < n; i++){
        res *= x;
    }
    return res;
}

double polynomial_fast(std::vector<double>& coef, double x){
    if(coef.size() <= 0){
        return 0.0;
    }
    double res = 0.0;
    for(int i = coef.size()-1; i >= 0; i--){
        res = res * x + coef[i];
    }
    return res;
}

double polynomial_slow(std::vector<double>& coef, double x){
    if(coef.size() <= 0){
        return 0.0;
    }

    double res = coef[0];
    for(unsigned int i = 1; i < coef.size(); i++){
        res += coef[i] * power(x, i);
    }
    return res;
}

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
