class Solution {
    int solve(int i, string s, unordered_map<string, int>& mp, vector<int>& dp) {
        if(i == s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int ans = 1 + solve(i+1, s, mp, dp);
        string st = "";
        for(int j = i; j<s.size(); j++) {
            st += s[j];
            if(mp.find(st) != mp.end()) 
                ans = min(ans, solve(j+1, s, mp, dp));
        }
        return dp[i] = ans;
    }
public:
    int minExtraChar(string s, vector<string>& d) {
        unordered_map<string, int> mp;
        for(int i=0; i<d.size(); i++)
            mp[d[i]]++;
        
        vector<int> dp(s.size(), -1);
        return solve(0, s, mp, dp);
    }
};