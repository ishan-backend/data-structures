
#include<bits/stdc++.h>
using namespace std;


/*
for a node, within it : int *a = new int[26];  //normal array
for a node, 26 next pointers to above such nodes: int **b = new int* [26]or[as many children] //pointer array


3 opns:
InsertWord
Search
RemoveWord
*/

class TrieNode
{
public:
    char data;
    TrieNode **children; //an array of pointers to Trienode class
    bool isTerminal;

    TrieNode(char data)
    {
        this->data = data;
        children = new TrieNode* [26]; //26 pointers to a trienode data strcuture/class
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;
public:

    Trie()
    {
        root = new TrieNode('0');
    }

    void insertWord(TrieNode* root, string word)
    {
        //base CASE
        if(word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //small calc
        int idx = word[0]-'a';
        TrieNode *child;

        if(root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->children[idx] = child;
        }

        //Recursive call
        insertWord(child, word.substr(1));
    }

    //user func
    void insertWord(string word)
    {
        insertWord(root, word);
    }


    bool search(TrieNode *root, string word)
    {
        if(word.size() == 0)
        {
            return root->isTerminal;
        }

        //small calc
        int idx = word[0]-'a';
        TrieNode* child;
        if(root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            return false;
        }

        //recursive call
        return search(child, word.substr(1));
    }
    //for user
    bool search(string word)
    {
        return search(root, word);
    }


    void removeWord(TrieNode* root, string word)
    {
        if(word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        //small calc
        TrieNode *child;
        int idx = word[0]-'a';
        if(root->children[idx] != NULL)
        {
            child = root->children[idx];
        }
        else
        {
            //word not found
            return;
        }

        removeWord(child, word.substr(1));

        //remove child node if useless

        //bottom up: deallocate 
        /*
            \0 -> A-> R-> E
                  \-> N -> D

            Note to remove AND, ND will be dealocated and A wont be as it has other children leading to words
        */
        if(child->isTerminal == false)
        {
            for(int i=0; i<26; i++)
            {
                if(child->children[i] != NULL) return;
            }
            delete child;
            //root ke array se pointer delete
            root->children[idx] = NULL;
        }
    }

    void removeWord(string word)
    {
        removeWord(root, word);
    }
};

void solve()
{
    // int choice;
    // cin >> choice;
    // Trie t;
    
    // //cout << "asasas";
    // while(choice != -1){
    //     string word;
    //     bool ans;
    //     switch(choice) {
    //         case 1 : // insert
    //             // getline(cin, word);
    //             cin >> word;
    //             t.insertWord(word);
    //             break;
    //         case 2 : // search
    //             // getline(cin, word);
    //             cin >> word;
    //             ans = t.search(word);
    //             if (ans) {
    //                 cout << "true" << endl;
    //             } else {
    //                 cout << "false" << endl;
    //             }
    //             break;
    //         default :
    //             return;
    //     }
    //     cin >> choice;
    // }
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.search("and")<<endl;

    t.removeWord("and");
    cout<<t.search("and")<<endl;
    

}

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("/home/ishan/Desktop/input.txt",  "r",  stdin);
    freopen("/home/ishan/Desktop/output.txt", "w", stdout);
    #endif
    int t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}
