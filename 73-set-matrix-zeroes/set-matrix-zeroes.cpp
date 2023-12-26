class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> r0(m, 1), c0(n, 1);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j]==0) r0[j]=0, c0[i]=0;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(r0[j]==0 || c0[i]==0) grid[i][j] = 0;
            }
        }
    }
};