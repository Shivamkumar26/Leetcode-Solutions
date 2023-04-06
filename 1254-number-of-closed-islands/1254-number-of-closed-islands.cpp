class Solution {
    void solve(int r, int c,  vector<vector<int>>& visited,  vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        if(r<0 || r>n-1 || c<0 || c>=m || visited[r][c] || nums[r][c])
            return;
        visited[r][c] = 1;
        
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        for(int i=0; i<4; i++) {
            solve(r + dr[i], c + dc[i], visited, nums);
        }
    }
public:
    int closedIsland(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) 
            for(int j=0; j<m; j++) 
                if(i==0 || i==n-1 || j==0 || j==m-1) {
                    if(nums[i][j]==0) solve(i, j, visited, nums);
                    visited[i][j]=1;
                }

        
        int numOfIsland = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(i==0 || i==n-1 || j==0 || j==m-1) continue;
                if(nums[i][j]==0 && visited[i][j]==0) {
                    solve(i, j, visited, nums);
                    numOfIsland++;
                }
            }
        }
        return numOfIsland;
    }
};