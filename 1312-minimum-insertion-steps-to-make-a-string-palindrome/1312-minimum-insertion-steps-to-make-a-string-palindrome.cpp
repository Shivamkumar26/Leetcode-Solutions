class Solution {
    int lps(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
        if(i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s1[i] == s2[j]) 
            return dp[i][j] = 1 + lps(s1, s2, i+1, j+1, dp);
        return dp[i][j] = max(lps(s1, s2, i+1, j, dp), lps(s1, s2, i, j+1, dp));
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        string s2 = s;
        reverse(s2.begin(), s2.end());
        
        return n - lps(s, s2, 0, 0, dp);
    }
};

/*

"mbadm"
"mdabm"

reverse find lcs
----------------

"leetcode"
a = 2+3 = 5
----------------

"abvfabb"

*/