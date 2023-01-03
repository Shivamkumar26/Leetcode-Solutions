//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    void dfs(int r, int c, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        int n = grid.size(), m = grid[0].size();
        if(r<0 || c<0 || r>n-1 || c>m-1 || vis[r][c]==1 || grid[r][c]=='X') 
        return;
        
        vis[r][c]=1;
        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        
        for(int i=0; i<4; i++){
            int cr = r+dr[i];
            int cc = c+dc[i];
            dfs(cr, cc, grid, vis);
        }
    }
public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> grid) {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i=0; i<m; i++) {
            if(!vis[0][i] && grid[0][i]=='O') 
                dfs(0, i, grid, vis);
            if(!vis[n-1][i] && grid[n-1][i]=='O')
                dfs(n-1, i, grid, vis);
        }
        for(int i=0; i<n; i++) {
            if(!vis[i][0] && grid[i][0]=='O') 
            dfs(i, 0, grid, vis);
            if(!vis[i][m-1] && grid[i][m-1]=='O')
            dfs(i, m-1, grid, vis);
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(!vis[i][j] && grid[i][j]=='O')
                grid[i][j]='X';
            }
        }
        return grid;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends