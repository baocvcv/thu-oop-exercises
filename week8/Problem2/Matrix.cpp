#include "Matrix.h"

#include <iostream>

Matrix::Matrix(const std::string& filename) {
    std::ifstream fin(filename);
    if(!fin.is_open()){
        std::cout << "File does not exist!\n";
        return;
    }

    int m,n;
    fin >> m >> n;
    for(int i = 0; i < m; i++){
        std::vector<int> row;
        for(int j = 0; j < n; j++){
            int x;
            fin >> x;
            row.push_back(x);
        }
        mat.push_back(row);
    }
    fin.close();
}

Matrix::Matrix(const Matrix& b){
    mat = b.mat;
}

void Matrix::load(const std::string& filename){
    std::ifstream fin(filename);
    if(!fin.is_open()){
        std::cout << "File does not exist!\n";
        return;
    }

    mat.clear();
    int m,n;
    fin >> m >> n;
    for(int i = 0; i < m; i++){
        std::vector<int> row;
        for(int j = 0; j < n; j++){
            int x;
            fin >> x;
            row.push_back(x);
        }
        mat.push_back(row);
    }
    fin.close();
}

void Matrix::display() const {
    std::cout << "The matrix is :\n";
    for(unsigned int i = 0; i < mat.size(); i++){
        for(unsigned int j = 0; j < mat[0].size(); j++){
            std::cout << mat[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void Matrix::save(const std::string& filename) const {
    std::ofstream fout(filename);
    int M = mat.size();
    int N = mat[0].size();

    fout << M << ' ' << N << std::endl;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            fout << mat[i][j] << ' ';
        }
        fout << std::endl;
    }
    fout.close();
}

const Matrix Matrix::multiply(const Matrix& b) const {
    std::vector<std::vector<int>> _mat;

    if(mat[0].size() != b.mat.size()){
        std::cout << mat[0].size() << ' ' << b.mat.size() << std::endl;
        std::cout << "Error: matrix size does not match. Cannot multiply.\n";
    }
    display();

    for(unsigned int i = 0; i < mat.size(); i++){
        std::vector<int> row;
        for(unsigned int j = 0; j < b.mat[0].size(); j++){
            int x = 0;
            for(unsigned int k = 0; k < mat[0].size(); k++){
                x += mat[i][k] * b.mat[k][j];
            }
            row.push_back(x);
        }
        _mat.push_back(row);
    }

    return Matrix(_mat);
}