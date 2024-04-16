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
        if(!root) return NULL;
        if(depth==1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        if(depth==2) {
            TreeNode* nodel = new TreeNode(val);
            TreeNode* noder = new TreeNode(val);
            TreeNode* l = root->left;
            TreeNode* r = root->right;
            root->left = nodel;
            root->right = noder;
            nodel->left = l;
            noder->right = r;
            return root;
        }

        addOneRow(root->left, val, depth-1);
        addOneRow(root->right, val, depth-1);
        return root;
    }
};