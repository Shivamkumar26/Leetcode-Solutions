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
    void solve(TreeNode* root, int mn, int mx, int& ans) {
        if(abs(mn-mx) > ans) {
            ans = abs(mn-mx);
        }
        if(!root) return;
        mn = min(mn, root->val);
        mx = max(mx, root->val);
        solve(root->left, mn, mx, ans);
        solve(root->right, mn, mx, ans);
    }
public:
    //mn, mx 
    int maxAncestorDiff(TreeNode* root) {
        int mn = root->val, mx = root->val;
        int ans = 0;
        solve(root, mn, mx, ans);
        return ans;
    }
};