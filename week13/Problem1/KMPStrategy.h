#pragma once

#include "Strategy.h"
#include <string>

class KMPStrategy: public Strategy {
    int* lps;
    void computeLPS(std::string& pattern);

  public:
    KMPStrategy() : Strategy(){}

    /* virtual */ bool check(std::string& pattern, std::string& source);
};