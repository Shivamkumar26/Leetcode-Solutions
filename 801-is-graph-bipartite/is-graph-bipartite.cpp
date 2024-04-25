class Solution {
    bool check(int node, int col, vector<vector<int>>& nums, vector<int>& vis) {
        vis[node] = col;
        for(int i=0; i<nums[node].size(); i++) {
            if(vis[nums[node][i]] == -1) {
                if(check(nums[node][i], !col, nums, vis)==false)
                return false;
            }
            else if(vis[nums[node][i]]==col) return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> vis(n, -1);

        for(int i=0; i<n; i++) {
            if(vis[i]==-1) {
                if(check(i, 0, nums, vis)==false) return false;
            }
        }
        return true;
    }
};