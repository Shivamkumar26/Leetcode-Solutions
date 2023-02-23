class Solution {
    void dfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis[r][c] = 1;
            
            int dr[] = {1, -1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for(int i=0; i<4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m 
                && grid[nr][nc] == '1' && vis[nr][nc] == 0) {
                    dfs(nr, nc, vis, grid);
                }
            }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                if(!vis[i][j] && grid[i][j]=='1') {
                    dfs(i, j, vis, grid);
                    ans++;
                }
        return ans;
    }
};