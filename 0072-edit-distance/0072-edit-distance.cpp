class Solution {
    int solve(int i, int j, string& word1, string& word2, vector<vector<int>>& dp) {
        int n = word1.length(), m=word2.length();
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(word1[i] == word2[j]) 
            return dp[i][j] = solve(i+1, j+1, word1, word2, dp);
        
        return dp[i][j] = 1 + min({solve(i+1, j, word1, word2, dp), solve(i+1, j+1, word1, word2, dp), solve(i, j+1, word1, word2, dp)});
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, word1, word2, dp);
    }
};

/*
"park"
"spake"
----------------
horse -> ros

rorse -> 

rose  
rosrse


orse
rhorse

*/