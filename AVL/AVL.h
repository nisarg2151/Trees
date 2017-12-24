#include <iostream>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

class BST {
public:

	/***** Node class *****/
	class BinNode {
	public:
		int data;
//		int height;
		BinNode * left;
		BinNode * right;

		BinNode() :
				left(0), right(0) {
		}

		BinNode(int item) :
				data(item), left(0), right(0) {
		}
	};
	/***** Function Members *****/
	BST();
	bool empty() const;
	bool search(const int & item) const;
	BinNode * insert(BinNode * root, int item);
	void display(BinNode * r, int level);
	void preOrder(BinNode *r);
	void postOrder(BinNode * r);
	void inOrder(BinNode * r);
	int nodeCount(BinNode * r);
	BinNode * deleteNode(BinNode * r, int item);
	BinNode * smallestNode(BinNode * root);
	int height(BinNode * root);
	int getDifference(BinNode *root);
	BinNode * balanceTree(BinNode * temp);
	BinNode * rr_rotation(BinNode *parent);
	BinNode * ll_rotation(BinNode *parent);
	BinNode * rl_rotation(BinNode *parent);
	BinNode * lr_rotation(BinNode *parent);
	BinNode * getParentNode(BinNode * root, int value);

	/***** Data Members *****/
	BinNode * myRoot;

};

#endif

