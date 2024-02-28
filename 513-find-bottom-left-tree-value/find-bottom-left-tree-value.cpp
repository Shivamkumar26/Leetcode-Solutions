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
    int height(TreeNode* root) {
        if(!root) return 0;
        
        return 1+max(height(root->left), height(root->right));
    }
    TreeNode* findNode(TreeNode* root, int ht, int cht) {
        if(cht == ht && root) return root;
        if(!root) return NULL;
        
        TreeNode* left = findNode(root->left, ht, cht+1);
        if(left) return left;
        return findNode(root->right, ht, cht+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        if(!root) return 0;
        int ht = height(root);
        TreeNode* res = findNode(root, ht, 1);
        if(!res) return 0;
        return res->val;
    }
};