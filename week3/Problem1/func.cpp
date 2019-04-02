#include "func.h"
#include <vector>

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


