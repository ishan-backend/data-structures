#include<bits/stdc++.h>
using namespace std;


 Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };



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

Node* takeInput2()
{
    //O(n) for inserting n nodes
    int data; cin>>data;
    Node* head = NULL;
    Node* tail = NULL;
    //hame apne head ko puri LL me sirf ek bar update krna hai jb first node enter krwa rhe
    while(data != -1)
    {
        //statically object, scope under only this while
        //Node newnode(data);

        //dynamic object, newnode is a pointer
        Node* newnode = new Node(data);

        if(head == NULL)
        {
           // head = &newnode; for static object
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;

            //or
            //tail = newnode;
        }

        cin>>data;
    }
    return head;
}



void print(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
}


// . or -> lgane se pehle ensure current (temp)isnt null, else segmentation fault
Node* insertNode(Node* head, int i, int data)
{
    //newnode with desired data
    Node* newnode = new Node(data);
    int count=0;

    if(i == 0)
    {
        newnode->next = head;
        head = newnode;
        //return new head
        return head;
    }

    Node* temp = head;
    while(count < i-1 and temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    if(temp != NULL)
    {
    Node *a = temp->next;  //temp ke aage newnode aayega
    temp->next = newnode;
    newnode->next = a;
    }

    return head; //else return pehle wala head
    
}



void solve()
{
    //to enter n no of nodes, 
    Node* head = takeInput2();
    print(head);
    cout<<endl;
    int i, data;
    cin>>i>>data;
    insertNode(head, i, data);
    print(head);

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
