class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), ans = 0;
        set<string> mp;
        
        for(int i = 0; i < n; i++) {
            string st = to_string(arr1[i]);
            for(int j = 0; j < st.size(); j++) {
                mp.insert(st.substr(0, j+1));
            }
        }
        for(int i = 0; i < m; i++) {
            string st = to_string(arr2[i]);
            for(int j = 0; j < st.size(); j++) {
                if(mp.find(st.substr(0, j+1)) != mp.end())
                    ans = max(ans, j+1);
            }
        }
        return ans;
    }
};