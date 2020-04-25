#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
#define int long long

/*
10
 9 
4 
-1 
-1 
 5 
 8 
-1 
6 
-1 
-1 
3 
-1 
-1
-1

Ouput:
5

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


int height(BinaryTreeNode<int> *root) 
{   
    if(root == NULL) return 0;
    int h=1,h1,h2;
    h1 = height(root->left);
    h2= height(root->right);
    if(h1>h2)
        h = h+h1;
    else
        h = h+h2;
    
    return h;
}


void solve()
{
    BinaryTreeNode<int> *root = takeInput();
    //printlevelwise(root);
    cout << height(root) << endl;
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
