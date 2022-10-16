class Solution {
    int solve(vector<int>& nums, int i, int remcut, vector<vector<int>>& dp) {
        if(i == nums.size() && remcut == 0) 
            return 0;
        
        if(i == nums.size() && remcut > 0 || i < nums.size() && remcut == 0)
            return INT_MAX;
        
        if(dp[i][remcut] != -1) 
            return dp[i][remcut];
        
        int mx = INT_MAX, mele = INT_MIN;
        for(int j = i; j<nums.size(); j++) {
            mele = max(mele, nums[j]);
            int a = solve(nums, j+1, remcut-1, dp);
            if(a == INT_MAX) continue;
            mx = min(mx, mele + a);
        }
        dp[i][remcut] = mx;
        return mx;
    }
public:
    int minDifficulty(vector<int>& nums, int d) {
        int n = nums.size();
        if(n < d) return -1;
        vector<vector<int>> dp(n+1, vector<int>(d+1, -1));
        return solve(nums, 0, d, dp);
    }
};