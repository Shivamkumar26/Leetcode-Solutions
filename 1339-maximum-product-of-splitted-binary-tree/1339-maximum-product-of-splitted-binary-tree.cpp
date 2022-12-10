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
    long total = 0, csum = 0, ans = 0;
    int find(TreeNode* root) {
        if(!root) return 0;
        csum = find(root->left) + find(root->right) + root->val;
        ans = max(ans, (csum)*(total-csum));
        return csum;
    }
public:
    int maxProduct(TreeNode* root) {
        total = find(root);
        find(root);
        return ans % (int)(1e9+7);
    }
};