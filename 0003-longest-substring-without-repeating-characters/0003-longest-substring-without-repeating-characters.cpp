class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        int s = -1, mx = 0, n = st.size();
        unordered_map<char, int> mp;  
        
        for(int i = 0; i < n; i ++) {
            if(mp.find(st[i]) != mp.end()) {
                s = max(s, mp[st[i]]);
            }
            mp[st[i]] = i;
            mx = max(mx, i-s);
        }
        return mx;
    }
};