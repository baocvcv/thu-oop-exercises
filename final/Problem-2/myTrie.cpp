#include "myTrie.h"
#include <iostream>

void MyTrie::getString(std::string &std, int &value){
    matches.push_back(Result(std, value));
}

void MyTrie::printMatches(){
    std::cout << "Results: " << std::endl;
    for (int i = 0; i < matches.size(); i++){
        std::cout << "String: " << matches[i].s << ' ';
        std::cout << "Value: " << matches[i].val << std::endl;
    }
    std::cout << std::endl;
    matches.clear();
}