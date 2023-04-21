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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        
        queue<pair<TreeNode*,unsigned long long>> q;
        int width = 0, l=0, r=0; 
        q.push({root, 0});
        
        while(q.size()) {
            int sz = q.size();
            auto start = q.front();
            int l = start.second;
            
            for(int i=0; i<sz; i++) {
                auto curr = q.front();
                r = curr.second;
                q.pop();
                
                if(curr.first->left)
                q.push({curr.first->left, curr.second*2+1});
                
                if(curr.first->right)
                q.push({curr.first->right, curr.second*2+2});
            }
            width = max(width, r-l+1);
        }
        return width;
    }
};