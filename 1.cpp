#include <iostream>
using namespace std;
class Node {
public:
	//Pointer to previous node
	Node * prev;
	//Pointer to next node
	Node * next;
	int value;
	node() {
		prev = NULL;
		next = NULL;
	}
}
class DLList {
public:
	//Pointer to first node
	Node * head;
	//Pointer to last node
	Node * tail;
	DLList() {
		head = NULL;
		tail = NULL;
	}
	void insert(int data) {
		Node * temp = new Node;
		temp -> value = data;
		if (head == NULL) head = temp;
		else {
			tail -> next = temp;
			temp -> prev = tail;
		}
		tail = temp;
	}
	void insertAt(int pos, int data) {
		Node * i = head;
		int j = 0;
		while (i != NULL) {
			i = i -> next;
			j++;
		}
		cout << j << endl;
		Node * current = head;
		int k = 1;
		if (j >= pos) {	
			while (k < pos - 1) {
				k++;
				current = current -> next;
			}
			cout << current -> value << endl;
			Node * temp = new Node;
			temp -> value = data;
			temp -> next = current -> next;
		        temp -> prev = current;
			current -> next -> prev = temp;
			current -> next = temp;
		}
		else {
			cout << "Check the number of elements in the list." << endl;
		}
	}
	void delete() {
		Node * i = tail;
		Node * current = head;
		while(current -> next -> next != NULL) {
			current = current -> next;
		}
		cout << current -> value << endl;
		current -> next = NULL;
		current = tail;
		delete i;
	}
	void deleteAt(int pos)	{
		Node * l = head;
		int j = 0;
		while (l != NULL) {
			l = l -> next;
			j++;
		}
		if (j >= pos) {
			Node * current = head;
			int k = 1;
			while (k < pos - 1) {
				current = current -> next;
			}
			Node * temp = current -> next;
			current -> next = temp -> next;
			temp -> next -> prev = current;
			delete temp;
		}
		else {
			cout << "Check the number of entries in the list." << endl; 
	}
	void countItems() {
		Node * k = head;
		int k = 0;
		while (i != NULL) {
			i = i -> next;
			k++;
		}
		cout << "The nummber of entries in the list is : " << k << endl;
	}
	void display() {
		Node * temp = head;
		while(temp != NULL) {
			cout << temp -> value << " -> ";
			temp = temp -> next;
		}
		cout << endl;
	}
}
int main() {
	DDList l;
	l.insert(5);
	l.insert(4);
	l.insert(46);
	l.countItems();
	l.display();
	l.insertAt(7,420);
	l.countItems();
	l.display();
	l.delete();
	l.countItems();
	l.display();
	l.insert(289);
	l.insert(4800);
	l.insertAt(5,666);
	l.countItems();
	l.display();
	l.delete();
	l.countItems();
	l.display();
	l.deleteAt(2);
	l.countItems();
	l.display();
	return 0;
}
