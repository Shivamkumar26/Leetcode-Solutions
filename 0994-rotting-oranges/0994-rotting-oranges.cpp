class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++) 
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == 2) q.push({i, j});
        
        int dr[] = {1, 0, 0, -1};
        int dc[] = {0, 1, -1, 0};
        
        int ans = -1;
        while(q.size()) {
            int sz = q.size();
            ans++;
            for(int i = 0; i < sz; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int d=0; d<4; d++) {
                    int new_r = r + dr[d];
                    int new_c = c + dc[d];
                    
                    if(new_r >= 0 && new_c >= 0 && new_r < n && new_c < m
                      && grid[new_r][new_c]==1) {
                        q.push({new_r, new_c});
                        grid[new_r][new_c] = 2;
                    }
                }
            }
        }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++)
            if(grid[i][j]==1) return -1;
        if(ans == -1) return 0;

        return ans;
    }
};