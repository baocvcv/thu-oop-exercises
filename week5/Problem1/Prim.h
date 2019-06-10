#pragma once

#include "WeightedGraph.h"
#include "Node.h"
#include "Edge.h"

#include <vector>
#include <queue>

/**
 * @brief A Prim class. 
 * Calculate the MST of a graph using Prim algo.
 * 
 */
class Prim{
    /// Stores the edges of the MST
    std::vector<Edge> mst;

    public:
    /**
     * @brief Construct a new Prim object and calculate the MST
     * 
     * @param G The graph to be calculated
     */
    Prim(WeightedGraph G);

    /**
     * @brief Print the MST to command line.
     * 
     */
    void print_mst();       
};