/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0;
    void solve(TreeNode* root, string str) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans += stoi(str + to_string(root->val));
            return;
        }
        
        if(root->left) solve(root->left, str + to_string(root->val));
        if(root->right) 
            solve(root->right, str + to_string(root->val));
    }
public:
    int sumNumbers(TreeNode* root) {
        
        string str = "";
        solve(root, str);
        
        /* 
        
        traverse 
        string maintain
        ans += stoi
        remove last character
        
        */
        return ans;
    }
};