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
    bool isEvenOddTree(TreeNode* root) {
        int level = 0;
        
        queue<TreeNode* > q;
        q.push(root);
        
        while(q.size()) {
            int n = q.size();
            int prev = (level%2) ? INT_MAX : INT_MIN;
            
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                if(level % 2 == 0) {
                    if(prev >= node->val || node->val % 2 == 0) return false;
                    prev = node->val;
                } 
                else{
                    if(prev <= node->val || node->val % 2 == 1) return false;
                    prev = node->val;
                }
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            level++;
        }
        return true;
    }
};