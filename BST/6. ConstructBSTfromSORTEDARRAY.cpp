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

BinaryTreeNode<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"Enter root data"<<endl;
	cin>>rootdata;

	if(rootdata == -1)
	{
		return NULL;
	}

	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);

	queue<BinaryTreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while(!pendingNodes.empty())
	{
		BinaryTreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"Enter left child of"<<front->data<<endl;
		int leftchilddata;
		cin>>leftchilddata;

		if(leftchilddata != -1)
		{
			BinaryTreeNode<int>* lchild = new BinaryTreeNode<int>(leftchilddata);
			front->left = lchild;
			pendingNodes.push(lchild);
		}

		cout<<"Enter right child of"<<front->data<<endl;
		int rightchilddata;
		cin>>rightchilddata;

		if(rightchilddata!=-1)
		{
			BinaryTreeNode<int>* rchild = new BinaryTreeNode<int>(rightchilddata);
			front->right = rchild;
			pendingNodes.push(rchild);
		}

	}
	return root;
}

/*
	Construct BST from sorted array:
	Functions just like Binary Search (balanced) to make O(height), so make height balanced
	Dont make skewed BST

Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note : If array size is even, take first mid as root.
Input format :

Line 1 : Integer n (Size of array)
Line 2 : Array elements (separated by space)

Output Format :

BST elements (in pre order traversal, separated by space)

Sample Input :

7
1 2 3 4 5 6 7

Sample Output :

4 2 1 3 6 5 7 


*/

BinaryTreeNode<int>* makeBST(int* arr, int start, int end)
{
	if(start > end)
		return NULL;

	int mid = (start+end)>>1;
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(arr[mid]);

	root->left = makeBST(arr, start, mid-1);
	root->right = makeBST(arr, mid+1, end);
	return root;
}

BinaryTreeNode<int>* constructTree(int *arr, int n)
{
	return makeBST(arr, 0, n-1);
}

void preorder(BinaryTreeNode<int>* root)
{
	if(root == NULL)
		return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void solve()
{
	int size;
    cin>>size;
    int *input=new int[1+size];
    
    for(int i=0;i<size;i++)
        cin>>input[i];
    
    BinaryTreeNode<int>* root = constructTree(input, size);
    preorder(root);
	
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


