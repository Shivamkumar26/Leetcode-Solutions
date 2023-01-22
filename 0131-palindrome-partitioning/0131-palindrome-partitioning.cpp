class Solution {
    bool isPal(string str, int s, int e) {
        while(s<e) 
            if(str[s++]!=str[e--]) return false;
        return true;
    }
    
    void solve(int ind, string& s, vector<string>& temp, vector<vector<string>>& ans) {
        if(ind==s.size()) {
            ans.push_back(temp);
            return; 
        }
        
        for(int i = ind; i<s.size(); i++) {
            if(isPal(s, ind, i)) {
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, temp, ans);
        return ans;
    }
};