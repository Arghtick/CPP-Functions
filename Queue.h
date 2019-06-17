class Node {
public:
	int datum;
	Node *next;
	Node *prev;
	Node(int);
};

class Queue {
	Node *head;
	Node *tail;
public:
	Queue();
	~Queue();
	void destr_helper(Node*);
	void push(int);
	int pop();
	int peek();
	bool is_empty();
};