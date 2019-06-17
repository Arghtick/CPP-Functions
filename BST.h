//create the node class
class Node {
public:
	int datum;	//create the variable to hold the data
	Node *left, *right, *parent;	//create node pointers variables to the left right and parent nodes
	Node(int);
};
//create the binary search tree class
class BST {
	Node *root;	//create a node pointer variable to the root
	void dest_helper(Node*);	//declare the destructure helper
public:
	BST();	//create a binary search tree function
	~BST();	//create the binary search tree distructor
	void insert(int);	//create the insert function
	int rem(int);	//create the remove function
	Node* search(int);	//create the searh function
};
