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
Check if a Binary Tree is BST

Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
Duplicate elements should be in right subtree.
Input format :

Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place

Output format :

true or false

Constraints :
1 <= N <= 10^5
Sample Input 1 :

3 1 5 -1 2 -1 -1 -1 -1

Sample Output 1 :

true

Sample Input 2 :

5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

Sample Output 2 :

false

Note: CheckBST-1 : O(nh)
		suggestion:

		return <<min, max>, bool> ; bool: tree is BST or not
		or return some ds/class 


*/
class isBSTReturn
{
public:
	bool isBST;
	int minimum;
	int maximum;
};

isBSTReturn checkBST2(BinaryTreeNode<int>* root)
{
	if(root == NULL)
	{
		//create new tppe object of this class
		isBSTReturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}

	isBSTReturn leftoutput = checkBST2(root->left);
	isBSTReturn rightoutput = checkBST2(root->right);

	int minimum = min(root->data, min(leftoutput.minimum, rightoutput.minimum));
	int maximum = max(root->data, max(leftoutput.maximum, rightoutput.maximum));

	//4 conditions:
	bool isBSTfinal = (root->data > leftoutput.maximum) and

	(root->data <= rightoutput.minimum) and
	(leftoutput.isBST) and (rightoutput.isBST);

	isBSTReturn output;
	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTfinal;
	return output;
}


bool isBST(BinaryTreeNode<int> *root)
{
	isBSTReturn  ans = checkBST2(root);
	return ans.isBST;
}


void solve()
{
	BinaryTreeNode<int>* root = takeinputlevelwise();

	//soln
	if(isBST(root))
	{
		cout<<"true\n";
	}
	else
		cout<<"false\n";
	
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


