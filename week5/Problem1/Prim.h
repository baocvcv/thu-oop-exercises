#pragma once

#include "WeightedGraph.h"
#include "Node.h"
#include "Edge.h"

#include <vector>
#include <queue>

class Prim{
    std::vector<Edge> mst; // stores the edges of the MST

    public:
    Prim(WeightedGraph G);
    void print_mst();       
    
};