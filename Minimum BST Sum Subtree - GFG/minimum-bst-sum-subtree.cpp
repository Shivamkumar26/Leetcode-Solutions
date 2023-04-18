//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
    int findSum(Node* root) {
        if(!root) return 0;
        int l = findSum(root->left);
        int r = findSum(root->right);
        return l+r+root->data;
    }
    void findInorder(Node* root, vector<int>& v) {
        if(!root) return;
        findInorder(root->left, v);
        v.push_back(root->data);
        findInorder(root->right, v);
    }
    void solve(int t, int& len, Node* root) {
        if(!root) return;
        
        int sum = findSum(root);
        
        if(sum == t) {
            vector<int> v;
            findInorder(root, v);
            bool isInorderSorted = true;
            for(int i=1; i<v.size(); i++) {
                if(v[i]<=v[i-1]) {
                    isInorderSorted=false;
                    break;
                }
            }
            if(isInorderSorted)
            len = min(len, (int)v.size());
        }
        solve(t, len, root->left);
        solve(t, len, root->right);
    }
public:
    int minSubtreeSumBST(int target, Node *root) {
        int minLen = INT_MAX;
        solve(target, minLen, root);
        return ((minLen == INT_MAX) ? -1 : minLen);
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends