class Solution {
    int solve(int i, int j, vector<vector<int>>& dp, string& word1, string& word2) {
        int n = word1.size(), m = word2.size();
        if(i == n) return m-j; 
        if(j == m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];
        
        
        int replace = solve(i+1, j+1, dp, word1, word2);
        if(word1[i] == word2[j]) return dp[i][j] =replace;
        int del1 = solve(i+1, j, dp, word1, word2);
        int del2 = solve(i, j+1, dp, word1, word2);
        return dp[i][j] = 1 + min({replace, del1, del2});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, dp, word1, word2);
    }
};