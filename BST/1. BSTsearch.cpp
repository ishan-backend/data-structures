#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;

/*
For every node, everythng in left subt is less than n's data
Everything in n's right subtree is greater than n's data

Balanced BST: searching fast, balanced no of nodes on left and right
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
	//else BST is lost, if pointer not returned
	return root;
}

//search only goes one side
BinaryTreeNode<int>* searchinBST(BinaryTreeNode<int> *root, int k)
{
	if(root == NULL)
	{
		return NULL;
	}	
	if(root->data == k)
	{
		return root;
	}

	else if(k < root->data)
	{
		return searchinBST(root->left, k);
	}
	else
		return searchinBST(root->right, k);
} 


void solve()
{
	BinaryTreeNode<int>* root = takeinputlevelwise();
	int k;
	cin>>k;

	BinaryTreeNode<int>* ans = searchinBST(root, k);
	if(ans != NULL)
	{
		cout<<ans->data<<endl;
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

/* INput:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2
-> 2
*/
