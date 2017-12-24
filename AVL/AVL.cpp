#include <iostream>

using namespace std;

#include "AVL.h"

/***** Definition of constructor *****/
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
		if (item < locptr->data) /*****descend left *****/
			locptr = locptr->left;
		else if (locptr->data < item) /***** descend right *****/
			locptr = locptr->right;
		else
			/***** item found *****/
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

			cout << "TREE --> ";
		else {
			for (i = 0; i < level; i++)
				cout << "\t";
		}
		cout << locptr->data << " H" << height(locptr) << "D"
				<< getDifference(locptr);
		BST::display(locptr->left, level + 1);
	}
}

/*
 * Insert Element into the tree
 */
BST::BinNode * BST::insert(BinNode * root, int item) {
	if(search(item)){
			cout << "\nItem Already in Tree"<<endl;
			return root;
	}
	if (root == NULL) {
		root = new BinNode();
		root->data = item;
		root->left = NULL;
		root->right = NULL;
		return root;
	} else if (item < root->data) {
		root->left = insert(root->left, item);
		root = balanceTree(root);
	} else if (item > root->data) {
		root->right = insert(root->right, item);
		root = balanceTree(root);
	}
	return root;
}


void BST::preOrder(BinNode * root) {
	BinNode * locptr = root; 				/***** search pointer *****/
	if (locptr != 0) {
		cout << locptr->data << " ";
		preOrder(locptr->left);
		preOrder(locptr->right);
	}
}

void BST::postOrder(BinNode * root) {
	BinNode * locptr = root; 				/***** search pointer *****/
	if (locptr != 0) {
		postOrder(locptr->left);
		postOrder(locptr->right);
		cout << locptr->data << " ";
	}
}

void BST::inOrder(BinNode * root) {
	BinNode * locptr = root; 				/***** search pointer *****/
	if (locptr != 0) {
		inOrder(locptr->left);
		cout << locptr->data << " ";
		inOrder(locptr->right);
	}
}

int BST::nodeCount(BinNode * root) {
	BinNode * locptr = root;			 /***** search pointer *****/
	if (locptr == 0)
		return 0;

	return 1 + nodeCount(locptr->left) + nodeCount(locptr->right);

}

int BST::height(BinNode * root) {
	int current_height = 0;
	if (root != NULL) {
		current_height = max(height(root->left), height(root->right)) + 1;
	}
	return current_height;
}

int BST::getDifference(BinNode *root) {
	int current_difference = height(root->left) - height(root->right);
	return current_difference;
}

BST::BinNode * BST::balanceTree(BinNode * temp) {
	int difference = getDifference(temp);
	cout << "Difference at node " << temp->data << "--> " << difference << endl;
   /* cout << temp->right->data << "right diff -> " << difference ;
    cout << temp->left->data << " left diff -> " << difference ;*/
	if (difference > 1) {

		if (getDifference(temp->left) > 0)
			return ll_rotation(temp);
		else
			return lr_rotation(temp);
	} else if (difference < -1) {
		if (getDifference(temp->right) > 0)
			return rl_rotation(temp);
		else
			return rr_rotation(temp);
	}
	return temp;
}

/*
 * Right- Right Rotation
 */
BST::BinNode * BST::rr_rotation(BinNode *parent) {
	cout << "\n<-------------Before Left Rotate -------------------->\n";
	display(myRoot, 1);
	cout << "\n\n\n<-------------After Left Rotate -------------------->\n";
	BinNode *temp = parent->right;
	BinNode *temp1 = temp->left;
	temp->left = parent;
	parent->right = temp1;
	return temp;
	/*BinNode * temp;
	 temp = parent;
	 parent = parent->right;
	 temp->right = parent->left;
	 parent->left = temp;
	 return parent;*/
}
/*
 * Left- Left Rotation
 */
BST::BinNode * BST::ll_rotation(BinNode *parent) {
	cout << "\n<---------------Before Right Rotate------------------>\n";
	display(myRoot, 1);
	cout << "\n\n\n<-------------After Right Rotate -------------------->\n";
	BinNode *temp = parent->left;
	BinNode *temp1 = temp->right;
	temp->right = parent;
	parent->left = temp1;
	return temp;

	/*BinNode *temp;
	 temp = parent->left;
	 parent->left = temp->right;
	 temp->right = parent;
	 return temp;*/

}

/*
 * Left - Right Rotation
 */
BST::BinNode * BST::lr_rotation(BinNode *parent) {
//	display(myRoot, 1);
	cout << "\n<-------------Applying Left Right Rotate -------------------->\n";
	parent->left = rr_rotation(parent->left);
	return ll_rotation(parent);
//	BinNode *temp;
//	temp = parent->left;
//	parent->left = rr_rotation(temp);
//	return ll_rotation(parent);
}

/*
 * Right- Left Rotation
 */
BST::BinNode * BST::rl_rotation(BinNode *parent) {
//	display(myRoot, 1);
	cout << "\n<-------------Applying Right Left Rotate -------------------->\n";
	parent->right = ll_rotation(parent->right);
	return rr_rotation(parent);
//	BinNode *temp;
//	temp = parent->right;
//	parent->right = ll_rotation(temp);
//	return rr_rotation(parent);
}

BST::BinNode * BST::getParentNode(BinNode * root, int item) {
	if (item == myRoot->data)
		return NULL;

	if (root->left == NULL && root->right == NULL)
		return NULL;

	if ((root->left != NULL && root->left->data == item)
			|| (root->right != NULL && root->right->data == item))
		return root;

	if (root->data > item)
		return getParentNode(root->left, item);

	if (root->data < item)
		return getParentNode(root->right, item);
}

BST::BinNode * BST::deleteNode(BinNode * root, int item) {
	if (myRoot == 0) {
	 cout << "Tree is empty";
	 return NULL;
	 }

	if (myRoot == root && myRoot->left == NULL && myRoot->right == NULL) {
		myRoot = NULL;
			cout << "Tree is empty";
			return NULL;
		}
	if (root == NULL) {
		cout << "Item not Found";
		return root;
	}

	if (item < root->data) {
		root->left = deleteNode(root->left, item);
	}

	else if (item > root->data) {
		root->right = deleteNode(root->right, item);
	}

	else {

		if (root->left == NULL && root->right == NULL) {
				cout << "\nCase 1"<<endl;
				root = NULL;
				delete root;

		}
		else if (root->left == NULL && root->right != NULL) {
			cout << "\nCase 2.1"<<endl;
			root = root->right;


		} else if (root->right == NULL && root->left != NULL) {
			cout << "\nCase 2.2"<<endl;
			root = root->left;

		} else if (root->right != NULL && root->left != NULL) {
			cout << "\nCase 3"<<endl;
			BinNode * temp = smallestNode(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}

	if (root == NULL)
		return root;

	root = balanceTree(root);
	return root;
}

BST::BinNode * BST::smallestNode(BinNode * root) {
	while (root->left != 0)
		root = root->left;
	return root;
}



/*BST::BinNode * BST::insert(BinNode * root,const int & item) {
 BinNode * locptr = root; **** search pointer ****
 BinNode * parent = 0; **** pointer to parent of current node ****
 //	BinNode * grandParent = 0;
 //	BinNode * ggrandParent = 0;
 bool found = false; **** indicates if item already in BST ****
 while (!found && locptr != 0) {
 parent = locptr;
 if (item < locptr->data) **** descend left ****
 locptr = locptr->left;
 else if (locptr->data < item) **** descend right ****
 locptr = locptr->right;
 else
 **** item found  ****
 found = true;
 }
 if (!found) { **** construct node containing item ****
 locptr = new BinNode(item);
 if (parent == 0) { **** empty tree ****
 if(myRoot == 0){
 myRoot = locptr;
 return myRoot;
 }
 else
 return locptr;
 } else if (item < parent->data) {
 cout << "left";
 parent->left = insert(parent->left, item);
 parent = balanceTree(parent);
 } else if (item >= parent->data) {
 cout << "right";
 parent->right = insert(parent->right, item);
 parent = balanceTree(parent);
 }
 display(myRoot, 1);
 cout << "\n\n";
 return parent;
 } else
 cout << "Item already in the tree\n";
 }*/


/***** Case 1:  No child *****/
/*		if (root->left == NULL && root->right == NULL && root == myRoot) {
 myRoot = 0;

 } else*/

/*		if (root->left == NULL && root->right == NULL) {
 cout << "\nCase 1";
 cout << "\nPARENT DATA " << parent->data << endl;

 if (parent->left != 0 && parent->left->data == root->data)
 parent->left = NULL;

 else if (parent->right != 0 && parent->right->data == root->data)
 parent->right = NULL;

 //return parent;
 root = balanceTree(parent);
 }
 ****Case 2: One child ****
 else if (root->left == NULL && root->right != NULL) {
 cout << "\nCase 2.1";
 root = root->right;
 BinNode * temp = root->right;
 root->data = temp->data;
 root->right = temp->right;
 root->left = temp->left;
 delete temp;
 root = balanceTree(root);
 //			temp = NULL;
 } else if (root->right == NULL && root->left != NULL) {
 cout << "\nCase 2.2";
 root = root->left;
 BinNode * temp = root->left;
 root->data = temp->data;
 root->left = temp->left;
 root->right = temp->right;
 delete temp;
 root = balanceTree(root);
 //			temp = NULL;
 }*/
/***** case 3 2 children *****/
/*else if (root->right != NULL && root->left != NULL) {
 cout << "\nCase 3";
 BinNode * temp = smallestNode(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);

 }
 // If the tree had only one node then return
 if (root == NULL)
 return root;


 }
 root = balanceTree(root);
 return root;
 }*/

//	 int current_height = max(height(root->left), height(root->right))+1;
//	 if(height(root->left) - height(root->right) == 2)
//	 {
//		 // right right case
//		 if(height(root->left->left) - height(root->left->right) == 1)
//			 return ll_rotation(root);
//		 // right left case
//		 else
//			 return lr_rotation(root);
//	 }
//	 // If right node is deleted, left case
//	 else if(height(root->right) - height(root->left) == 2)
//	 {
//		 // left left case
//		 if(height(root->right->right) - height(root->right->left) == 1)
//			 return rr_rotation(root);
//		 // left right case
//		 else
//			 return rl_rotation(root);
//	 }


