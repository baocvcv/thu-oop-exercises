#pragma once

#include <string>
#include <vector>

class Strategy {

    int i;
  public:
    Strategy() : i(5) {}

    virtual bool check(std::string &pattern, std::string &source) = 0;
};

class KRStrategy: public Strategy {
  public:
    KRStrategy() : Strategy(){}

    /* virtual */ bool check(std::string& pattern, std::string& source);
};

class KMPStrategy: public Strategy {
    int* lps;
    void computeLPS(std::string& pattern);

  public:
    KMPStrategy() : Strategy(){}

    /* virtual */ bool check(std::string& pattern, std::string& source);
};