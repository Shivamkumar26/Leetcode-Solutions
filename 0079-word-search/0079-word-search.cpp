class Solution {
    bool solve(vector<vector<char>>& board, string word, int r, int c) {
        if(word.size()==0) return true;
        if(r<0 || r==board.size() || c<0 || c==board[0].size() || word[0]!=board[r][c])
            return false;
        
        // move in 4 dir 
        board[r][c] = '#';
        string s = word.substr(1, word.size()-1);
        bool t =  solve(board, s, r+1, c) || 
                solve(board, s, r-1, c) || 
                solve(board, s, r, c+1) || 
                solve(board, s, r, c-1);
        board[r][c] = word[0];
        return t;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                bool found = solve(board, word, i, j);
                if(found) return true;
            }
        }
        return false;
    }
};

/*

a b c e
s f e s
a d e e 

a b c e s e e e f s 


[["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"],["A","A","A","A","A","A"]]
"AAAAAAAAAAAAAAB"

[["A","B","C","E"],["S","F","E","S"],["A","D","E","E"]]
"ABCESEEEFS"

*/