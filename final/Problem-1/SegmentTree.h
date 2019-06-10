#ifndef SEGMENTTREE_H
#define SEGMENTTREE_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <iostream>

using std::ostream;
using std::vector;

struct Node {
    int start_, end_;
    int id_;
    vector<int> ids_;
    Node(const int& start, const int& end, const int& id): start_(start), end_(end), id_(id) {}
};

class BaseFuncObj {
public:
	virtual bool operator()(const int &id) { counter.push_back(id); }

	friend ostream &operator<<(ostream &output, const BaseFuncObj obj);

protected:
	vector<int> counter;
};

class CounterFuncObj: public BaseFuncObj {
public:
	friend ostream &operator<<(ostream &output, const CounterFuncObj &obj);
};

class PrintFuncObj: public BaseFuncObj {
public:
	PrintFuncObj(vector<Node> data): data_(data), BaseFuncObj() {}

	bool operator()(const int &id) {
		Node n(0, 0, 0);
		for (int i = 0; i < data_.size(); i++){
			if(id == data_[i].id_){
				n = data_[i];
				break;
			}
		}
		std::cout << "start_: " << n.start_ << ' ';
		std::cout << "end_: " << n.end_ << ' ';
		std::cout << "id_: " << n.id_ << ' ';
		std::cout << std::endl;
		counter.push_back(id);
	}

private:
	vector<Node> data_;
};

class SegmentTree {
public:
	SegmentTree(const vector<Node >& data);

	//returns id of intervals overlapping the point
	void search(const int& point);
	void search(const int &point, BaseFuncObj &callBackFunObjIds) const;

	int count(const int &point);


	friend ostream &operator<<(ostream &output, const SegmentTree &tree);

private:
	static const int TREE_ROOT = 1;
	vector<Node> Tree_;
	
	/* added members */
	vector<int> segIDs_;

	void BuildTree(const vector<Node >& data);
	void FindOverlappingIntervals(const int& start, const int& end, const int currentRoot) const;
	void FindOverlappingIntervals(const int& start, const int& end, const int currentRoot, BaseFuncObj &callBackFunObjIds) const;
	void FindOverlappingIntervals(const int& start, const int& end, const int currentRoot, vector<int>& IDs);
	void RecordOverlappingIntervals(const int& start, const int& end, const int currentRoot, vector<int>& IDs);
	void insert(const int& start, const int& end, const int& id, const int currentRoot);
};

template<class T>
struct TNode {
    T start_, end_;
    int id_;
    vector<int> ids_;
    TNode(const T& start, const T& end, const int& id): start_(start), end_(end), id_(id) {}
};

template<class T>
class TSegmentTree {
public:
	TSegmentTree(const vector<TNode<T> >& data){}

	//returns id of intervals overlapping the point
	void search(const T& point){
		segIDs_.clear();
		const int& minValue = Tree_[TREE_ROOT].start_;
		const int& maxValue = Tree_[TREE_ROOT].end_;
		if (!(point < minValue || point >= maxValue)) {
			FindOverlappingIntervals(point, point, TREE_ROOT, segIDs_);
		}
	}

	int count(const T&point){
		segIDs_.clear();
		const int& minValue = Tree_[TREE_ROOT].start_;
		const int& maxValue = Tree_[TREE_ROOT].end_;
		if (!(point < minValue || point >= maxValue)) {
			RecordOverlappingIntervals(point, point, TREE_ROOT, segIDs_);
		}
		return segIDs_.size();
	}

	friend ostream &operator<< (ostream &output, const TSegmentTree<T> &tree){
		std::cout << "The overlapping seg ids are : ";
		for (int i = 0; i < tree.segIDs_.size(); i++){
			std::cout << tree.segIDs_[i] << ' ';
		}
		std::cout << std::endl;

		return output;
	}

private:
	static const int TREE_ROOT = 1;
	vector<TNode<T>> Tree_;
	
	// added members 
	vector<int> segIDs_;

	void BuildTree(const vector<TNode<T>> &data){
		vector<int> borders;
		for (TNode<T> v : data) {
			borders.push_back(v.start_);
			borders.push_back(v.end_);
		}
		std::sort(borders.begin(), borders.end());
		const int maxValue = *borders.rbegin();
		vector<TNode<T> > leafNodes;
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
		Tree_ = vector<TNode<T> >(nodeNum, Node(maxValue, maxValue, -1));
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

	void FindOverlappingIntervals(const T& start, const T& end, const int currentRoot) const{
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

	void FindOverlappingIntervals(const T& start, const T& end, const int currentRoot, vector<int>& IDs){
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

	void RecordOverlappingIntervals(const T& start, const T& end, const int currentRoot, vector<int>& IDs){
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

	void insert(const T& start, const T& end, const int& id, const int currentRoot){
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
};

#endif
