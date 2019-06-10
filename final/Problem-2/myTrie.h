#pragma once

#include "BaseTrie.h"
#include <vector>
#include <string>

struct Result{
    std::string s;
    int val;

    Result(std::string &st, int &v) : s(st), val(v){}
};

class MyTrie: public BaseTrie {
public:
    MyTrie(): BaseTrie() {}

    void getString(std::string &str, int &value);
    void printMatches();

    ~MyTrie() {}

private:
    std::vector<Result> matches;
};