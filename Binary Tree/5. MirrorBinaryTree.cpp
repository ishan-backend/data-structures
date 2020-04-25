#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
#define int long long

/*
MIRROR THE GIVEN B TREE
MAKE LEFT CHILD AS RIGHT AND RIGHT AS LEFT CHILD

Note : You don't need to print or return the tree, just mirror it.

Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Output format : Elements in level order form (Every level in new line)
Sample Input 1:

1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

Sample Output 1:

1 
3 2 
7 6 5 4

Sample Input 2:

5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 2:

5 
6 10 
3 2 
9



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


void mirrorBinaryTree(BinaryTreeNode<int>* root) 
{
    // Write your code here
    if(root == NULL)
         return;
    
    BinaryTreeNode<int>* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

void printLevelATNewLine(BinaryTreeNode<int> *root) 
{
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()) 
        {
            BinaryTreeNode<int> *first = q.front();
            q.pop();
            if(first == NULL) 
            {
                if(q.empty()) 
                {
                    break;
                }
                
                cout << endl;
                q.push(NULL);
                continue;
            }
            cout << first -> data << " ";
            if(first -> left != NULL) 
            {
                q.push(first -> left);
            }
            if(first -> right != NULL) 
            {
                q.push(first -> right);
            }
        }
}


void solve()
{
    BinaryTreeNode<int> *root = takeInput();
    //printlevelwise(root);
    mirrorBinaryTree(root);
    printLevelATNewLine(root); 
   
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
