#include "DoublyLinkedList.h"
#include <iostream>


Node::Node(int datum) {
	this->datum = datum;
	this->next = NULL;
	this->prev = NULL;
}


int Node::get_datum() {
	return this->datum;
}

void Node::set_datum(int datum) {
	this->datum = datum;
}

Node* Node::get_next() {
	return this->next;
}

void Node::set_next(Node *next) {
	this->next = next;
}

Node* Node::get_prev() {
	return this->prev;
}

void Node::set_prev(Node *prev) {
	this->prev = prev;
}

LinkedList::LinkedList() {
	this->size = 0;
	this->head = NULL;
	
}


int LinkedList::get(int index) {
	if (index >= this->size) {
		throw "Index out of bounds";
	}

	Node *temp = this->head;
	for (int i = 0; i < index; i++) {
		temp = temp->get_next();
	}

	return temp->get_datum();
}

void LinkedList::set(int index, int value) {
	if (index >= this->size) {
		throw "Index out of bounds";
	}

	Node *temp = this->head;
	for (int i = 0; i < index; i++) {
		temp = temp->get_next();
	}

	temp->set_datum(value);
}

void LinkedList::insert(int index, int value) {
	if (index > this->size) {
		throw "Index our of bounds";
	}

	Node *newNode = new Node(value);
	Node *temp = this->head;
	if (index == 0) {
		newNode->set_next(this->head);
		if (this->head) {
			this->head->set_prev(newNode);
		}
		this->head = newNode;
	}
	else {
		for (int i = 1; i < index; i++) {
			temp = temp->get_next();
		}
		newNode->set_next(temp->get_next());
		newNode->set_prev(temp);
		if (newNode->get_next()) {
			newNode->get_next()->set_prev(newNode);
		}
		temp->set_next(newNode);
	}
	this->size++;
	
}


void LinkedList::print_reverse_List() { //function to print list in reverse
	Node *last;//create the node to point to the tail end of the list
	last = this->head;	
	if (this->size > 0) {		//if the size is greater than 0
		while (this->head->get_next() != NULL) {		//while the next node isnt null
			last = this->head->get_next();	//set the last pointer to the next node
			this->head = this->head->get_next();	//update the head
		}
		
		for (Node *temp = last; temp; temp = temp->get_prev()) {	//for each node starting from the last going to each previous
			std::cout << "," << temp->get_datum();	//output the data in the node
		}
	}
	std::cout << "}" << std::endl;	//output a } representing the end of the code
}