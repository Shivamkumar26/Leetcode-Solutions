class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        set<string> st;
        vector<vector<string>> res;
        int n = strs.size();

        for(int i=0; i<n; i++) {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            if(st.find(cur) == st.end()) {
                st.insert(cur);
                res.push_back({strs[i]});
            }
            else {
                int sz = res.size();
                for(int j=0; j<sz; j++) {
                    string str = res[j][0];
                    sort(str.begin(), str.end());
                    if(cur == str) {
                        res[j].push_back(strs[i]);
                    }
                }
            }
        }
        return res;
    }
};