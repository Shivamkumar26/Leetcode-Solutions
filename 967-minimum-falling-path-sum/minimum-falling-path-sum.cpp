class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) dp[n-1][i]=nums[n-1][i];
        
        for(int i=n-2; i>=0; i--) {
            for(int j=0; j<n; j++) {
                int mn = dp[i+1][j];
                if(j>0) mn = min(mn, dp[i+1][j-1]);
                if(j+1<n) mn = min(mn, dp[i+1][j+1]);
                dp[i][j] = nums[i][j] + mn;
            }
        }
        
        int res = INT_MAX;
        for(int i=0; i<n; i++) res=min(res, dp[0][i]);
        return res;
    }
};