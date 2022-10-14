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
    int maxLevel = 0;
    void solve(TreeNode* root, int level, int& sum) {
        if(!root->left && !root->right) {
            if(level == maxLevel) sum += root->val;
            else if(level > maxLevel)  {
                sum = root->val;
                maxLevel = level;
            }
            return;
        }
        if(root->left) solve(root->left, level+1, sum);
        if(root->right) solve(root->right, level+1, sum);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        solve (root, 0, sum);
        return sum;
    }
};