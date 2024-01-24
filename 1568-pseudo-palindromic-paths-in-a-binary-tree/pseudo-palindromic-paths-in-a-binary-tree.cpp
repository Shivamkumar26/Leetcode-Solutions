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
    bool isPPal(unordered_map<int, int>& mp) {
        int oddfreq = 0;
        for(auto i=mp.begin(); i!=mp.end(); i++) {
            if(i->second % 2) oddfreq++;
        }
        return oddfreq <= 1;
    }
    void solve(TreeNode* root, int& c,  unordered_map<int, int>& path) {
        if(!root) return;
        if(!root->left && !root->right) {
            path[root->val]++;
            if(isPPal(path)) c++;
            path[root->val]--;
            if(path[root->val]==0) path.erase(root->val);
            return;
        }
        
        path[root->val]++;
        solve(root->left, c, path);
        solve(root->right, c, path);
        path[root->val]--;
        if(path[root->val]==0) path.erase(root->val);
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        if(!root) return 0;
        unordered_map<int, int> path;
        int count = 0;
        solve(root, count, path);
        
        return count;
    }
};
/*

pseudo - palindromic 
freq of all ele is even 
odd freq count <= 1 

*/