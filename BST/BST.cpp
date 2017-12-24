#include <iostream>
//#include <iomanip>

using namespace std;

#include "BST.h"

//--- Definition of constructor
BST::BST() :
		myRoot(0) {
}

bool BST::empty() const {
	return myRoot == 0;
}

bool BST::search(const int & item) const {
	BinNode * locptr = myRoot;
	bool found = false;
	while (!found && locptr != 0) {
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else
			// item found
			found = true;
	}
	return found;
}

void BST::display(BinNode * root, int level) {
	BinNode * locptr = root;
	int i;
	if (locptr != 0) {
		BST::display(locptr->right, level + 1);
		cout << endl;
		if (locptr == myRoot)
			cout << "Root->:  ";
		else {
			for (i = 0; i < level; i++)
				cout << "       ";
		}
		cout << locptr->data;
		BST::display(locptr->left, level + 1);
	}
}

void BST::insert(const int & item) {
	BinNode * locptr = myRoot;   // search pointer
	BinNode * parent = 0;        // pointer to parent of current node
	bool found = false;     // indicates if item already in BST
	while (!found && locptr != 0) {
		parent = locptr;
		if (item < locptr->data)       // descend left
			locptr = locptr->left;
		else if (locptr->data < item)  // descend right
			locptr = locptr->right;
		else
			// item found
			found = true;
	}
	if (!found) {                              // construct node containing item
		locptr = new BinNode(item);
		if (parent == 0)               // empty tree
			myRoot = locptr;
		else if (item < parent->data)  // insert to left of parent
			parent->left = locptr;
		else
			// insert to right of parent
			parent->right = locptr;
	} else
		cout << "Item already in the tree\n";
}

void BST::preOrder(BinNode * root) {
	BinNode * locptr = root;   // search pointer
	if (locptr != 0) {
		cout << locptr->data << " ";
		preOrder(locptr->left);
		preOrder(locptr->right);
	}
}

void BST::postOrder(BinNode * root) {
	BinNode * locptr = root;   // search pointer
	if (locptr != 0) {
		postOrder(locptr->left);
		postOrder(locptr->right);
		cout << locptr->data << " ";
	}
}

void BST::inOrder(BinNode * root) {
	BinNode * locptr = root;   // search pointer
	if (locptr != 0) {
		inOrder(locptr->left);
		cout << locptr->data << " ";
		inOrder(locptr->right);
	}
}

int BST::nodeCount(BinNode * root) {
	BinNode * locptr = root;   // search pointer
	if (locptr == 0)
		return 0;

	return 1 + nodeCount(locptr->left) + nodeCount(locptr->right);

}

BST::BinNode * BST::deleteNode(BinNode * root, int item) {

	if (BST::empty()) {
		cout << "Tree is empty";
		return NULL;
	}

	if (myRoot == root && myRoot->left == NULL && myRoot->right == NULL) {
		myRoot = NULL;
		cout << "Tree is empty now";
		return NULL;
	}

	if (root == 0)
		return NULL;   // search pointer

	else if (item < root->data)
		root->left = deleteNode(root->left, item);
	else if (item > root->data)
		root->right = deleteNode(root->right, item);
	else {
		if (root->left == NULL && root->right == NULL && root == myRoot) {
			myRoot = 0;

		} else if (root->left == NULL && root->right == NULL) {
			cout << "\nCase 1";
			delete root;
			root = 0;
		}

		else if (root->left == NULL) {
			cout << "\nCase 2.1";
			BinNode * temp = root->right;
			root->data = temp->data;
			root->right = temp->right;
			root->left = temp->left;
			delete temp;
			temp = NULL;
		} else if (root->right == NULL) {
			cout << "\nCase 2.2";
			BinNode * temp = root->left;
			root->data = temp->data;
			root->left = temp->left;
			root->right = temp->right;
			delete temp;
			temp = NULL;
		}

		else {
			cout << "\nCase 3";
			BinNode * temp = smallestNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

BST::BinNode * BST::smallestNode(BinNode * root) {
	while (root->left != 0)
		root = root->left;
	return root;
}

