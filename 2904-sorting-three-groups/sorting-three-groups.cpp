class Solution {
    int solve(vector<int>& nums, int i, int num, vector<vector<int>>& dp) {
        if(i==nums.size()) return 0;
        if(num > 3) return INT_MAX-100;
        if(dp[i][num] != -1) return dp[i][num];

        int ans = INT_MAX;
        if(nums[i] == num) ans = solve(nums, i+1, num, dp);
        else {
            if(nums[i] > num) ans = min(ans, solve(nums, i+1, nums[i], dp)); //case 3
            ans = min(ans, 1 + solve(nums, i+1, num, dp)); // case unequal
            ans = min(ans, 1 + solve(nums, i+1, num+1, dp)); 
        }
        return dp[i][num] = ans;
    }
public:
    int minimumOperations(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int>(4, -1));
        return solve(nums, 0, 1, dp);
    }
};