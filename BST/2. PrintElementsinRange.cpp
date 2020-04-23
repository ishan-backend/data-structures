#include<bits/stdc++.h>
#include<iostream>
#include<queue>
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
	Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
	Print the elements in increasing order.

	Input:
	Line 1 : Elements in level order form (separated by space)
	(If any node does not have left or right child, take -1 in its place)
	Line 2 : Two Integers k1 and k2

	Output Format :

	Required elements (separated by space)

Sample Input :

8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
6 10

Sample Output :

6 7 8 10
*/

void printinrange(BinaryTreeNode<int>* root, int k1, int k2)
{
	if(root == NULL)
		return;

	if(root->data >= k1 and root->data <= k2)
	{
		printinrange(root->left, k1, k2);
		cout<<root->data<<" ";
		printinrange(root->right, k1, k2);
	}

	if(root->data < k1)
	{
		printinrange(root->right, k1, k2);
		return;
	}
	if(root->data > k2)
	{
		printinrange(root->left, k1, k2);
		return;
	}
}





void solve()
{
	BinaryTreeNode<int>* root = takeinputlevelwise();
	int k1, k2;
	cin>>k1>>k2;
	printinrange(root, k1, k2);
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


