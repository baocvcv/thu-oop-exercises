#include "WeightedGraph.h"
#include "Node.h"
#include "Edge.h"

#include <vector>

WeightedGraph::WeightedGraph(int _V){
    V = _V;
    for(int i = 0; i < V; i++){
        std::vector<Edge> v;
        edges_list.push_back(v);
    }
}

void WeightedGraph::insert(Edge e){
    int v = e.get_v();
    int w = e.get_w();
    edges_list[v].push_back(e);
    edges_list[w].push_back(e);
}

const std::vector<Edge>& WeightedGraph::adj(int v){
    return edges_list[v];
}

