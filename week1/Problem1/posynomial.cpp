#include <vector>
#include <iostream>
#include <cmath>
#include "func.h"

void posynomial(std::vector<double>& coef, double x){
    if(coef.size() <= 0){
        return;
    }
    if(abs(x) < 0.00001){
        std::cout << "Posynomial: error: input x equals to 0" << std::endl;
        return;
    }

    double res = coef[0];
    for(unsigned int i = 1; i < coef.size(); i++){
        res += coef[i] / pow(x, i);
    }

    std::cout << "Posynomial: " << res << std::endl;
}