#pragma once

#include <string>
#include <iostream>

class Member {
    const std::string name;
    const int age;

  public:
    Member(const std::string& _name = "???", int _age = 0): name(_name), age(_age) {}
    void printInfo() const;
};