class Solution {
    int mod=1e9+7;
    
    int solve(int t, int s, int tar, int ct, vector<vector<int>>& dp) {       
        if(t==ct) {
            if(tar==0) return 1;
            return 0;
        } if(tar<=0) return 0;
        
        if(dp[ct][tar]!=-1) return dp[ct][tar];
        
        long long ans = 0;
        for(int i=1; i<=s; i++) {
             ans = ans + (solve(t, s, tar-i, ct+1, dp)) % mod;
        }
        return dp[ct][tar] = ans % mod;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> 
            dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, 0, dp);
    }
};