#include<bits/stdc++.h>
using namespace std;
#include<queue>

/*
K-SMALLEST ELEMENTS:


You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.
Input Format :

Line 1 : Size of array (n)
Line 2 : Array elements (separated by space)
Line 3 : Integer k

Output Format :

k smallest elements

Sample Input 1 :

13
2 12 9 16 10 5 3 20 25 11 1 8 6 
4

Sample Output 1 :

5
3
2
1

*/

vector<int> ksmallest(int* input, int n, int k)
{
    priority_queue<int> pq; //maxpq
    vector<int> output;

    int i;
    for(i=0; i<k; i++)
    {
        pq.push(input[i]);
    }
    for(; i<n; i++)
    {
        if(input[i] < pq.top())
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

    vector<int> res = ksmallest(arr, size, k);

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
