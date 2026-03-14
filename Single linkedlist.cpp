#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* head = NULL;
void insert(int data)
{
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}
void insertAtEnd(int data) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = newNode;		
}
void insertAtPosition(int data, int position) {
	Node* newNode = new Node();
	newNode->data = data;
	newNode->next = NULL;
	if (position == 1)
	{
		newNode->next = head;
		head = newNode;
		return;
	}
	Node* temp = head;
	for (int i = 1; i < position - 1 && temp != NULL; i++)
	{
		temp = temp->next;
	}
	if (temp == NULL)
	{
		cout << "Position out of bounds" << endl;
		delete newNode;
		return;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}



void print()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insertAtEnd(40);
	insertAtPosition(25, 3);
	print();
}


