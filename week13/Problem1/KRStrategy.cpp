#include "Strategy.h"
#include <string>
#include <iostream>

using namespace std;

const int d = 256; // number of characters
const int q = 6700417; // a large prime num

bool KRStrategy::check(string& pattern, string& source){
    bool res = false;
    int h = 1; // a useful value
    for (int i = 0; i < pattern.length(); i++){
        h = (h * d) % q;
    }

    int h_pattern = 0;
    int h_source = 0;

    // calculate hash of pattern and source
    for (int i = 0; i < pattern.length(); i++){
        h_pattern = (h_pattern * d + pattern[i]) % q;
        h_source = (h_source * d + source[i]) % q;
    }

    for (int i = 0; i <= source.length() - pattern.length(); i++){
        // check has value
        if(h_pattern == h_source){
            // check one by one
            bool flag = true;
            for (int j = 0; j < pattern.length(); j++){
                if(pattern[j] != source[i+j]){
                    flag = false;
                    break;
                }
            }
            // if same
            if(flag){
                cout << "    Pattern found at index " << i << endl;
                if(!res){
                    res = true;
                }
            }
        }

        if(i < source.length() - pattern.length()){
            h_source = (d * (h_source - source[i] * h) + source[i + pattern.length()]) % q;
            if(h_source < 0){
                h_source += q;
            }
        }
    }
    return res;
}