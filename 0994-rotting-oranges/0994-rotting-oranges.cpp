class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j]==2) q.push({i, j});
            }
        }
        int minutes = -1;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while(!q.empty()) {
            int sz = q.size();
            minutes++;
            for(int i=0; i<sz; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int j = 0; j < 4; j++) {
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc]==1) {
                        grid[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
        }
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if(grid[i][j]==1) return -1;
        if(minutes==-1) return 0;
        return minutes;
    }
};