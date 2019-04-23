#pragma once

#include <fstream>
#include <vector>
#include <string>

class Matrix {
    std::vector<std::vector<int>> mat;

  public:
    Matrix() {}
    Matrix(const std::vector<std::vector<int>>& _mat): mat(_mat) {}
    Matrix(const std::string& filename);
    Matrix(const Matrix& b);

    void load(const std::string& filename);
    void display() const;
    void save(const std::string& filename) const;
    const Matrix multiply(const Matrix& b) const;
};