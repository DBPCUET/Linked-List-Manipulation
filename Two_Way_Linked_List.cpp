#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class Node {
public:
	int data ;
	Node* prev ;
	Node* link ;
	Node(int data)
	{
		this -> data = data ;
		prev = nullptr ;
		link = nullptr ;
	}
};

Node* head = nullptr ;

void traverse_forw()
{
	if (head == NULL)
	{
		cout << "value not found" ;
		return ;
	}
	Node* ptr = head ;
	cout << "Forward : ";
	while (ptr != NULL)
	{
		cout << ptr -> data ;
		if (ptr -> link != NULL)
		{
			cout << "<->" ;
		}
		ptr = ptr -> link ;
	}
	cout << "\n" ;
}


void traverse_backw()
{
	if (head == nullptr)
	{
		cout << "value not found";
		return;
	}
	Node* ptr = head;
	// Traverse to the last node
	while (ptr -> link != nullptr)
	{
		ptr = ptr->link;
	}

	// Traverse backward and print the nodes
	cout << "Backward : ";
	while (ptr != nullptr)
	{
		cout << ptr->data ;
		if (ptr != head)
		{
			cout << "<->" ;
		}
		ptr = ptr->prev;
	}
	cout << "\n";
}


void ins_beg(int val)
{
	Node* newnode = new Node(val) ;
	if (head == NULL)
	{
		head = newnode ;
		return ;
	}
	newnode->link = head ;
	head -> prev = newnode ;
	head = newnode ;
}

void ins_end(int val)
{
	Node* newnode = new Node(val) ;
	if (head == NULL)
	{
		head = newnode ;
		return ;
	}
	Node* temp = head ;
	while (temp -> link != nullptr)
	{
		temp = temp -> link ;
	}
	newnode -> prev = temp ;
	temp -> link = newnode ;

}

void ins_after(int pdata , int ndata)
{
	Node* newnode = new Node(ndata) ;
	if (head == NULL)
	{
		cout << "Value not Found" << "\n" ;
		return ;
	}
	Node* ptr = head ;
	while (ptr != nullptr)
	{
		if (ptr -> data == pdata)
		{
			break ;
		}
		ptr = ptr -> link ;
	}
	if (ptr == NULL)
	{
		return ;
	}
	newnode -> link = ptr -> link ;
	newnode -> prev = ptr ;
	ptr -> link = newnode ;
	newnode -> link -> prev = newnode ;
	//The logic is as same as pseudocode
}


void del(int item)
//
{
	if (head == NULL)
	{		cout << "Deletion can't be possible" << "\n" ;
		return ;
	}
	Node* temp = head ;
	if (temp -> data == item)
	{
		head = head -> link ;
		head -> prev = NULL ;
		return ;
	}
	while (temp != nullptr)
	{
		if (temp -> data == item)
		{
			break ;
		}
		temp = temp -> link ;
	}
	if (temp == nullptr)
	{
		return ;
	}
	if (temp -> link != nullptr)
//if deleted node is not lastnode
	{
		temp -> prev -> link = temp -> link ;
		temp -> link -> prev = temp -> prev ;
	//As same as pseudocode
	}
	else
	{
		temp -> prev -> link = NULL ;
	//If deleted node is lastnode
	}
	delete temp ;
}

void search(int item)
{
	Node* ptr = head;
	int pos = 1;
	while (ptr != nullptr)
	{
		if (ptr->data == item)
		{
			cout << "Value found at position " << pos << endl ;
		}
		ptr = ptr->link;
		pos++;
	}
	return ; 
}





int main()
{
	ins_beg(10) ;
	ins_beg(20) ;
	ins_beg(30) ;
	cout <<"After insertion at beg" << endl ;
	traverse_forw() ;
	traverse_backw() ;
	cout << endl ;
	ins_end(40) ;
	ins_end(201) ;
	cout <<"After insertion at end" << endl ;
	traverse_forw() ;
	traverse_backw() ;
	cout << endl ;
	search(30) ;
	cout << endl; 
	ins_after(20, 60) ;
	ins_after(10000, 90) ;
	cout <<"After insertion at pos:" << endl ;
	traverse_forw() ;
	traverse_backw() ;
	cout << endl ;
	del(201) ;
	cout <<"After Deletion:" << endl ;
	traverse_forw() ;
	traverse_backw() ;
}