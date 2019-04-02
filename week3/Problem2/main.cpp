#include "ReviewerAssigner.h"
#include <iostream>
#include <string>

int main(){
    ReviewerAssigner assigner;
    std::string output = "Output.txt";

    assigner.load();
    assigner.choose();
    assigner.output(output);
    std::cout << "The result has been saved in " << output << std::endl;

    return 0;
}
