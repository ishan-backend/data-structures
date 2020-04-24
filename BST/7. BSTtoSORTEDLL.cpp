#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left  = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

BinaryTreeNode<int>* takeInput() {
    int rootData;
    //cout << "Enter root data : ";
    cin >> rootData;
    if(rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
    q.pop();
        int leftChild, rightChild;
        //cout << "Enter left child of " << currentNode -> data << " : ";
        cin >> leftChild;
        if(leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode -> left =leftNode;
            q.push(leftNode);
        }
        //cout << "Enter right child of " << currentNode -> data << " : ";
        cin >> rightChild;
        if(rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode -> right =rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

/*
Given a BST, convert it into a sorted linked list. Return the head of LL.
Input format :

Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)

Output Format :

Linked list elements (separated by space)

Sample Input :

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

Sample Output :

2 5 6 7 8 10


    
*/
template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class base
{
    //stores the head and tail pointers of a LL
public:
    Node<int> *head;
    Node<int> *tail;
};

base askedFunc(BinaryTreeNode<int> *root)
{
    //base case : null tree
    if(root == NULL)
    {
        base b;
        b.head = NULL; b.tail = NULL;
        return b;
    }

    base l = askedFunc(root->left);
    base r = askedFunc(root->right);


    //bottom up process
    //Linked list head pointer at this level of recursion, points to root as were sure root has some data
    Node<int> *thead = new Node<int>(root->data);


    //if left exists and has clear boundaries
    if(l.tail != NULL)
    {
        l.tail->next = thead;
    }


    //rhead maybe NULL, we'll see later
    thead->next = r.head;


    base b;
    if(l.head != NULL)
    {
        b.head = l.head;
    }
    else
    {
        b.head = thead;
    }

    if(r.tail != NULL)
    {
        b.tail = r.tail;
    }
    else
    {
        b.tail = thead;
    }
    return b;

}



Node<int> *constructBST(BinaryTreeNode<int> *root)
{
    base obj = askedFunc(root);
    return obj.head;
}


void solve()
{
    //pointer to BST
    BinaryTreeNode<int> *root = takeInput();
    //LL head pointer is returned
    Node<int> *head = constructBST(root);
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
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
