#include<bits/stdc++.h>
using namespace std;

/*
K-SORTED ARRAY:

For given input array, ith indexed element after sorting only can go upto i+kth idx or i-kth idx


10 12 15 6 9 , k=3
-> 15 12 10 9 6

with help of nlogn ,we can sort an array
But we want < nlogn for k sorted array

use max priority queue over sliding window of k in pq
 and we'll do it inplace that is O(1)

5
3
10 12 6 7 9

->12 10 6 7 9

*/

void ksortedarray(int input[], int n, int k)
{
    priority_queue<int> pq;

    //k log k
    for(int i=0; i<k; i++)
    {
        pq.push(input[i]);
    }
    int j=0;
    //(n-k)logk baar pop
    for(int i=k; i<n; i++)
    {
        input[j] = pq.top();
        pq.pop();
        pq.push(input[i]);
        j++;
    }

    //k log k
    while(!pq.empty())
    {
        input[j] = pq.top();
        pq.pop();
        //j++; since k srted array 
    }
}//(n+k)logk where k <<<<<< n -> O(n)

void solve()
{
    int size;
    cin>>size;
    int k;
    cin>>k;

    int* arr = new int[1+size];

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    ksortedarray(arr, size, k);

    for(int i=0; i<size; i++)
    {
        cout<<arr[i]<<" ";
    }

}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("/home/ishan/Desktop/input.txt",  "r",  stdin);
    freopen("/home/ishan/Desktop/output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
