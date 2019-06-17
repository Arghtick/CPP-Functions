#include "Queue.h"

Node::Node(int darum) {
	this->datum = datum;
	this->next = 0;
	this->prev = 0;
}

Queue::Queue() {
	this->head = 0;
	this->tail = 0;
}

Queue::~Queue() {
	this->destr_helper(this->head);
}

void Queue::destr_helper(Node *node) {
	if (node) {
		destr_helper(node->next);
		delete node;
	}
}

void Queue::push(int datum) {
	Node *newNode = new Node(datum);

	if (this->head) {
		this->head->prev = newNode;
	}
	newNode->next = this->head;
	this->head = newNode;
	if (!this->tail) {
		this->tail = newNode;
	}
}

int Queue::pop() {
	if (!this->head) {
		throw "Queue is empty";
	}

	int retVal = this->tail->datum;
	Node *oldTail = this->tail;
	this->tail = this->tail->prev;
	if (this->tail) {
		this->tail->next = 0;
	}
	else {
		this->head = 0;
	}
	delete oldTail;
	return retVal;
}

int Queue::peek() {
	if (!this->head) {
		throw "Queue is empty";
	}
	return this->tail->datum;
}

bool Queue::is_empty() {
	return !this->head;
}