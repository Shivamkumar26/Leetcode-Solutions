class Solution {
    void dfs(int i, int j, vector<vector<char>>& board, int row) {
        int n = board.size(), m = board[0].size();
        if(i==n || j==m || board[i][j]=='.') return;

        board[i][j] = '_';
        if(row) dfs(i+1, j, board, row);
        else dfs(i, j+1, board, row);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]=='X') {
                    dfs(i, j, board, 0);
                    dfs(i, j, board, 1);
                    ans++;
                }
            }
        }
        return ans;
    }
};