class Solution {
    bool searchword(int r, int c, vector<vector<char>>& board, string word) {
        if(word.size() == 0) return true;
        int n = board.size(), m = board[0].size();
        if(r<0 || c<0 || r>=n || c>=m || board[r][c]!=word[0])
            return false;
        
        board[r][c] = '#';
        bool ans = false;
        string wordd = word.substr(1, word.size()-1);
        ans = searchword(r+1, c, board, wordd) | 
            searchword(r, c+1, board, wordd) |
            searchword(r-1, c, board, wordd) | 
            searchword(r, c-1, board, wordd);
            
        board[r][c] = word[0];
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(searchword(i, j, board, word)) 
                    return true;
            }
        }
        return false;
    }
};