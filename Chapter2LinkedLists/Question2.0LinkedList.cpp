/*
Implement a class to define the singly linked list.
*/

#include<iostream>
#include<vector>
#include<cassert>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<unordered_set>

using namespace std;

struct Node {
	// member data
	int val;
	Node* next;
	// default constructor
	Node()
	{
		val = 0;
		next = nullptr;
	}
	// constructor
	Node(int value)
	{
		val = value;
		next = nullptr;
	}
	// constructor
	Node(int value, Node* ptr)
	{
		val = value;
		next = ptr;
	}
};

class LinkedList
{
public:
	// constructor
	LinkedList() { head = nullptr; };

	// append tail to the last node
	void appendNode(int value);

	// print the list
	void printList();

	// remove a node
	void removeNode(int value);

private:
	Node* head;
};

void LinkedList::printList()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		cout << cur->val << '\t';
		cur = cur->next;
	}
	cout << endl;
}

void LinkedList::appendNode(int value)
{
	// empty list
	if (head == nullptr)
	{
		head = new Node(value);
		return;
	}
	// append to the tail
	Node* cur = head;
	while (cur->next != nullptr)
		cur = cur->next;
	cur->next = new Node(value);
}

void LinkedList::removeNode(int value)
{
	if (head == nullptr)
		return;
	// remove head
	if (head->val == value)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return;
	}
	// find the removed node
	Node* cur = head;
	while (cur->next != nullptr && cur->next->val != value)
		cur = cur->next;
	// no such node exists
	if (cur->next == nullptr)
		return;
	Node* temp = cur->next;
	cur->next = temp->next;
	delete temp;
}


int main()
{
	// Test node implementation
	Node* ptr0 = new Node(0);
	Node* ptr1 = new Node(1);
	Node* ptr2 = new Node(2);
	Node* ptr3 = new Node(3);
	Node* ptr4 = new Node(4);
	ptr0->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = ptr3;
	ptr3->next = ptr4;

	// print the list
	Node* cur = ptr0;
	for (int i = 0; i < 5; i++)
	{
		assert(cur->val == i);
		cur = cur->next;
	}
	cout << "Pass node implementation test\n";

	// Test LinkedList implementation
	LinkedList ls;
	ls.printList();
	ls.appendNode(0);
	ls.printList();
	ls.appendNode(1);
	ls.printList();
	ls.appendNode(2);
	ls.printList();
	ls.appendNode(3);
	ls.printList();
	ls.appendNode(4);
	ls.printList();
	
	ls.removeNode(10);
	ls.printList();
	ls.removeNode(3);
	ls.printList();
	ls.removeNode(0);
	ls.printList();
	ls.removeNode(4);
	ls.printList();
	ls.removeNode(1);
	ls.printList();
	ls.removeNode(2);
	ls.printList();
	ls.removeNode(3);
	ls.printList();
	cout << "Pass all tests\n";
}

