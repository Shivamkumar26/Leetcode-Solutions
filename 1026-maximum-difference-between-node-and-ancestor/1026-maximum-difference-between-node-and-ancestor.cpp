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
    void solve(TreeNode* root, int mx, int mn, int& ans) {
        if(!root) {
            ans = max(ans, abs(mx-mn));
            return;
        }
        if(root->val > mx) mx = root->val;
        if(root->val < mn) mn = root->val;
        
        solve(root->left, mx, mn, ans);
        solve(root->right, mx, mn, ans);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        
        // root to leaf mei max and min find out 
        // global max(diff) 
        
        int maxx = 0, minn = INT_MAX, ans = 0;
        solve(root, maxx, minn, ans);
        return ans;
    }
};