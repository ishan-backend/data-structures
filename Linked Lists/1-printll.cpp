#include<bits/stdc++.h>
using namespace std;

/*
to insert a new node in ll, create a  new node (data, next=null)
and shift nexts easily bro, but remember not to lose next pointer address
*/
class Node{
public:
	int data;
	Node* next;

	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

//create two nodes and connect
//store head node address in LL, otherwise its lost






void solve()
{
	int x, y;
	cin>>x>>y;

	


	//statically create an object
	Node n1(x); //bound to pass data value, as no default constructor
	Node n2(y);

	Node* head = &n1; //8 bytes
	cout<<head->data<<endl;

	n1.next = &n2;
	//print 
	cout<<n1.data<<" "<<n2.data<<endl;

	//dynamically create a node
	Node *n3 = new Node(10);
	Node *n4 = new Node(20);

	

}

signed main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
    #endif
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}