#pragma once

#include "Node.h"
#include "Edge.h"

#include <vector>

class WeightedGraph{
    std::vector<std::vector<Edge>> edges_list;
    int V;

    public:
    WeightedGraph(int _V);

    void insert(Edge e);
    const std::vector<Edge>& adj(int v);
    int get_V() { return V; }
};