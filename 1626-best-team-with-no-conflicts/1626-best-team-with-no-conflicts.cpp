class Solution {
    int solve(vector<pair<int, int>>& nums, int i, int prevAge, vector<vector<int>>& dp, int n) {
        if(i>=n) return 0;
        if(dp[i][prevAge]!=-1) return dp[i][prevAge];
        
        int pick = 0, np = 0;
        if(nums[i].second >= prevAge) {
            pick = nums[i].first + solve(nums, i+1, nums[i].second, dp, n);
        }
        np = solve(nums, i+1, prevAge, dp, n);
        return dp[i][prevAge] = max(pick, np);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int, int>> nums;
        vector<vector<int>> dp(n+1, vector<int>(1001, -1));
        
        for(int i=0; i<n; i++) 
            nums.push_back({scores[i], ages[i]});
        
        sort(nums.begin(), nums.end());
        return solve(nums, 0, 0, dp, n);
    }
};