/*
Queue: FIFO , one entry and one exit point alag alag.
*/
#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

/*
Uptil now, we had a capcity , that we had limited size of queue.
Now well make queue dynamic and no limitation on size

How to?
Create new array of double size, if earlier size was filled. Copy previous elements,
update nextindex, size, firstindex(not).

Dont copy paste elements from prev queue as it is.

firstindex : first element of queue to previdxsize-1, 
then copy idx 0  to firstidx-1

firstidx = 0;
nextidx = cap+1, update cap = 2*cap

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
			// cout<<"Queue Full , LOL"<<endl;
			// return;
			T* newdata = new T[2*capacity];
			int j=0;
			for(int i=firstindex; i<capacity; i++)
			{
				newdata[j] = data[i];
				j++;
			}
			for(int i=0; i<firstindex; i++)
			{
				newdata[j] = data[i];
				j++;
			}
			delete [] data; //array deleted
			data = newdata; //pointer redirected to new array
			firstindex = 0;
			nextindex = capacity;
			capacity *= 2;

			//this ends the improvements
		}


		data[nextindex] = element;
		nextindex = (nextindex+1)%capacity;
		if(firstindex == -1) //initially
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


