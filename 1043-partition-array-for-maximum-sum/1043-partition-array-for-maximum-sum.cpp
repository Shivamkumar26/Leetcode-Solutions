class Solution {
    int solve(int i, int k, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int maxNum = INT_MIN, mx = 0, len = 0;
        for(int j = i; j < min(i+k, n); j++) {
            len ++;
            maxNum = max(maxNum, nums[j]);
            mx = max(mx, len*maxNum + solve(j+1, k, nums, dp));
        }
        return dp[i] = mx;
    }
public:
    int maxSumAfterPartitioning(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, k, nums, dp);
    }
};