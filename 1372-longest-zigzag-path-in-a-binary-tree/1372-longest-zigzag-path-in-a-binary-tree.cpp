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
    void solve(TreeNode* root, bool moveleft, int currlen, int& ans) {
        if(!root) return;
        ans = max(ans, currlen);
        
        if(moveleft) {
            solve(root->left, 0, currlen+1, ans);
            solve(root->right, 1, 1, ans);
        } else {
            solve(root->right, 1, currlen+1, ans);
            solve(root->left, 0, 1, ans);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        int len = 0;
        solve(root, 1, 0, len);
        solve(root, 0, 0, len);
        return len;
    }
};