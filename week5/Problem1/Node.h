#pragma once

#include <cmath>
#include <cstdio>

/**
 * @brief Simple Node class. A node in a graph
 * 
 */
class Node{
    public:
    /// x-coordinate
    int x;
    /// y-coordinate
    int y;

    /**
     * @brief Construct a new Node object
     * 
     * @param _x x-coordinate
     * @param _y y-coordinate
     */
    Node(int _x, int _y): x(_x), y(_y) {};

    /**
     * @brief Distance to another node
     * 
     * @param n 
     * @return double distance between
     */
    double dist_to(Node n){
        return sqrt(1.0 * ((x-n.x)*(x-n.x) + (y-n.y)*(y-n.y)));
    };

    /**
     * @brief Display the node in command line
     * 
     */
    void print(){
        printf("(%4d, %4d)\n", x, y);
    }
};
