#include<bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	int priority;
	Node* link;
	Node(int data, int priority)
	{
		this->data = data;
		this->priority = priority;
		link = NULL;
	}
};

Node* front = nullptr;

void push(int data, int priority)
{
	Node* newnode = new Node(data, priority);
	if (front == NULL)
	{
		front = newnode;
		return;
	}
	if (front->priority <= newnode->priority)
	{
		newnode->link = front;
		front = newnode;
	}
	else
	{
		Node* tmp = front;
		while (tmp->link != NULL && tmp->link->priority >= newnode->priority)
		{
			tmp = tmp->link;
		}
		newnode->link = tmp->link;
		tmp->link = newnode;
	}
}

void pop()
{
	if(front==nullptr)
    {
        cout<<"No item"<<endl;
        return ;
    }
	Node* tmp = front;
	cout <<"Deleted item is " << tmp -> data << "\n" ;
	front = front->link;
	delete(tmp) ;
}


void print()
{
	Node* ptr = front;
	while (ptr != NULL)
	{
		cout << ptr->data << "\n";
		ptr = ptr->link;
	}
}

int main()
{
	push(10, 1019);
	push(5, 10);
	push(567, 4);
	print();
	pop() ;
	print() ;
	return 0;
}