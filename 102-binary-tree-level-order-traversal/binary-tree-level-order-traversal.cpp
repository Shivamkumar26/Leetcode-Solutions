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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(!root) return ans;

        q.push(root);

        while(q.size()) {
            int n = q.size();
            vector<int> temp;
            for(int i=0; i<n; i++) {
                TreeNode* t = q.front();
                temp.push_back(t->val);
                q.pop();

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

/*

    1
 2    3 
4 5  6 7




1,0
2,1 3,1
4,2 6,2
5,2 7,2



*/