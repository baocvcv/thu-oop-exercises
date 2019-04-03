#pragma once

#include <cmath>
#include <cstdio>

class Node{
    public:
    int x, y;

    Node(int _x, int _y): x(_x), y(_y) {};

    double dist_to(Node n){
        return sqrt(1.0 * ((x-n.x)*(x-n.x) + (y-n.y)*(y-n.y)));
    };

    void print(){
        printf("(%4d, %4d)\n", x, y);
    }
};
