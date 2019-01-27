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
	Node * shit=head->next;
	int i=0;
	while (shit !=head)
	{
	shit=shit->next;
	i++;
	}
	tail->next=head;
	cout<< i+1<<endl;
	}
	
	
	void insertAt(int position,int value)
	{
	
	//count the number of things in the list
	Node* shit=head->next;
	int i=0;
	while (shit !=head)
	{
	shit=shit->next;
	i++;
	}
	if (position<i+1)
	{
	//create a pointer that will point to the first node
	Node* current=head;
	//move it to the required nodal position
	int j=1;
	while (j<position-1)
	{
	current=current->next;
	j++;
	}
	//now the pointer "current"points to the required nodal position
	//create a node at that position and enter data
	Node* temp=new Node;
	temp->data=value;
	temp->next=current->next;
	current->next=temp;
	}
	else
	{
	cout<<"Check the range of your list before you type."<<endl;
	}
	tail->next=head;	
	}

	
	void del()
	{
	
	//point to the last node in the list and save its address
	Node* temp=tail;
	//point to the first node in the list
	Node* current=head;
	//move to the last but one node in the list
	tail->next=head;
	while (current->next != head)
	{
	current = current->next;
	}
	//set the pointer to the last but one node to head
	current->next=head;
	//set the current( last but one node) to be the last node
	current=tail;
	//get rid of the ex-last node
	
	delete temp;
	}

	
	void delAt(int position)
	{
	
	//count the number of things in the list
	Node* shit=head->next;
	int i=0;
	while (shit !=head)
	{
	shit=shit->next;
	i++;
	}
	if (position<i+1)
	{	
	//point to the first node
	Node* current=head;
	//move to the required position
	int j=1;
	while (j<position-1)
	{
	current=current->next;
	j++;
	}
	//we have reached the predecessor of the node we want to delete
	//now, we store the address of the node we want to delete
	Node* temp=current->next;
	//temp->next will give us the address of the successor of the node we want out
	//equate the address of the successor to that of the node we want deleted
	current->next=temp->next;
	//delete the node you want to delete
	tail->next=head;
	delete temp;
	}
	else
	{
	cout<<"Check the total number of things in your list."<<endl;
	}	
	}
	

	void display()
	{
	
	//create a pointer to the first node
	Node* tem=head->next;
	cout<<head->data<<" -> ";
	while(tem!=head)
	{
	cout<< tem->data <<" -> ";
	tem=tem->next;
	}
	cout<<endl;
	tail->next=head;
	}
	
	

};

//driver function
int main()
{
	CList l1;
	l1.insert(8);
	l1.insert(3);
	l1.insert(34);
	l1.insert(56);
	l1.count();
	l1.display();
	l1.insertAt(3,67);
	l1.display();
	l1.del();
	l1.display();
	l1.delAt(3);
	l1.display();
	
	return 0;
}
