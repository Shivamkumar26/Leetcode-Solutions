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
    void solve(TreeNode* root, int& ans) {
        if(!root) return;
        if(root->left) {
            TreeNode* child = root->left;
            if(!child->left && !child->right) ans+=child->val;
            // return;
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};