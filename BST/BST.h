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
		BinNode * left;
		BinNode * right;

		// BinNode constructors
		// Default -- data part is default int value; both links are null.
		BinNode() :
				left(0), right(0) {
		}

		// Explicit Value -- data part contains item; both links are null.
		BinNode(int item) :
				data(item), left(0), right(0) {
		}

	};	    // end of class BinNode declaration

	/***** Function Members *****/
	BST();
	bool empty() const;
	bool search(const int & item) const;
	void insert(const int & item);
	void display(BinNode * r, int level);
	void preOrder(BinNode *r);
	void postOrder(BinNode * r);
	void inOrder(BinNode * r);
	int nodeCount(BinNode * r);
	BinNode * deleteNode(BinNode * r,int item);
	BinNode * smallestNode(BinNode * root);



	/***** Data Members *****/
	BinNode * myRoot;

};
// end of class declaration

#endif
