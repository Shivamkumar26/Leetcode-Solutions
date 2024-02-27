class Solution {
    bool solve(int i, string& s, set<string>& st, vector<int>& dp) {
        int n = s.size();
        if(i==n) return true;
        if(dp[i]!=-1) return dp[i];
        
        for(int j=i; j<n; j++) {
            string str = s.substr(i, j-i+1);
            if(st.find(str)!=st.end()) {
                if(solve(j+1, s, st, dp)) return dp[i]=1;
            } 
        }
        return dp[i]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<int> dp(n+1, -1);
        return solve(0, s, st, dp);
    }
};