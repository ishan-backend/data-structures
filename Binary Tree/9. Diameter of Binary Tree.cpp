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
//pair has (height and diameter)
pair<int, int> heightDiameter(BinaryTreeNode<int>* root)
{
    if(root == NULL)
    {
        return {0, 0};
    }

    pair<int, int> lans = heightDiameter(root->left);
    pair<int, int> rans = heightDiameter(root->right);
    int ldia = lans.second;
    int lh = lans.first;

    int rdia = rans.second;
    int rh = rans.first;

    int height = 1+max(lh, rh);
    int diameter = max(lh+rh, max(ldia, rdia));

    pair<int, int> ret;
    ret.first = height;
    ret.second = diameter;
    return ret;
}



void solve()
{

    BinaryTreeNode<int>* root = takeInput();//levelwise
    printLevelATNewLine(root);

    pair<int, int> ans = heightDiameter(root);
    cout<<endl<<"Height: " <<ans.first;
    cout<<endl<<"Diameter: "<<ans.second;
}

/*
Input:
1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

Output:
1 
2 3 
4 5 
6 7 
8 9 
Height: 5
Diameter: 6
*/


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
