#include "Prim.h"
#include "Node.h"
#include "Edge.h"
#include "WeightedGraph.h"

#include <vector>
#include <iostream>
#include <queue>

Prim::Prim(WeightedGraph G){
    bool* marked;
    marked = new bool[G.get_V()];

    auto cmp = [](Edge e, Edge f){
        return e.get_weight() > f.get_weight();
    };
    //std::priority_queue<Edge, std::vector<Edge>, decltype(Edge::compare)> pq(Edge::compare);
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);

    int s = 0;
    marked[s] = true;
    for(Edge e: G.adj(s)){
        pq.push(e);
    }

    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();
        
        int v = e.get_v();
        int w = e.get_w();
        if(!marked[v] || !marked[w]){
            mst.push_back(e);
        }
        if(!marked[v]){
            for(Edge f: G.adj(v)){
                pq.push(f);
            }
            marked[v] = true;
        }
        if(!marked[w]){
            for(Edge f: G.adj(w)){
                pq.push(f);
            }
            marked[w] = true;
        }
    }
}

void Prim::print_mst(){
    std::cout << "===== Edges of MST ======" << std::endl;
    std::cout << " v   w   weight" << std::endl;
    for(Edge e: mst){
        std::cout << e.get_v() << ' ';
        std::cout << e.get_w() << ' ';
        std::cout << e.get_weight() << std::endl;
    }
    std::cout << "===============" << std::endl;
}