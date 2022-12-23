class Solution {
    int solve(int i, bool canBuy, int cprofit, vector<int>& nums, vector<vector<int>>& dp) {
        if(i >= nums.size()) return 0;
        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        
        int pickprofit = 0, np = 0;
        if(canBuy == 1) {
            pickprofit = -nums[i] + solve(i+1, !canBuy, cprofit-nums[i], nums, dp);
        }
        else {
            pickprofit = nums[i] + solve(i+2, !canBuy, cprofit+nums[i], nums, dp);
        }
        np = solve(i+1, canBuy, cprofit, nums, dp);
        
        return dp[i][canBuy] = max(pickprofit, np);
        
    }
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        
        bool canBuy = 1;
        return solve(0, canBuy, 0, nums, dp);
    }
};