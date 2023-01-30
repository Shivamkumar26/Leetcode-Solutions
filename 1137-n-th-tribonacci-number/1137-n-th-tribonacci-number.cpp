class Solution {
public:
    int ans(int n, vector<int>& dp) {
        if(dp[n]!=-1) return dp[n];
        return dp[n] = ans(n-1, dp) + ans(n-2, dp) + ans(n-3, dp);
    }
    int tribonacci(int n) {
        if(n<=1) return n;
        vector<int> dp(n+1, -1);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        return ans(n, dp);
    }
};