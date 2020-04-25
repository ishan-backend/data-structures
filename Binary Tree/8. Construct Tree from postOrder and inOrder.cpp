#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

/*

Construct Tree from Postorder and Inorder

Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.
Note: Assume binary tree contains only unique elements.

Input format :

Line 1 : n (Total number of nodes in binary tree)

Line 2 : Post order traversal

Line 3 : Inorder Traversal

Output Format :

Elements are printed level wise, each level in new line (separated by space).
Sample Input :

8
8 4 5 2 6 7 3 1
4 8 2 5 1 6 3 7

Sample Output :

1 
2 3 
4 5 6 7 
8



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


// BinaryTreeNode<int>* takeInput()
// {
//     int rootdata; cin>>rootdata;
//     if(rootdata == -1) return NULL;

//     BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootdata);
//     queue<BinaryTreeNode<int>*> q;

//     q.push(root);
//     while(!q.empty())
//     {
//         BinaryTreeNode<int> *curNode = q.front();
//         q.pop();

//         int leftChild, rightChild;
//         cin>>leftChild;

//         if(leftChild != -1)
//         {
//             BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
//             curNode->left = leftNode;
//             q.push(leftNode);
//         }

//         cin>>rightChild;

//         if(rightChild != -1)
//         {
//             BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
//             curNode->right = rightNode;
//             q.push(rightNode);
//         }
//     }
//     return root;
// }

BinaryTreeNode<int>* construct(int *postorder, int postStart, int postEnd, int *inorder, int inStart, int inEnd)
{
    if(postStart > postEnd or inStart > inEnd)
        return NULL;

    //last element will be root of this subarray formed subtree in postorder
    int valroot = postorder[postEnd];
    BinaryTreeNode<int> *p = new BinaryTreeNode<int>(valroot);

    //find parent element idx from inorder
    int k=0;
    for(int i=inStart; i<=inEnd; i++)
    {
        if(valroot == inorder[i])
        {
            k=i;
            break;
        }
    }

    p->left = construct(postorder, postStart, postStart+(k-inStart)-1, inorder, inStart, k-1);
    p->right = construct(postorder, postStart + (k-inStart), postEnd-1, inorder, k+1, inEnd);

    return p;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
   
   int postStart = 0;
   int postEnd = postLength-1;

   int inStart = 0;
   int inEnd = inLength-1;

   return construct(postorder, postStart, postEnd, inorder, inStart, inEnd);
   
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

//solution



void solve()
{
    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for(int i=0;i<size;i++)
        cin>>post[i];
    for(int i=0;i<size;i++)
        cin>>in[i];
    BinaryTreeNode<int>* root = buildTree(post, size, in, size);
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
