/*----- treetester.cpp -----------------------------------------------------
 *  Program for testing AVL.
 *   ------------------------------------------------------------------------*/
#include <iostream>
using namespace std;

#include "AVL.h"

int main() {

	BST intBST;

	cout << "Constructing empty AVL\n";
	cout << "AVL " << (intBST.empty() ? "is" : "is not") << " empty\n";

	/* Testing insert */
	cout << "\nNow insert a bunch of integers into the AVL."
		"\nTry items not in the AVL and some that are in it:\n";
	int number;
	for (;;) {
		cout << "############################################################\n";
		cout << "Item to insert (-999 to stop): ";
		cin >> number;
		if (number == -999)
			break;
		intBST.myRoot = intBST.insert(intBST.myRoot,number);
		cout << "\n";
		intBST.display(intBST.myRoot, 1);
		cout << "\n\n";
		cout << "\n<----------------------------------------------------------->\n";
		cout << "In-Order --> ";

		intBST.inOrder(intBST.myRoot);
		cout << "\n" << "Node Count --> ";
		int count = intBST.nodeCount(intBST.myRoot);
		cout << count<< endl;
	}


	intBST.display(intBST.myRoot, 1);
	cout << "\n\n\n" << "Pre-Order --> ";
	intBST.preOrder(intBST.myRoot);
	cout << "\n" << "Post-Order --> ";
	intBST.postOrder(intBST.myRoot);
	cout << "\n" << "In-Order --> ";
	intBST.inOrder(intBST.myRoot);
	cout << "\n" << "Node Count --> ";
	int count = intBST.nodeCount(intBST.myRoot);
	cout << count<< endl;;

	for (;;) {
		cout << "############################################################\n";
		cout << "Item to delete (-999 to stop): ";
		cin >> number;
		if (number == -999) break;

		intBST.myRoot = intBST.deleteNode(intBST.myRoot,number) ;
//		cout << "<---------------------------------------------------------------->\n";
		intBST.display(intBST.myRoot,1);
		cout << "\n\n\n<---------------------------------------------------------------->\n";
		cout << "In-Order --> ";
		intBST.inOrder(intBST.myRoot);

		cout << "\n" << "Node Count --> ";
		int count = intBST.nodeCount(intBST.myRoot);
		cout << count << endl;

	}
	cout << "BST " << (intBST.empty() ? "is" : "is not") << " empty\n";

	/* Testing search() */
	cout << "\n\nNow testing the search() operation."
		"\nTry both items in the AVL and some not in it:\n";

	for (;;) {
		cout << "Item to find (-999 to stop): ";
		cin >> number;

		if (number == -999)
			break;
		cout << (intBST.search(number) ? "Found" : "Not found") << endl;
	}

}

