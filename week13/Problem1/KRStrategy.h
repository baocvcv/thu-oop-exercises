#pragma once

#include "Strategy.h"
#include <string>

class KRStrategy: public Strategy {
  public:
    KRStrategy() : Strategy(){}

    /* virtual */ bool check(std::string& pattern, std::string& source);
};
