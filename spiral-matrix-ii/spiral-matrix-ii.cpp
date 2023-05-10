class Solution {
public:
    vector<vector<int>> generateMatrix(int side) {
        int n = side, m = n;
        int r1 = 0, r2 = n-1, c1 = 0, c2 = m-1;
        vector<vector<int>> ans(n, vector<int>(m, 0));
        
        int val = 1, dir = 1;
        while(r1<=r2 && c1<=c2) {
            if(dir == 1) {
                for(int i = c1; i <= c2; i++) 
                    ans[r1][i] = val++;
                r1++;
                dir = 2;
            }
            else if(dir == 2) {
                for(int i = r1; i <= r2; i++) 
                    ans[i][c2] = val++;
                c2--;
                dir = 3;
            }
            else if(dir == 3) {
                for(int i = c2; i >= c1; i--) 
                    ans[r2][i] = val++;
                r2--;
                dir = 4;
            }
            else {
                for(int i = r2; i >= r1; i--) 
                    ans[i][c1] = val++;
                c1++;
                dir = 1;
            }
        }
        return ans;
    }
};