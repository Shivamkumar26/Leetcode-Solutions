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
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(!root) return root;
        if(depth == 2) {
            TreeNode* node = new TreeNode(val);
            TreeNode* node2 = new TreeNode(val);
            node->left = root->left;
            node2->right = root->right;
            root->left = node;
            root->right = node2;
            return root;
        }
        if(depth==1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        addOneRow(root->left, val, depth-1);
        addOneRow(root->right, val, depth-1);
        return root;
    }
};