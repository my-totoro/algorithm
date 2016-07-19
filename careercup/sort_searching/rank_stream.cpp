/*
10.10 Rank from Stream: Imagine you are reading in a stream of integers. Periodically, you wish
to be able to look up the rank of a number x (the number of values less than or equal to x).
Implement the data structures and algorithms to support these operations. That is, implement
the method track(int x), which is called when each number is generated, and the method
getRankOfNumber(int x), which returns the number of values less than or equal to x (not
including x itself).
EXAMPLE
Stream(in order of appearance):5, 1, 4, 4, 5, 9, 7, 13, 3
getRankOfNumber(l) 0
getRankOfNumber(3) 1
getRankOfNumber(4) 3
*/

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<cmath>
#include<algorithm>
using std::vector;
using std::string;

class BadInput
{
public:
	BadInput(){ std::cout << "Bad Input" << std::endl; }
};

class RankNode
{
public:
	int data{ 0 };
	RankNode* left;
	RankNode* right;
	int left_size{ 0 };
	RankNode(int d) :data{ d }, left{ nullptr }, right{ nullptr }{}
	void insert(int d)
	{
		if (d <= data){
			if (left) left->insert(d);
			else {
				left = new RankNode(d);
				++left_size;
			}
		}
		else{
			if (right) right->insert(d);
			else {
				right = new RankNode(d);
			}
		}
	}
	//remember to track the null tree
	int get_rank(int d)
	{
		if (d == data) return left_size;
		else if (d < data) {
			return left == nullptr ? -1 : left->get_rank(d);
		}
		else {
			return right == nullptr ? left_size + 1 : right->get_rank(d) + left_size + 1;
		}
	}

	~RankNode(){
		if (left) delete left;
		if (right) delete right;
	}
};

RankNode* root;
void track(int d)
{
	if (root) root->insert(d);
	else{
		root = new RankNode(d);
	}
}

//binary search tree and track the size of the node's left tree

int getRank(int num)
{
	return root->get_rank(num);
}

int main()
{
	track(5);
	track(10);
	track(13);
	track(15);
	track(20);
	
	std::cout << getRank(24) << std::endl;
	return 0;
}