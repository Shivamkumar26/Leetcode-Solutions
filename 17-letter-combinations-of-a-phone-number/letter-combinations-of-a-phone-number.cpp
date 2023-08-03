class Solution {
    void solve(string digits, int ind, vector<string>& mp, string& temp, vector<string>& ans) {
        if(ind >= digits.size())  {
            ans.push_back(temp);
            return;
        }
        
        int dictInd = digits[ind]-'0';
        string s = mp[dictInd];
        for(int i = 0; i < s.size(); i++) {
            temp.push_back(s[i]);
            solve(digits, ind+1, mp, temp, ans);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string temp;
        vector<string> mp =
         {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(digits, 0, mp, temp, ans);
        return ans;
    }
};