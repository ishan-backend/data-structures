#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
#define int long long

/*
Given a Binary Tree and an integer x, check if node with data x is present in the input binary tree or not. Return true or false.
Input format :

Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer x

Output Format :

true or false

Sample Input :

8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7

Sample Output :

true




*/

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
        left = NULL;
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


BinaryTreeNode<int>* takeInput()
{
    int rootdata; cin>>rootdata;
    if(rootdata == -1) return NULL;

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
    queue<BinaryTreeNode<int>*> q;

    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int> *curNode = q.front();
        q.pop();

        int leftChild, rightChild;
        cin>>leftChild;

        if(leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            curNode->left = leftNode;
            q.push(leftNode);
        }

        cin>>rightChild;

        if(rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
            curNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printlevelwise(BinaryTreeNode<int> *root)
{
    if(root == NULL) return;

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0)
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        cout<<front->data<<":";
        pendingNodes.pop();

        if(front->left == NULL)
        {
            cout<<"L:"<<-1<<",";
        }
        if(front->left != NULL)
        {
            cout<<"L:"<<front->left->data<<",";
            pendingNodes.push(front->left);
        }

        if(front->right == NULL)
        {
            cout<<"R:"<<-1<<",";
        }
        if(front->right != NULL)
        {
            cout<<"R:"<<front->right->data<<",";
            pendingNodes.push(front->right);
        }
        cout<<endl;
    }

}


bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root == NULL) return false;
    if(root->data == x) return true;
    bool result = false;
    result = (isNodePresent(root->left, x) || isNodePresent(root->right, x));
    return result;

}


void solve()
{
    BinaryTreeNode<int> *root = takeInput();
    //printlevelwise(root);
    int x;
    cin >> x;
    if(isNodePresent(root, x)) {
        cout << "true";
    }
    else {
        cout << "false";
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
