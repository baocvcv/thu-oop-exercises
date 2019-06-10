#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "SegmentTree.h"

int main() {
	// create the tree by intervals with ids: [0, 3), [2, 5), [3, 7), [5, 8) ...
	vector<Node> data = { Node(0, 3, 1), Node(2, 5, 2), Node(3, 7, 3), Node(5, 8, 4), Node(2, 8, 5), Node(8, 9, 6), Node(8, 18, 7), Node(12, 18, 8)};
	SegmentTree tree(data);
	// search ids of intervals overlapping point 3
	// answer: 3, 5, 2
    tree.search(3);
    //for operator overloading
    std::cout << tree << std::endl;
    tree.search(3);
    std::cout << tree << std::endl;
    
    //implement a member function to count the number of overlapping intervals
    std::cout << tree.count(3) << std::endl;
    BaseFuncObj callBackFunObj;
    std::cout << "Call back base...\n";
    tree.search(3, callBackFunObj);
    std::cout << callBackFunObj << std::endl;

    CounterFuncObj counterFunObj;
    std::cout << "Call back counter...\n";
    tree.search(3, counterFunObj);
    std::cout << counterFunObj << std::endl;

    PrintFuncObj printerFunObj(data);
    std::cout << "Call back printer...\n";
    tree.search(3, printerFunObj);
    std::cout << printerFunObj << std::endl;


    vector<TNode<long>> data2 = { TNode<long>(0, 3, 1), TNode<long>(2, 5, 2), TNode<long>(3, 7, 3), TNode<long>(5, 8, 4), TNode<long>(2, 8, 5), TNode<long>(8, 9, 6), TNode<long>(8, 18, 7), TNode<long>(12, 18, 8)};
	TSegmentTree<long> tree2(data2);
    tree2.search(3);
    std::cout << tree2 << std::endl;
    tree2.search(3);
    std::cout << tree2 << std::endl;

    return 0;
}
