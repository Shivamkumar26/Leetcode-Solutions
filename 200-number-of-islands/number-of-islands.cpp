class Solution {
    void solve(vector<vector<char>>& grid, int i, int j, int n, int m, vector<vector<int>>& vis) {
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]!=-1 || grid[i][j]!='1') 
            return;
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};
        vis[i][j] = 1;
        for(int k = 0; k < 4; k++) {
            int r = i + dr[k];
            int c = j + dc[k];
            solve(grid, r, c, n, m, vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));

        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]=='1' && vis[i][j]==-1) ans++;
                solve(grid, i, j, n, m, vis);
            }
        }
        return ans;
    }
};