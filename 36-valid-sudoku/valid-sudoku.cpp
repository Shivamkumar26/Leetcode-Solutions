class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(board[i][j] == '.') continue;
                int num = board[i][j] - '0';

                // check row 
                for(int row = 0; row<9; row++) {
                    if(row!=i && board[row][j] == board[i][j]) return false;
                }
                // check col 
                for(int col = 0; col < 9; col++) {
                    if(col!=j && board[i][col] == board[i][j]) return false;
                }
                // check square 
                /*
                range check 
                (0-2), (3-5), (6-8)
                */
                for(int row=(i/3)*3; row < (i/3)*3+3; row++) {
                    for(int col = (j/3)*3; col < (j/3)*3+3; col++) {
                        if(row==i && col == j) continue;
                        if(board[row][col] == board[i][j]) return false;
                    }
                }
            }
        }
        return true;
    }
};