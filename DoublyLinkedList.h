class Node {
	int datum;
	Node *next;
	Node *prev;

public:
	Node(int);
	~Node();
	int get_datum();
	void set_datum(int);
	Node* get_next();
	void set_next(Node*);
	Node* get_prev();
	void set_prev(Node*);
};

class LinkedList {
	int size;
	Node *head;
	Node *tail;

public:
	LinkedList();
	//LinkedList(int);
	~LinkedList();
	void destr_helper(Node *node);
	int get(int);
	void set(int, int);
	void insert(int, int);
	//int rem(int);
	void print_list();
	void print_reverse_List();
};