class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string ans="";
        ans+=s[0];
        for(int i=1; i<n; i++) {
            if(ans.size() && (ans.back()==s[i]+32 || ans.back()==s[i]-32))
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};