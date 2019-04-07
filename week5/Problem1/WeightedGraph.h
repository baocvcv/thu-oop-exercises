#pragma once

#include "Node.h"
#include "Edge.h"

#include <vector>

class WeightedGraph{
    std::vector<std::vector<Edge>> edges_list;
    int V;

    public:
    WeightedGraph(int _V);

    int get_V() { return V; }
    void insert(Edge e);
    
    // return edges connected to vertex v
    const std::vector<Edge>& adj(int v);
};