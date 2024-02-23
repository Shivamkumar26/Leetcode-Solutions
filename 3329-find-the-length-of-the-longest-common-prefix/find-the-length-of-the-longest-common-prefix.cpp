class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size(), ans = 0;
        unordered_map<string, int> mp;
        
        for(int i = 0; i < n; i++) {
            string st = to_string(arr1[i]);
            for(int j = 0; j < st.size(); j++) {
                mp[st.substr(0, j+1)] = 1;
            }
        }
        for(int i = 0; i < m; i++) {
            string st = to_string(arr2[i]);
            for(int j = 0; j < st.size(); j++) {
                if(mp.count(st.substr(0, j+1)))
                    ans = max(ans, j+1);
            }
        }
        return ans;
    }
};