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
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class BST
{
    BinaryTreeNode<int>* root;

public:
    //imp constructor and destructor(recursive)
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

private:

    BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL) return NULL;

        if(data > node->data)
        {
            node->right = deleteData(data, node->right);
            return node;
        }

        else if(data < node->data)
        {
            node->left = deleteData(data, node->left);
            return node;
        }

        else
        {
            if(node->left == NULL and node->right == NULL)
            {
                delete node;
                return NULL;
            }

            else if(node->left == NULL)
            {
                BinaryTreeNode<int>* temp = node->right;
                node->right == NULL;
                delete node;
                return temp;
            }

            else if(node->right == NULL)
            {
                BinaryTreeNode<int>* temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }

            else
            {
                BinaryTreeNode<int>* minNode = node->right;
                while(minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(rightMin, node->right);
                return node;

            }
        }

    }

    void printTree(BinaryTreeNode<int>* root)
    {
        if(root == NULL)
            return;
        cout<<root->data<<" :";

        if(root->left != NULL)
        cout<<"L: "<<root->left->data<<" ,";

        if(root->right != NULL)
        cout<<"R: "<<root->right->data;

        cout<<endl;

        printTree(root->left);
        printTree(root->right);

    }


public:
    void deleteData(int data)
    {
        //if root-NULL then return
        //if root->data < data, right side me call, similarly forleft side
        //if data is same, then root is changed 
        //1. if this is leaf, so return NULL
        //2. if one child null, return other child
        //3. root hai, and left and right child isnt null
        //we need to find a replacement for root r
        //Observe that lergest of left side can be made root
        //or smallest of right side can be made root
        root = deleteData(data, root);
    }

    void printTree()
    {
        printTree(root);
    }

private:
    BinaryTreeNode<int>* insert(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            BinaryTreeNode<int>* newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }

        if(data < node->data)
        {
            node->left = insert(data, node->left);
        }
        else
        {
            node->right = insert(data, node->right);
        }
        return node;
    }
public:
    void insert(int data)
    {
        //given a BST you need to insert 7 in it.
        //create a node and put 7, also root is changing from null to 7 for first element and return it

        //if 5 is now inserted , again root is changed...acc to BST structure
        this->root = insert(data, this->root);

    }


private:
    //helper function of hasdata: as we want to do hasdata(data, root->left), not possible
    //if this private isnt there, then it will take root of BST
    bool hasData(int data, BinaryTreeNode<int>* node)
    {   
        if(node == NULL)
            return false;

        if(node->data == data)
        {
            return true;
        }
        else if(data < node->data)
        {
            //left me dekho sirf
            return hasData(data, node->left);
        }
        else
        {
            //right me sirf dekho
            return hasData(data, node->right);
        }


    }


public:
    bool hasData(int data) //works on root of object
    {
        return hasData(data, root); //helper function ka mtlb, btao kisme kya dhundhna hai, isko hmare object se koi mtlb nhi hai
    }

};


void solve()
{
    BST* tree = new BST();

    int choice, input;

    while(true)
    {
        cin>>choice;

        switch(choice)
        {
            case 1:
                cin>>input;
                tree->insert(input);
                break;
            case 2:
                cin>>input;
                tree->deleteData(input);
                break;
            case 3:
                cin>>input;
                if(tree->hasData(input))
                {
                    cout<<"true"<<endl;
                }
                else
                {
                    cout<<"false"<<endl;
                }
                break;
            default:
                tree->printTree();
                return;
                break;
        }
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
