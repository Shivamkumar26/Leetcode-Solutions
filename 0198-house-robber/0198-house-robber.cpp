class Solution {
int solve(int i, bool canRobHouse, vector<int>& nums, vector<int>& dp) 
    {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
    
        int pick = nums[i], np = 0;
    
        pick += solve(i+2, canRobHouse, nums, dp);
        np += solve(i+1, canRobHouse, nums, dp);
    
        return dp[i] = max(pick, np);
        
        
    }
public:
    int rob(vector<int>& nums) {
        bool canRobHouse = true;
        int n = nums.size();
        vector<int> dp(n+1, -1);
        
        return solve(0, canRobHouse, nums, dp);
    }
};