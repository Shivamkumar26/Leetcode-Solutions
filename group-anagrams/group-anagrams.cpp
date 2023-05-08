class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        int n = s.size();
        vector<vector<string>> ans;
        unordered_map<string, int> mp;

        for(int i=0; i<n; i++) {
            string curr = s[i];
            sort(curr.begin(), curr.end());
            if (mp.find(curr) == mp.end()) {
                ans.push_back({s[i]});
                mp[curr]=ans.size()-1;
            }
            else ans[mp[curr]].push_back(s[i]);
        }
        return ans;
    }
};