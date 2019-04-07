#include "Node.h"
#include "Edge.h"
#include "WeightedGraph.h"
#include "Prim.h"

#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>

int main(){
    const int N = 50;
    const int mod = 10001;

    // generate 50 distinct points
    std::vector<std::pair<int, int>> nums;
    srand(time(0));
    int x = rand() % mod;
    int y = rand() % mod;
    nums.push_back(std::make_pair(x, y));
    while(nums.size() < 50){
        bool flag = true;
        do{
            x = rand() % mod;
            y = rand() % mod;
            // check for repitition
            for(unsigned int i = 0; i < nums.size(); i++){
                if(nums[i].first == x && nums[i].second == y){
                    flag = false;
                    break;
                }
            }
        }while(!flag);
       nums.push_back(std::make_pair(x, y));
    }

    // print the points
    std::vector<Node> nodes;
    std::cout << "The points are: " << std::endl;
    for(unsigned int i = 0; i < nums.size(); i++){
        Node n(nums[i].first, nums[i].second);
        printf("%2d: ", i+1);
        n.print();
        nodes.push_back(n);
    }
    
    // contruct graph
    WeightedGraph G(N);
    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){
            double weight = nodes[i].dist_to(nodes[j]);
            Edge e(i, j, weight);
            G.insert(e);
        }
    }

    // calculate mst
    Prim prim(G);
    prim.print_mst();

    return 0;
}