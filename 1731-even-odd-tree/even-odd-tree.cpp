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
            vector<int> arr;
            
            for(int i=0; i<n; i++) {
                TreeNode* node = q.front();
                arr.push_back(node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level % 2 == 0) {
                if(arr[0]%2 == 0) return false;
                for(int i=1; i<arr.size(); i++) 
                    if(arr[i]<=arr[i-1] || arr[i]%2==0) return false;
            }
            else {
                if(arr[0]%2 == 1) return false;
                for(int i=1; i<arr.size(); i++) 
                    if(arr[i]>=arr[i-1] || arr[i]%2) return false;
            }
            level++;
        }
        return true;
    }
};