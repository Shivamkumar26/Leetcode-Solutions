class Solution {
    int solve(int ind, int k, vector<vector<int>>& piles, vector<vector<int>>& dp) {
        if(k==0) return 0;
        if(ind==piles.size()) return INT_MIN;
        if(dp[ind][k] != -1) return dp[ind][k];
        
        int ans = INT_MIN, psize = piles[ind].size();
        for(int i=0; i<min(k, psize); i++) {
            ans = max(ans, piles[ind][i] + solve(ind+1, k-(i+1), piles, dp));
        }
        return dp[ind][k] = max(ans, solve(ind+1, k, piles, dp));
    }
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(1001, vector<int>(k+1, -1));
        
        int m = piles.size();
        for(int i=0; i<m; i++) {
            for(int j=1; j<piles[i].size(); j++) {
                piles[i][j] += piles[i][j-1];
            }
        }
        
        return solve(0, k, piles, dp);
    }
};

/*

k = 2

1 101 104
7 15  24

max(all permutations)

*/