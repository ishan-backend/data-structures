#include<bits/stdc++.h>
using namespace std;
#include<queue>

/*
K-LARGEST ELEMENTS:

priority_queue<int> pq; //maxpq parent<child, then swap
priority_queue<int, vector<int>, greater<int>> pq; //minpq , parent>child then swap


13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

->
12
16
20
25
*/
//int input[]
vector<int> klargest(int* input, int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq; //minpq
    vector<int> output;

    int i;
    for(i=0; i<k; i++)
    {
        pq.push(input[i]);
    }
    for(; i<n; i++)
    {
        if(input[i] > pq.top()) //change sign
        {
            pq.pop();
            pq.push(input[i]);
        }
    }

    while(!pq.empty())
    {
        output.push_back(pq.top());
        pq.pop();
    }
    return output;
}



void solve()
{
    int size;
    cin>>size;
    

    int* arr = new int[1+size];

    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    int k;
    cin>>k;

    vector<int> res = klargest(arr, size, k);

    for(int i=0; i<k; i++)
    {
        cout<<res[i]<<" ";
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
