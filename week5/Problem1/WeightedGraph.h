#pragma once

#include "Node.h"
#include "Edge.h"

#include <vector>

/**
 * @brief A weighted graph class.
 * 
 */
class WeightedGraph{
    /// List of edges
    std::vector<std::vector<Edge>> edges_list;

    /// Number of verteces
    int V;

    public:
    /**
     * @brief Construct a new Weighted Graph object
     * 
     * @param _V number of verteces
     */
    WeightedGraph(int _V);

    /**
     * @brief Get the number of verteces
     * 
     * @return int 
     */
    int get_V() { return V; }

    /**
     * @brief Insert an edge into the graph
     * 
     * @param e 
     */
    void insert(Edge e);
    
    /**
     * @brief Get edges connected to vertex v
     * 
     * @param v 
     * @return const std::vector<Edge>& list of edges adjacent to vertex v
     */
    const std::vector<Edge>& adj(int v);
};