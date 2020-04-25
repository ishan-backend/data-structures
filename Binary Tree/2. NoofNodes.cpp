#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;
#define int long long

/*


Sample Input :

8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

Sample Output :
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

int numNodes(BinaryTreeNode<int> *root)
{
    if(root == NULL)
        return 0;

    return 1 + numNodes(root->left) + numNodes(root->right);
}



void solve()
{
    BinaryTreeNode<int> *root = takeInput();
    //printlevelwise(root);
    int ans = numNodes(root);
    cout<<ans<<endl;
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
