class Solution {
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if(i==s1.size() || j==s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int one = 0, two = 0, three = 0;
        if(s1[i] == s2[j]) three = 1 + solve(i+1, j+1, s1, s2, dp);
        else {
            one = solve(i+1, j, s1, s2, dp);
            two = solve(i, j+1, s1, s2, dp);
        }
        return dp[i][j] = max({one, two, three});
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, text1, text2, dp);
    }
};