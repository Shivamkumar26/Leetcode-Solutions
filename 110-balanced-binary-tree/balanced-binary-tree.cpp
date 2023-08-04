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
    int heightDiff(TreeNode* root) {
        if(!root) return 0;

        int lh = heightDiff(root->left);
        int rh = heightDiff(root->right);
        if(lh == -1 || rh == -1 || abs(lh-rh) > 1) return -1;

        return 1 + max(lh, rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int h = heightDiff(root);
        return h == -1 ? false : true;
    }
};