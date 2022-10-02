class Solution {
    int solve(string s, int idx, vector<int>& dp) {
        if(idx==s.size()) return 1;
        if(s[idx]=='0') return 0;
        if(idx==s.size()-1) return 1;
        
        if(dp[idx] != -1) return dp[idx];
        
        int onestep = 0, twostep = 0;
        onestep = solve(s, idx + 1, dp);
        int num = stoi(s.substr(idx, 2));
        if(num>=1 && num<=26) 
            twostep = solve(s, idx + 2, dp);
        return dp[idx] = onestep + twostep;
    }
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, -1);
        return solve(s, 0, dp);
    }
};