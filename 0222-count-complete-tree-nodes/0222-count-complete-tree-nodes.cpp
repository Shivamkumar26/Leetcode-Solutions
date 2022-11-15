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
    int lh(TreeNode* root) {
        if(!root) return 0;
        int h = 1;
        while(root->left) {
            root=root->left;
            h++;
        }
        return h;
    }
    int rh(TreeNode* root) {
        if(!root) return 0;
        int h = 1;
        while(root->right) {
            root=root->right;
            h++;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lheight = lh(root);
        int rheight = rh(root);
        // cout << "lheight - " << lheight << endl;
        // cout << "rheight - " << rheight << endl;
        if(lheight == rheight) return pow(2, lheight)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};