class Solution {
    void dfs(int r, int c, vector<vector<int>>& nums, vector<vector<int>>& vis) {
        int n = nums.size(), m = nums[0].size();
        if(r<0 || c<0 || r>=n || c>=m || nums[r][c]==0 || vis[r][c]==1) 
        return;

        vis[r][c] = 1;
        nums[r][c] = 0;

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};
        for(int i=0; i<4; i++) {
            int nr = r+dr[i], nc = c+dc[i];
            dfs(nr, nc, nums, vis);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++) {
            if(nums[i][0]==1) dfs(i, 0, nums, vis);
            if(nums[i][m-1]==1) dfs(i, m-1, nums, vis);
        }
        for(int j=0; j<m; j++) {
            if(nums[0][j]==1) dfs(0, j, nums, vis);
            if(nums[n-1][j]==1) dfs(n-1, j, nums, vis);
        }

        int count = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(nums[i][j]==1) count++;
            }
        }
        return count;
    }
};