#include<bits/stdc++.h>
using namespace std;
int node_no ;
class node
{
public:
	int data ;
	node* next ;
	node(int val){
	data =val;
	next=NULL;
	}
};

void insbeg(node* &start , int val)
{
	node* n = new node(val) ;
	if(start == NULL)
	{
	    node* st=new node(-1);
	    start=st;
		node* head = new node(1) ;
		start->next=head;
		head -> next = n ;
		return ;
	}
	n -> next = start -> next -> next ;
	start -> next -> next = n ;
	start->next->data++;
}
void insend(node* &start , int val)
{
	if(start == NULL)
	{
		insbeg(start , val) ;
		return ;
	}
	node *n = new node(val) ;
	node *temp = start ;
	while(temp -> next)
	{
		temp = temp -> next ;

	}
	temp -> next = n ;
	start->next->data++;
}

void insafter(node* &start , int pos_val , int val)
{
	if(start == NULL)
	{
		cout << "Position not found" << endl ;
		return ;
	}
	node* temp = start->next ;
	while(temp -> next -> data != pos_val)
	{
		temp = temp -> next ;
		if(temp->next == NULL)
		{
			cout << "Position not found" << endl ;
			return ;
		}
	}
	node* n = new node(val);
	n -> next = temp -> next ;
	temp -> next = n ;
	start->next->data++;
}

void del(node *start , int val)
{
	if(start == NULL)
	{
		cout << "Value not found" << endl ;
		return ;
	}
	node* temp = start ;
	while(temp -> next -> data != val)
	{
		temp = temp -> next ;
	}
	node* del = temp -> next ;
	temp -> next = del -> next ;
	free(del) ;
	start -> next -> data-- ;
}

void prnt(node* start)
{
	if(start == NULL)
	{
		cout << "No value is found" << endl ;
		return ;
	}
	node* temp = start ->next;
	while(temp !=NULL)
	{
		cout << temp -> data << "->" ;
		temp=temp->next;

	}
	//cout<<"NULL"<<endl;
}

int main()
{
node* start=NULL;
	insbeg(start,11) ;
	insend(start,13);
	insend(start,15);
	prnt(start) ;
	insafter(start,13,17);
	cout << endl ;
	insafter(start,18,17);
	cout << endl ;
	prnt(start) ;
	cout << endl ;
del(start,13);
prnt(start) ;
}


