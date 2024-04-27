class Solution {
    int solve(int i, int prev, string& s, int k, vector<vector<int>>& dp) {
        int n = s.size();
        if(i>=n) return 0;
        if(dp[i][prev]!=-1) return dp[i][prev];

        int ans = 0;
        if(prev==26 || abs((s[i]-'a') - prev) <= k) {
            ans = max(1 + solve(i+1, s[i]-'a', s, k, dp), solve(i+1, prev, s, k, dp));
        }
        else ans = solve(i+1, prev, s, k, dp);
        return dp[i][prev] = ans;
    }
public:
    int longestIdealString(string s, int k) {
        int n = s.size(), ans = 0;
        vector<vector<int>> dp(n, vector<int>(27, -1));

        // prev storing the alphabetical index of last character 0-'a';
        return solve(0, 26, s, k, dp);
    }
};
/*

acfgbd
k=2

pick, not pick


*/