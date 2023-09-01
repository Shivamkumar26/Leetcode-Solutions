class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int st = -1, len = 0;
        
        for(int i=0; i<n; i++) {
            if(mp.find(s[i]) != mp.end()) {
                st = max(st, mp[s[i]]);
            }
            mp[s[i]] = i;
            len = max(len, i-st);    
        }
        return len;
    }
};