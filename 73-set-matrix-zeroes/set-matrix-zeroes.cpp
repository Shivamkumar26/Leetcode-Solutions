class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> r0(m, 1), c0(n, 1);
        
        if(grid[0][0]==0) r0[0]=0, c0[0]=0;
        for(int i=1; i<m; i++) {
            if(grid[0][i]==0) r0[i]=0, c0[0]=0;
        }
        for(int i=1; i<n; i++) {
            if(grid[i][0]==0) c0[i]=0, r0[0]=0;
        }
        
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(grid[i][j]==0) r0[j]=0, c0[i]=0;
            }
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(r0[j]==0 || c0[i]==0) grid[i][j] = 0;
            }
        }
        
        for(int i=0; i<n; i++) {
            cout << c0[i] << " ";
        }
        cout << "\n";
        for(int j=0; j<m; j++) {
            cout << r0[j] << " ";
        }
        //return grid;
    }
};