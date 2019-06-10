#include "Strategy.h"
#include <string>
#include <iostream>

using namespace std;

bool KMPStrategy::check(string& pattern, string& source){
    bool res = false;
    lps = new int[pattern.length()];
    computeLPS(pattern);

    int i = 0;
    int j = 0;
    while(i < source.length()){
        if(pattern[j] == source[i]){
            i++, j++;
        }

        if(j == pattern.length()){
            cout << "    Pattern found at index " << i - j << endl;
            j = lps[j - 1];
            if(!res){
                res = true;
            }
        }else if(i < source.length() && pattern[j] != source[i]){
            if(j != 0){
                j = lps[j - 1];
            }else{
                i++;
            }
        }
    }
    delete[] lps;
    return res;
}

void KMPStrategy::computeLPS(string& pattern){
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < pattern.length()){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len != 0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}