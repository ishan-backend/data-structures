#include<bits/stdc++.h>
using namespace std;

/*
Inplace Heap sort:
Building Heap in given array only, not taking additional place

Assume First elem considered inside heap, Rest n-1 elements to be inserted yet into heap.
CBT is fulfilled but Heap order isnt yet

INsert: compare coming elem with parent, and as required take process to left and swap


Remove: remove first elem of array, then satisfy heap order prop
assume sz = n-1, then swap first with last, rightlim = n-1


Given an integer array of size n. Sort this array (in decreasing order) using heap sort.
Space complexity should be O(1).
Input Format :

Line 1 : Integer n, Array size
Line 2 : Array elements, separated by space

Output Format :

Array elements after sorting

Constraints :
1 <= n <= 10^6
Sample Input:

6 
2 6 8 5 4 3

Sample Output:

8 6 5 4 3 2


*/

void inplaceHeapSort(int pq[], int n)
{
    //Build heap in input array
    for(int i=1; i<n; i++)
    {
        int childIndex = i;
        while(childIndex > 0)
        {
            int parentIndex = (childIndex-1)/2;

            if(pq[parentIndex] > pq[childIndex])
            {
                //swap
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
            {
                break;
            }

            childIndex = parentIndex;
        }
        
    }

    //Remove Elements
    int size = n;

    while(size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size-1];
        pq[size-1] = temp;

        size--;

        int parentIndex = 0;
        int leftchildIndex = 2*parentIndex + 1;
        int rightchildIndex = 2*parentIndex + 2;

        while(leftchildIndex < size)
        {
            int minIndex = parentIndex;

            if(pq[minIndex] > pq[leftchildIndex])
            {
                minIndex = leftchildIndex;
            }
            if(rightchildIndex < size and pq[rightchildIndex] < pq[minIndex])
            {
                minIndex = rightchildIndex;
            }
            if(minIndex == parentIndex)
            {
                break;
            }

            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftchildIndex = 2*parentIndex +1;
            rightchildIndex = 2*parentIndex +2;
        }
    }
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

    inplaceHeapSort(arr, size);

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
