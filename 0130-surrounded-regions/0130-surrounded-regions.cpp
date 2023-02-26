class Solution {
public:
     void dfs(int i, int j, vector<vector<char>>& mat) {
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size()) return;
        if(mat[i][j]=='X' || mat[i][j]=='-') return;
        
        mat[i][j]='-';
        dfs(i+1, j, mat);
        dfs(i-1, j, mat);
        dfs(i, j+1, mat);
        dfs(i, j-1, mat);
    }
public:
    void solve(vector<vector<char>>& mat)
    {
        int n = mat.size(), m = mat[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if((i==0 || j==0 || i==n-1 || j==m-1) && mat[i][j]=='O'){
                    dfs(i, j, mat);
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j] == '-') mat[i][j] = 'O';
                else mat[i][j] = 'X';
            }
        }
    }
};