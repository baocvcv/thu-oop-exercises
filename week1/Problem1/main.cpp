#include <iostream>
#include <string>
#include <cstdlib>
#include "func.h"

using namespace std;

int main(int argc, char** argv){
    vector<double> coef;
    double x;
    
    for(int i = 1; i < argc-1; i++){
        coef.push_back(atof(argv[i]));
    }
    x = atof(argv[argc-1]);

    for(int i = 0 ; i < coef.size(); i++){
        cout << coef[i] << ' ';
    }
    cout << x << endl;

    polynomial(coef, x);
    posynomial(coef, x);

    return 0;
}