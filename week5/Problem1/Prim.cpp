#include "Prim.h"
#include "Node.h"
#include "Edge.h"
#include "WeightedGraph.h"

#include <vector>
#include <cstdlib>
#include <queue>

Prim::Prim(WeightedGraph G){
    bool* marked;
    marked = new bool[G.get_V()+1];
    for (int i = 1; i <= G.get_V(); i++){
        marked[i] = false;
    }

    auto cmp = [](Edge e, Edge f) {
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
}

void Prim::print_mst(){
    printf("===== Edges of MST ======\n");
    printf("id   v  w  weight\n");

    double sum = 0;
    int i = 1;
    for(Edge e: mst){
        printf("%2d: %2d %2d  %.2f\n", i, e.get_v(), e.get_w(), e.get_weight());
        i++;
        sum += e.get_weight();
    }
    printf("===============\n");
    printf("Total weight: %.2f\n", sum);
}