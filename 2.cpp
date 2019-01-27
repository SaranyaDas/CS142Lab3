#include <iostream>
using namespace std;
class Node {
	public:
	int value;
	Node * next;
	Node() {
    next = NULL;
	}
}
class CLList {
  public:
	Node * head;
  Node * tail;
	CLList() {
	head = NULL;
	tail = head;
	}
	void insert(int data) {
    Node * temp = new Node;
    temp -> value = data;
    if (head == NULL) {
	  head = temp;
	  }
	  else {
	  tail -> next = temp;
	  }
	  tail = temp;
	  tail -> next = head;
	  }
  void countItems() {
	Node * i = head -> next;
	int j = 0;
	while (i != head) {
		i = i -> next;
	        j++;
	        }
	tail -> next = head;
	cout << j + 1 << endl;
	}
  void insertAt(int pos,int data) {
	  Node * i = head -> next;
	  int j = 0;
	  while (i != head) {
		  i = i -> next;
	          j++;
	          }
	  if (pos < j + 1) {
		  Node * current = head;
		  int k = 1;
		  while (k < pos - 1) {
			  current = current -> next;
			  k++;
		  }
		  Node * temp = new Node;
		  temp -> value = data;
		  temp -> next = current -> next;
		  current -> next = temp;
	  }
	  else {
		  cout << "Check the range of your list." << endl;
	  }
	  tail -> next = head;	
  }
  void delele() {
	Node * temp = tail;
	Node * current = head;
	tail -> next = head;
	while (current -> next != head) {
		current = current -> next;
	}
	current -> next = head;
	current = tail;
	delete temp;
  }
  void deleteAt(int pos) {
	Node * i = head -> next;
	int j = 0;
	while (i != head) {
		i = i -> next;
		j++;
	}
	if (pos < j + 1) {	
		Node * current = head;
		int k = 1;
		while (k < pos - 1) {
		current = current -> next;
		k++;
		}
		Node * temp = current -> next;
		current -> next = temp -> next;
		tail -> next = head;
		delete temp;
	}
	else {
		cout << "Check the total number of items in your list." << endl;
	}
  }
  void display() {
	Node * temp = head -> next;
	cout<< head -> value << " -> ";
	while(temp != head) {
		cout << temp -> value << " -> ";
		temp = temp -> next;
	}
	cout << endl;
	tail -> next = head;
  }
}
int main() {
	CLList l1;
	l1.insert(4);
	l1.insert(6);
	l1.insert(48);
	l1.insert(69);
	l1.countItems();
	l1.display();
	l1.insertAt(6,54);
	l1.display();
	l1.delete();
	l1.display();
	l1.deleteAt(6);
	l1.display();
	return 0;
}
