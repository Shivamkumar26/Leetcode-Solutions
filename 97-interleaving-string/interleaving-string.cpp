class Solution {
    bool solve(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp) {
        if(i>=s1.size()) return s2.substr(j)==s3.substr(k);
        if(j>=s2.size()) return s1.substr(i)==s3.substr(k);

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j]) {
            if(s1[i]==s3[k])
                return dp[i][j] = solve(s1, s2, s3, i+1, j, k+1, dp) 
                || solve(s1, s2, s3, i, j+1, k+1, dp);
            else return dp[i][j] = 0;
        }
        else {
            if(s1[i]==s3[k]) 
            return dp[i][j] = solve(s1, s2, s3, i+1, j, k+1, dp);
            else if(s2[j]==s3[k]) 
            return dp[i][j] = solve(s1, s2, s3, i, j+1, k+1, dp);
            else return dp[i][j] = 0;
        }
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size(), m = s2.size();
        if(n + m != s3.size()) return 0;

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, s3, 0, 0, 0, dp);
    }
};