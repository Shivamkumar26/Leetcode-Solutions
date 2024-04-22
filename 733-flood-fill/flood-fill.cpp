class Solution {
    void dfs(int r, int c, int col, int prev, vector<vector<int>>& nums, vector<vector<int>>& vis, int n, int m) {
        if(r<0 || c<0 || r>=n || c>=m || nums[r][c]!=prev || vis[r][c]==1)
        return;

        vis[r][c]=1;
        nums[r][c]=col;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int i=0; i<4; i++)
        dfs(r+dr[i], c+dc[i], col, prev, nums, vis, n, m);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc, int color) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int prev = nums[sr][sc];
        dfs(sr, sc, color, prev, nums, vis, n, m);
        return nums;
    }
};