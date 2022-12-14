class Solution {
    int solve(int r, int c, vector<vector<int>>& nums, vector<vector<int>>& dp) {
        if(r == nums.size()) return 0;
        if(dp[r][c] != -1) return dp[r][c];
        
        int lt = INT_MAX, st = INT_MAX, rt = INT_MAX;
        
        st = solve(r+1, c, nums, dp);
        if(c > 0) lt = solve(r+1, c-1, nums, dp);
        if(c < (nums[0].size()-1)) 
            rt = solve(r+1, c+1, nums, dp);
        
        return dp[r][c] = min({st, lt, rt}) + nums[r][c];
    }
public:
    int minFallingPathSum(vector<vector<int>>& nums) {
        int r = nums.size(), c = nums[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        int ans = INT_MAX;
        
        for(int i=0; i<c; i++)
            ans = min(ans, solve(0, i, nums, dp));
        return ans;
    }
};