class Solution {
    int solve(vector<int>& days, vector<int>& costs, int idx, vector<int>& dp) {
        if(idx >= days.size()) return 0;
        if(dp[idx]) return dp[idx];
        
        int i = idx+1;
        int a = costs[0] + solve(days, costs, i, dp);
        
        while(i < days.size() && days[i] - days[idx] < 7) i++;
        int b = costs[1] + solve(days, costs, i, dp);
        
        while(i < days.size() && days[i] - days[idx] < 30) i++;
        int c = costs[2] + solve(days, costs, i, dp);
        
        
        return dp[idx] = min({a, b, c});
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        sort(days.begin(), days.end());
        vector<int> dp(days.size(), 0);
        return solve(days, costs, 0, dp);
    }
};