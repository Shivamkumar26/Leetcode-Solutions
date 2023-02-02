class Solution {
    int solve(int i, vector<pair<int, int>>& nums, int prev, vector<vector<int>>& dp) {
        if(i == nums.size()) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];
        
        int pick = 0, notPick = 0;
        if(prev <= nums[i].second) 
            pick = nums[i].first + solve(i+1, nums, nums[i].second, dp);
        notPick = solve(i+1, nums, prev, dp);
        return dp[i][prev] = max(pick, notPick);
    }
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> nums;
        for(int i=0; i<scores.size(); i++) 
            nums.push_back({scores[i], ages[i]});
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(ages.size()+1, vector<int>(1001, -1));
        return solve(0, nums, 0, dp);
    }
};

/*

scores, ages
sort

prev <

*/