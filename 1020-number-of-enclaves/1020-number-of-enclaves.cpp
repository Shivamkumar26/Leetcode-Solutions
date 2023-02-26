class Solution {
public:
    int numEnclaves(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        queue<pair<int, int>> q;
        
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++) {
            for(int j =0; j<m; j++) {
                if(i==0 || j==0 || i==n-1 || j==m-1)
                    if(nums[i][j]==1) {
                        q.push({i, j});
                        vis[i][j]=1;
                    }
            }
        }
        
        int dr[] = {0, 0, 1, -1};
        int dc[] = {-1, 1, 0, 0};
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++) {
                int r = row + dr[i];
                int c = col + dc[i];
                if(r<0 || c<0 || r>=n || c>=m || vis[r][c] || nums[r][c]!=1)
                    continue;
                q.push({r, c});
                vis[r][c] = 1;
            }
        }
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(nums[i][j]==1 && vis[i][j]==0)
                    ans++;
            }
        }
        return ans;
    }
};