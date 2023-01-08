class Solution {
    void solve(int ind, string cur, int ip_count, string& s, vector<string>& ans) {
        if(ip_count > 4) return;
        if(ip_count == 4 && ind == s.size()) {
            ans.push_back(cur); return; }
        
        for(int i=0; i<3; i++) {
            if(ind+i >= s.size()) break;
            string temp = s.substr(ind, i+1);
            if((temp[0] == '0' && temp.size() > 1) || (stoi(temp) >= 256))
                continue;
            solve(ind+i+1, cur + temp + (ip_count==3 ? "" : "."), ip_count+1, s, ans);
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(0, "", 0, s, ans);
        return ans;
    }
};