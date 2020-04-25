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

Node* takeInput()
{
    //O(n^2)
    int data; cin>>data;
    Node* head = NULL;
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
        }
        else
        {
            //tail ke next pe newnode add/prev ke next pe
            Node* temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }

        cin>>data;
    }
    return head;
}

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





void solve()
{
    //to enter n no of nodes, 
    Node* head = takeInput2();
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
