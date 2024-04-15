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
    void solve(TreeNode* root, int& ans, string s) {
        if(!root) return;
        if(!root->left && !root->right) {
            s += (root->val + '0');
            ans += stoi(s);
            return;
        }

        s += (root->val + '0');
        solve(root->left, ans, s);
        solve(root->right, ans, s);
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root, ans, "");
        return ans;
    }
};