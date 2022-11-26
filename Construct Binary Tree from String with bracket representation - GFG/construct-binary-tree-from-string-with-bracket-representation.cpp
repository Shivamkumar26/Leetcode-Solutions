//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
public:
    
    Node *treeFromString(string str){
        stack<Node*> s;
        for(int i=0; i<str.size(); i++){
            // curr data is number
            if(str[i]!='(' && str[i]!=')') {
                string n = "";
                while(str[i]!='(' && str[i]!=')')
                    n += str[i++];
                s.push(new Node(stoi(n)));
                i--;
            } else if(str[i]==')') {
                Node* child = s.top();
                s.pop();
                Node* prnt = s.top();
                if(prnt->left) prnt->right = child;
                else prnt->left = child;
            }
        }
        return s.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends