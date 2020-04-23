/*
Queue: FIFO , one entry and one exit point alag alag.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

/*
insert -> enqueue function
front -> access the first element (implicit)
deque-> pop of queue(front element deleted)
size -> 
empty- -> true/false


Here, we'll implement Queue using arrays.
*/
template<typename T>
class QueueUsingArray{
//4 data members
	T* data; 
	int nextindex;
	int firstindex;
	int size;
	int capacity;

public:
	QueueUsingArray(int sz)
	{
		data = new T[sz]; //initial empty array of size sz for functioning as queue
		nextindex = 0;
		firstindex = -1; //no elements initially
		size = 0; //current no of elements in queue
		capacity = sz; //maxm no of elements possible to store in queue
	}

	int getSize()
	{
		return size;
	}

	int isEmpty()
	{
		return (size == 0);
	}

	//insert element of type T
	void enqueue(T element)
	{
		if(size == capacity)
		{
			cout<<"Queue Full , LOL"<<endl;
			return;
		}


		data[nextindex] = element;
		nextindex = (nextindex+1)%capacity;
		if(firstindex == -1)
		{
			firstindex = 0;
		}
		size++;
	}

	T front()
	{
		//value at firstindex
		//a check, before that queue is empty or not
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		//else
		return data[firstindex];
	}

	T dequeue()
	{
		if(isEmpty())
		{
			cout<<"Queue is Empty"<<endl;
			return 0;
		}
		T ans = data[firstindex];
		firstindex = (firstindex+1)%capacity;
		size--;

		//optional
		if(size == 0)
		{
			firstindex = -1;
			nextindex = 0;
		}
		return ans;
	}
};


void solve()
{
	QueueUsingArray<int> q(4);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(10);
	q.enqueue(20);

	q.enqueue(20);

	cout<<q.front()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;

	cout<<q.getSize()<<endl;
	cout<<q.isEmpty()<<endl;


	
}

signed main()
{
	#ifndef ONLINE_JUDGE
    freopen("/home/ishan/Desktop/input.txt",  "r",  stdin);
    freopen("/home/ishan/Desktop/output.txt", "w", stdout);
    #endif
	int t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;


}


