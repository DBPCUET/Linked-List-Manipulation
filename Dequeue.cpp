#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int data ;
	Node* link ;
	Node(int val)
	{
		data = val ;
		link = NULL ;
	}
};

Node* f = NULL ;
Node*r = NULL ;

void push_front(int data)
{
	Node* newnode = new Node(data) ;
	if (newnode == NULL)
	{
		cout << "Queue is FUll\n" ;
	}
	else
	{
		newnode -> link = NULL ;
		if (f == NULL)
		{
			f = r = newnode ;
		}
		else
		{
			newnode -> link = f ;
			f = newnode ;
		}
	}
}

void push_back(int data)
{
	Node* newnode = new Node(data) ;
	if (newnode == NULL)
	{
		cout << "Queue is FUll\n" ;
	}
	else
	{
		newnode -> link = NULL ;
		r -> link = newnode ;
		r = newnode ;
	}
}

int pop_front()
{
	int val = -1;
	if (f == NULL)
	{
		cout << "Queue is Empty\n";
	}
	else
	{
		Node* ptr = f;
		f = f->link;
		val = ptr -> data ;
		delete ptr;
	}
	return val;
}

int pop_back()
{
	Node* ptr = f;
	int val = -1;
	if (f == NULL)
	{
		cout << "Queue is Empty\n" ;
	}
	else
	{
		Node* prev = f ;
		Node* ptr = f -> link ;
		while (ptr -> link != NULL)
		{
			prev = ptr ;
			ptr = ptr -> link ;
		}
		prev -> link = ptr -> link ;
		val = prev -> data ;
		delete ptr ;
	}
	return val;
}

void traversal(Node* ptr)
{
	while (ptr != NULL)
	{
		cout << ptr -> data << "\n" ;
		ptr = ptr -> link ;
	}
}


int main()
{
	push_front(90) ;
	push_front(100) ;
	traversal(f) ;
	cout << "\n" ;
	push_back(10) ;
	push_back(900) ;
	push_front(80) ;
	traversal(f) ;
	cout << "\n" ;
	pop_front() ;
	traversal(f) ;
	cout << "\n" ;
	pop_back() ;
	traversal(f) ;
}