#pragma once

#include "Strategy.h"
#include <string>

class Customer {
    enum Type{
        KR,
        KMP
    };

    Strategy *m_strategy;

  public:
    Customer() : m_strategy(NULL){};

    void SetStrategy(int type);

    bool run(std::string& pattern, std::string& source);
};

inline void Customer::SetStrategy(int type){
    if(m_strategy != NULL){
        delete m_strategy;
    }
    if(type == KR){
        m_strategy = new KRStrategy();
    }else if(type == KMP){
        m_strategy = new KMPStrategy();
    }
}

inline bool Customer::run(std::string& pattern, std::string& source){
    return m_strategy->check(pattern, source);
}