class Solution {
    void dfs(int r, int c, int matchColor, int newColor, 
    vector<vector<int>>& nums, vector<vector<int>>& vis) {
        int n = nums.size();
        int m = nums[0].size();
        if(r>=0 && c>=0 && r<n && c<m 
        && nums[r][c]==matchColor && !vis[r][c]) {
            nums[r][c] = newColor;
            vis[r][c]=1;
        }
        else return;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, 1, -1};
        for(int i=0; i<4; i++) {
            int row = r + dr[i];
            int col = c + dc[i];
            dfs(row, col, matchColor, newColor, nums, vis);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& nums, int sr, int sc, int newColor) {
        int n = nums.size();
        int m = nums[0].size();
        int matchColor = nums[sr][sc];
        vector<vector<int>> vis(n, vector<int>(m, 0));
        dfs(sr, sc, matchColor, newColor, nums, vis);
        return nums;
    }
};