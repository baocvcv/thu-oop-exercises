#pragma once

#include <cmath>
#include <iostream>

class Node{
    public:
    int x, y;

    Node(int _x, int _y): x(_x), y(_y) {};

    double dist_to(Node n){
        return sqrt(1.0 * ((x-n.x)*(x-n.x) + (y-n.y)*(y-n.y)));
    };

    void print(){
        std::cout << '(' << x << ", " << y << ')' << std::endl;
    }
};
