class Solution {
    /* Correct but memoization will give TLE */
    int solve(string colors, vector<int>& time, int idx, int prev, vector<vector<int>>& dp) {
        
        if(idx >= colors.size()) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        
        int p1 = INT_MAX, p2 = INT_MAX;
        if(prev == -1 || colors[prev] != colors[idx]) {
            p1 = solve(colors, time, idx+1, idx, dp);
        }
        p2 = time[idx] + solve(colors, time, idx+1, prev, dp);
        return dp[idx][prev+1] = min({p1, p2});
    }
public:
    int minCost(string colors, vector<int>& time) {
        int n=colors.size();
        vector<vector<int>> dp(n, vector<int>(27, 0));
        
        for(int i=0; i<27; i++) 
            if(colors[0]-'a'==i) dp[0][i] = time[0];
        
        for(int i=1; i<n; i++)
            for(int j=0; j<27; j++) {
                int p1 = INT_MAX, p2 = INT_MAX;
                int idx = colors[i]-'a';
                
                if(idx != j)
                    p1 = dp[i-1][idx];
                p2 = time[i] + dp[i-1][j];
                
                dp[i][j] = min(p1, p2);
            }
        
        return dp[n-1][26];
    }
};