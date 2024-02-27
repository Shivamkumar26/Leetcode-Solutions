class Solution {
    bool solve(int i, string& s, set<string>& st, string temp, 
    vector<string>& ans, vector<int>& dp) {
        int n = s.size();
        if(i==n) {
            temp.pop_back();
            ans.push_back(temp);
            return 1;
        }
        if(dp[i] == 0) return dp[i];
        
        for(int j=i; j<n; j++) {
            string str = s.substr(i, j-i+1);
            if(st.count(str)) {
                solve(j+1, s, st, temp+str+" ", ans, dp);
                dp[i]=1;
            }
        }
        return dp[i] == 1 ? 1 : 0;
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st(wordDict.begin(), wordDict.end());
        
        int n = s.size();
        vector<int> dp(n+1, -1);
        
        vector<string> ans;
        string temp = "";
        
        solve(0, s, st, temp, ans, dp);
        return ans;
    }
};