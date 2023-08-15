#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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




void print(Node*& start)
{
	if (start == NULL)
	{
		cout << "NO value is found" << endl ;
		return ;
	}
	Node* ptr = start ;
	cout << "Circular_Header: " ;
	do
	{
		cout << ptr -> data << "->" ;
		ptr = ptr -> link ;
	}
	while (ptr != start);
	cout << ptr -> link -> data ;
	cout << "\n" ;
}

void ins_beg(Node*& start , int val)
{
	int cnt = 0 ;
	Node* ptr = start ;
	Node* newnode = new Node(val) ;
	Node* head = new Node(1) ;
	if (ptr == nullptr)
	{
		start = head ;
		newnode -> link = head ;
		head -> link = newnode ;
		return ;
	}
	//This condition must run initially
	newnode -> link = start -> link ;
	start -> link = newnode ;
	start -> data++ ;
//start -> data++ becaue start has the address of head
}

void ins_end(Node*& start , int val)
{
	Node* newnode = new Node(val) ;
	if (start == nullptr)
	{
		ins_beg(start , val) ;
		return ;
	}
	Node* ptr = start ;
	do
	{
		ptr = ptr -> link ;
	}
	while (ptr -> link != start);
//Means the 2nd last node ,
	newnode -> link = ptr -> link ;
	ptr -> link = newnode ;
	start -> data++ ;
	//newnode -> link = start ;


}

void ins_after(Node*& start , int pdata , int ndata )
{
	if (start == NULL)
	{
		ins_beg(start , ndata) ;
		return ;
	}
	Node* newnode = new Node(ndata) ;
	Node* ptr = start ;
	while(ptr -> link != start and ptr -> data != pdata)
	{
		ptr = ptr -> link ;
	}
	if(ptr -> data != pdata)
	{
		return ;
	}
	newnode -> link = ptr -> link ;
	ptr -> link = newnode ;
	start -> data++ ;

}



void search(Node*& start , int val)
{
	Node* ptr = start ;
	int pos = 0 ;
	do {
		if (ptr -> data == val)
		{
			cout << "Position is found at " << pos << endl ;
		}
		ptr = ptr -> link ;
		pos++ ;
	}
	while (ptr != start);

}

void del(Node*& start , int val)
{
	if(start == NULL)
	{
		cout << "Impossible to delete" << endl ;
		return ;
	}
	Node* prev = start ;
	Node* ptr = start -> link ;
	if(prev -> data == val)
	{
		prev -> link = ptr -> link ;
		free(ptr) ;
		start -> data-- ;
		return ;
	}
	while(ptr -> link != start and ptr -> data != val)
	{
		prev = ptr ;
		ptr = ptr -> link ;
	}
	prev -> link = ptr -> link ;
	delete ptr ;
	start -> data-- ;

}



int main()
{
	Node* begin = nullptr ;
	ins_beg(begin, 10) ;
	ins_beg(begin, 200) ;
	ins_beg(begin, 300) ;
	ins_end(begin, 1000) ;
	ins_end(begin, 900) ;
	print(begin) ;
	search(begin, 200) ;
	search(begin, 123) ;
	ins_after(begin , 112 , 921) ;
	ins_after(begin , 200 , 890) ;
	print(begin) ;
	del(begin , 300) ;
	print(begin) ;
} 
