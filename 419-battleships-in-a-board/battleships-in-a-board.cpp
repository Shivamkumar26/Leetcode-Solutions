class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int ans = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(board[i][j]=='X' && ((j==0 || board[i][j-1]!='X') && 
                (i==0 || board[i-1][j]!='X')))
                ans ++;
                cout << ans << " ";
            }cout<<endl;
        }
        return ans;
    }
};