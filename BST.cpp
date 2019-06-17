#include "BST.h"
//set up the node and the node pointers
Node::Node(int datum) {
	this->datum = datum;	//set the datum equal to the input value
	this->left = 0;	//set the left pointer to zero
	this->right = 0;//set the right pointer to zero
	this->parent = 0;	//set the parent pointer to zero
}
//set up the binary search tree function
BST::BST() {
	this->root = 0;	//set the root pointer to zero
}
//set up the destructor 
BST::~BST() {
	this->dest_helper(this->root);	//call destructor helper to destroy the root
}

//set up destructor helper
void BST::dest_helper(Node *node) {
	if (node) {	//if the node exists
		this->dest_helper(node->left);	//destroy the left pointer
		this->dest_helper(node->right);	//destroy the right pointer
		delete node;	//delete the node
	}
}

//set up the insert function
void BST::insert(int datum) {
	Node *newNode = new Node(datum);	//create a new node that holds a value 'datum'
	if (!this->root) {	//if the root node does not exist
		this->root = newNode;	//the root equals the new node
	}
	else {	//if ther is already a root
		Node *temp = this->root;	//set a temporary node pointer to the root

		while (true) {	//create a loop that will continue until broken
			if (datum < temp->datum) {	//if the datum is less then the temporary pointers datum
				if (temp->left) {	//if there is a left node
					temp = temp->left;	//temporary pointer equals the left node of temp
				}
				else {	//if there is not a left node	
					temp->left = newNode;	//set a left pointer to a new node
					newNode->parent = temp;	// set the parent of the new node to temp
					break;	//break from the loop
				}
			}
			if (datum > temp->datum) {	//if datum is greater than the data in the node above
				if (temp->right) {	//if a right node exists
					temp = temp->right;	//the temporary pointer equals the right node to temp
				}
				else {//if a right node does not exist
					temp->right = newNode;	//create a right pointer to a new node 
					newNode->parent = temp;	//set the new node parent to temp
					break;	//break from the loop
				}
			}
			//else {
			//	throw "Duplicates not allowed";
			//}
		}
	}
}

int BST::rem(int datum) {
	Node *temp = this->root;
	
	int remDat;
	//create a temp node pointer to the root
	while (temp && temp->datum != datum) {	//while temp exists and the data in temp is not equal to the inputed data
		if (datum < temp->datum) {	//if the datum is less than the temp value
			temp = temp->left;	//the temp pointer goes left
		}
		else {	//if the datum is greater than the temp value
			temp = temp->right;	//the temp pointer goes right
		}
	}
	//if there is a right child set the child pointer of the parent to the temps child
	if (temp->right) {
		if (temp->parent->right == temp) {
			temp->parent->right = temp->right;
		}
		if (temp->parent->left == temp) {
			temp->parent->left = temp->right;
		}
	}
	//if there is a left and not right child set the child pointer of the parent to the temps child
	if (temp->left && !temp->right) {
		if (temp->parent->left == temp) {
			temp->parent->left = temp->left;
		}
		if (temp->parent->right == temp) {
			temp->parent->right = temp->left;
		}
	}
	
	remDat = temp->datum;
	temp = 0;
	delete temp;
	return remDat;	//return the value of temp
}

//set up the function to search for a number/datum
Node* BST::search(int datum) {
	Node *temp = this->root;	//create a temp node pointer to the root
	while (temp && temp->datum != datum) {	//while temp exists and the data in temp is not equal to the inputed data
		if (datum < temp->datum) {	//if the datum is less than the temp value
			temp = temp->left;	//the temp pointer goes left
		}
		else {	//if the datum is greater than the temp value
			temp = temp->right;	//the temp pointer goes right
		}
	}
	return temp;	//return the value of temp
}
