#include <vector>
#include <iostream>
#include <cmath>
#include "func.h"

void polynomial(std::vector<double>& coef, double x){
    if(coef.size() <= 0){
        return;
    }

    double res = coef[0];
    for(unsigned int i = 1; i < coef.size(); i++){
        res += coef[i] * pow(x, i);
    }

    std::cout << "Polynomial: " << res << std::endl;
}