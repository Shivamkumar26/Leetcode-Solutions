class Solution {
    void solve(vector<vector<int>>& nums, int i, int j, vector<vector<int>>& vis, int n, int m, vector<int>& temp) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]!=0 || nums[i][j]==0) {
            return;
        }

        vis[i][j] = 1;
        temp[2] = max(temp[2], i);
        temp[3] = max(temp[3], j);
        solve(nums, i+1, j, vis, n, m, temp);
        solve(nums, i, j+1, vis, n, m, temp);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> ans;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(vis[i][j]==0 && nums[i][j]==1) {
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(i);
                    temp.push_back(j);
                    solve(nums, i, j, vis, n, m, temp);
                    ans.push_back(temp);
                }
            }
        }

        return ans;
    }
};