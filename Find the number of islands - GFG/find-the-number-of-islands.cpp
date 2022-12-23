//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    void bfs(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        
        q.push({r,c});
        vis[r][c] = 1;
        
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(int new_r = -1; new_r<=1; new_r++)
                for(int new_c = -1; new_c<=1; new_c++) {
                    int nr = r + new_r;
                    int nc = c + new_c;
                    if (nr > 0 && nc > 0 && nr < n && nc < m 
                    && grid[nr][nc] == '1' && vis[nr][nc] == 0) {
                        vis[nr][nc]=1;
                        q.push({nr, nc});
                    }
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
                    bfs(i, j, vis, grid);
                    ans++;
                }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends