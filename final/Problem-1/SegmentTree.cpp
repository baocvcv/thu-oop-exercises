#include "SegmentTree.h"
#include <iostream>

SegmentTree::SegmentTree(const vector<Node >& data) {
	BuildTree(data);
}

//returns id of intervals overlapping the point
void SegmentTree::search(const int& point){
    segIDs_.clear();
    const int& minValue = Tree_[TREE_ROOT].start_;
    const int& maxValue = Tree_[TREE_ROOT].end_;
    if (!(point < minValue || point >= maxValue)) {
        FindOverlappingIntervals(point, point, TREE_ROOT, segIDs_);
    }
}

void SegmentTree::search(const int& point, BaseFuncObj &callBackFunObjIds) const {
    const int& minValue = Tree_[TREE_ROOT].start_;
    const int& maxValue = Tree_[TREE_ROOT].end_;
    if (!(point < minValue || point >= maxValue)) {
        FindOverlappingIntervals(point, point, TREE_ROOT, callBackFunObjIds);
    }
}

int SegmentTree::count(const int& point){
    segIDs_.clear();
    const int& minValue = Tree_[TREE_ROOT].start_;
    const int& maxValue = Tree_[TREE_ROOT].end_;
    if (!(point < minValue || point >= maxValue)) {
        RecordOverlappingIntervals(point, point, TREE_ROOT, segIDs_);
    }
    return segIDs_.size();
}

void SegmentTree::BuildTree(const vector<Node >& data) {
    vector<int> borders;
    for (Node v : data) {
        borders.push_back(v.start_);
        borders.push_back(v.end_);
    }
    std::sort(borders.begin(), borders.end());
    const int maxValue = *borders.rbegin();
    vector<Node > leafNodes;
    for (int nodeIndex = 0; nodeIndex < (int)borders.size(); ++nodeIndex) {
        if (nodeIndex > 0 && borders[nodeIndex] == borders[nodeIndex-1]) {
            continue;
        }
        const int& start = borders[nodeIndex];
        if (leafNodes.size()) {
            leafNodes.rbegin()->end_ = start;
        }
        leafNodes.push_back(Node(start, start, -1));
    }
    int nodeNum = 1;
    int layerSize = 1;
    while (layerSize < leafNodes.size()) {
        nodeNum += layerSize;
        layerSize = layerSize << 1;
    }
    Tree_ = vector<Node >(nodeNum, Node(maxValue, maxValue, -1));
    Tree_.insert(Tree_.end(), leafNodes.begin(), leafNodes.end());
    for (int position = Tree_.size() - leafNodes.size() - 1; position >= TREE_ROOT; --position) {
        const int left_child = position << 1;
        const int right_child = (position << 1) + 1;
        if (left_child < Tree_.size()) {
            Tree_[position].start_ = Tree_[left_child].start_;
            Tree_[position].end_ = Tree_[left_child].end_;
        }
        if (right_child < Tree_.size())
            Tree_[position].end_ = Tree_[right_child].end_;
    }
    //populate the data
    for (int intervalIndex = 0; intervalIndex < data.size(); ++intervalIndex) {
        const int& start = data[intervalIndex].start_;
        const int& end = data[intervalIndex].end_;
        const int& id = data[intervalIndex].id_;
        insert(start, end, id, TREE_ROOT);
    }
}

void SegmentTree::FindOverlappingIntervals(const int& start, const int& end, const int currentRoot) const{
    if (!Tree_[currentRoot].ids_.empty()) {
        for (typename vector<int>::const_iterator valueIt = Tree_[currentRoot].ids_.begin();
                valueIt != Tree_[currentRoot].ids_.end(); ++valueIt) {
            std::cout << "overlapping seg id " << *valueIt << std::endl;
        }
    }
    const int leftChild = currentRoot << 1;
    if (leftChild < Tree_.size() && Tree_[leftChild].start_ <= end && Tree_[leftChild].end_ > start) {
        FindOverlappingIntervals(start, end, leftChild);
    }
    const int rightChild = (currentRoot << 1) + 1;
    if (rightChild < Tree_.size() && Tree_[rightChild].start_ <= end && Tree_[rightChild].end_ > start) {
        FindOverlappingIntervals(start, end, rightChild);
    }
}

void SegmentTree::FindOverlappingIntervals(const int& start, const int& end, const int currentRoot, BaseFuncObj &funObj) const{
    if (!Tree_[currentRoot].ids_.empty()) {
        for (typename vector<int>::const_iterator valueIt = Tree_[currentRoot].ids_.begin();
                valueIt != Tree_[currentRoot].ids_.end(); ++valueIt) {
            funObj(*valueIt); //TODO: problem
        }
    }
    const int leftChild = currentRoot << 1;
    if (leftChild < Tree_.size() && Tree_[leftChild].start_ <= end && Tree_[leftChild].end_ > start) {
        FindOverlappingIntervals(start, end, leftChild, funObj);
    }
    const int rightChild = (currentRoot << 1) + 1;
    if (rightChild < Tree_.size() && Tree_[rightChild].start_ <= end && Tree_[rightChild].end_ > start) {
        FindOverlappingIntervals(start, end, rightChild, funObj);
    }
}

void SegmentTree::FindOverlappingIntervals(const int& start, const int& end, const int currentRoot, vector<int>& IDs){
    if (!Tree_[currentRoot].ids_.empty()) {
        for (typename vector<int>::const_iterator valueIt = Tree_[currentRoot].ids_.begin();
                valueIt != Tree_[currentRoot].ids_.end(); ++valueIt) {
            std::cout << "overlapping seg id " << *valueIt << std::endl;
            IDs.push_back(*valueIt);
        }
    }
    const int leftChild = currentRoot << 1;
    if (leftChild < Tree_.size() && Tree_[leftChild].start_ <= end && Tree_[leftChild].end_ > start) {
        FindOverlappingIntervals(start, end, leftChild, IDs);
    }
    const int rightChild = (currentRoot << 1) + 1;
    if (rightChild < Tree_.size() && Tree_[rightChild].start_ <= end && Tree_[rightChild].end_ > start) {
        FindOverlappingIntervals(start, end, rightChild, IDs);
    }
}

void SegmentTree::RecordOverlappingIntervals(const int& start, const int& end, const int currentRoot, vector<int>& IDs){
    if (!Tree_[currentRoot].ids_.empty()) {
        for (typename vector<int>::const_iterator valueIt = Tree_[currentRoot].ids_.begin();
                valueIt != Tree_[currentRoot].ids_.end(); ++valueIt) {
            IDs.push_back(*valueIt);
        }
    }
    const int leftChild = currentRoot << 1;
    if (leftChild < Tree_.size() && Tree_[leftChild].start_ <= end && Tree_[leftChild].end_ > start) {
        RecordOverlappingIntervals(start, end, leftChild, IDs);
    }
    const int rightChild = (currentRoot << 1) + 1;
    if (rightChild < Tree_.size() && Tree_[rightChild].start_ <= end && Tree_[rightChild].end_ > start) {
        RecordOverlappingIntervals(start, end, rightChild, IDs);
    }
}

void SegmentTree::insert(const int& start, const int& end, const int& id, const int currentRoot) {
    if (start ==  Tree_.at(currentRoot).start_ && end == Tree_.at(currentRoot).end_) {
        Tree_.at(currentRoot).ids_.push_back(id);
        return;
    }
    const int leftChild = currentRoot << 1;
    const int rightChild = leftChild + 1;
    const int& leftChildEnd = Tree_.at(leftChild).end_;
    if (start < leftChildEnd) {
        insert(start, std::min(leftChildEnd, end), id, leftChild);
    }
    if (end > leftChildEnd) {
        insert(std::max(start, leftChildEnd), end, id, rightChild);
    }
}    

ostream &operator<<(ostream &output, const SegmentTree &tree){
    std::cout << "The overlapping seg ids are : ";
    for (int i = 0; i < tree.segIDs_.size(); i++){
        std::cout << tree.segIDs_[i] << ' ';
    }
    std::cout << std::endl;

    return output;
}


ostream &operator<<(ostream &output, const BaseFuncObj obj){
    std::cout << "The overlapping seg ids are : ";
    for (int i = 0; i < obj.counter.size(); i++){
        std::cout << obj.counter[i] << ' ';
    }
    std::cout << std::endl;

    return output;
}

ostream &operator<<(ostream &output, const CounterFuncObj &obj){
    std::cout << "The number of overlapping segs are " << obj.counter.size() << std::endl;

    return output;
}
