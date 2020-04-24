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
Find Path in BST
Send Feedback
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST). Return null otherwise.
Assume that BST contains all unique elements.
Input Format :

Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer k

Output Format :

Path from node k to root

Sample Input :

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2

Sample Output :

2
5
8




    
*/

//returns a pointer to head of array/vector
vector<int>* findPath(BinaryTreeNode<int> *root, int data)
{
    if(root == NULL) return NULL;

    //if value found, create a empty vector, push in it its value , return its refernce
    if(root->data == data)
    {
        vector<int> *output = new vector<int>;
        output->push_back(root->data);
        return output;
    }

    else if(data < root->data)
    {
        vector<int> *output = findPath(root->left, data);
        if(output != NULL)
        {
            output->push_back(root->data);
        }
        return output;
    }

    else
    {
        vector<int> *output = findPath(root->right, data);
        if(output != NULL)
        {
            output->push_back(root->data);
        }
        return output;

    }
}



void solve()
{
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin>>k;

    vector<int>* output = findPath(root, k);

    if(output != NULL)
    {
        for(int i=0; i<output->size(); i++)
        {
            cout<<output->at(i)<<endl;
        }
    }
    delete root;
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
