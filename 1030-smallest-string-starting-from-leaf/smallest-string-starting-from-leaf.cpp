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
    void solve(TreeNode* root, string s, string& ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            s += (root->val + 'a');
            reverse(s.begin(), s.end());
            if(ans == "" || s < ans) 
                ans = s;
            return;
        }
        s += (root->val + 'a');
        solve(root->left, s, ans);
        solve(root->right, s, ans);
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        solve(root, "", ans);
        return ans;
    }
};