#include<bits/stdc++.h>
using namespace std;

/*
har idx of Bucket array is a linked list
for every LL at each idx: Node<V> type ka pointer to access

And bucket array is array of such pointers, to point it:
Node<V>* type ka pointer-> Node<V>**

int size; //array size
int bucket size; //size allowed for hashing

*/

template <typename V>
class MapNode
{
public:
    //LL ki node for each idx of bucket array
    string key;
    V value;
    MapNode *next;

    MapNode(string key, V value)
    {
        this->key = key;
        this->value = value;
        next = NULL;
    }

    //recursive destructor
    ~MapNode()
    {
        delete next;
    }
};

template <typename V> //typename V of value , key can be anything
class ourmap
{
    //a node which is head of LL
    MapNode<V>** buckets;
    int size;
    int numbuckets;

public:
    ourmap()
    {
        size=0;
        numbuckets=5;
        buckets = new MapNode<V>* [numbuckets];

        //removing garbage addresses, as they are dangerous
        for(int i=0; i<numbuckets; i++)
        {
            buckets[i] = NULL;
        }
    }

    //~destructor
    ~ourmap()
    {
        //pehle har LL ko distruct
        for(int i=0; i<numbuckets; i++)
        {
            delete buckets[i];
        }

        delete [] buckets;
    }


    //functions:

    int size() return count;


    //search
    V getValue(string key)
    {
        //get bucketindex for key
        int bucketindex = getbucketindex[bucketindex];
        //head of that LL
        MapNode<V>* head = buckets[bucketindex];
        while(head != NULL)
        {
            if(head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0; //nhi mila
    }




private:
    int getbucketindex(string key)
    {
        //pehle hme hashcode chahiye
        int hashcode;

        //how to find? using last method of base p
        int currentcoeff = 1; //p^0

        for(int i=key.length()-1; i>=0; i--)
        {
            hashcode += key[i]*currentcoeff;
            hashcode %= numbuckets;

            currentcoeff *= 37;
            currentcoeff %= numbuckets;
        }
        return hashcode%numbuckets;
    }
public:
    void insert(string key, V value)
    {
        int bucketindex = getbucketindex(string key);
        MapNode<V>* head = buckets[bucketindex];

        //kya ye entry pehle se hai, then we'll update that entry and not create a new one

        while(head != NULL)
        {
            if(head->key == key)
            {
                head->value = value;
            }

            head = head->next;
        }
        //agar khi nhi mila, lets find head again
        //create a new node, put value there and then head point to it
        head = buckets[bucketindex];
        MapNode<V>* node = new MapNode<V>(key, value);
        node->next = head;

        //ab nye head pe dekho
        buckets[bucketindex] = node;
        count++; //ek element or aya map me
    }



    V remove(string key)
    {
        //get bucketindex for key
        int bucketindex = getbucketindex[bucketindex];
        //head of that LL
        MapNode<V>* head = buckets[bucketindex];
        MapNode<V>* prev = NULL;

        while(head != NULL)
        {
            if(head->key  == key)
            {
                //remove head, so connect prev to node->next
                if(prev == NULL)
                {
                    //means fiirst pos of LL pe mil gya key
                    buckets[bucketindex] = head->next;
                    //head gone effectively

                }
                else
                {
                    prev->next = head->next;
                }


                // smbhal ke rkho value to return
                V value = head->value;
                //since we wrote a recursive destrcutor, to delete head
                head->next  = NULL;
                delete head;
                count--;
                return value;

            }

            prev = head;
            head = head->next;
        }
        //agar yha pohoche mtlb, mtlb khi bhiwo node nhi mili
        return 0; //signifies not present       
    }
};


void solve()
{

}

signed main()
{
    ishan_pandey();
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

/*
Time complexity:
 n = no of entries in ourmap
 Time to find hashcode: time depends on length of word in case of string key
 = O(L), say small strings so constant time

 for 10^5 (n) entries,
 length of this list in worst case: O(n), all in same bucket

 But research, on avg, for b boxes n entries, each box has n/b entries
 ->O(n/b) which is called load factor, load on our hash table.

 We will ensure n/b < 0.7 approxs
 for 100 entries, we'll have 130 entries

We have good qualities of hashcodes, every box will have contant no of entries atmax 7 if n/b is 10 times say

How to fix n/b?

-> for inc values of n, increase b....

Which means we rehash to increase bucket size to 2x
All entries are then rehashed, so load factor is reduced.

But this rehashing will be done 2x time after previous time we did it.

For insertion  and deletion :O(1)
For searching :O(1)

*/
