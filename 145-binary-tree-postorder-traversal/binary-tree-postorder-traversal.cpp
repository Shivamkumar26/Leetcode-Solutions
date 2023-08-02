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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while(s1.size()) {
            TreeNode* t = s1.top();
            s2.push(t);
            s1.pop();

            if(t->left) s1.push(t->left);
            if(t->right) s1.push(t->right);
        }
        while(s2.size()) {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        return ans;
    }
};