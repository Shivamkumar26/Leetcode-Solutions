class Solution {
    int solve(int i, int t, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(i>=n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        
        return dp[i][t] = max(solve(i+1, t, nums, dp), 
                              nums[i]*t + solve(i+1, t+1, nums, dp));
    }
public:
    int maxSatisfaction(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        sort(nums.begin(), nums.end());
        
        return max(0, solve(0, 1, nums, dp));
    }
};