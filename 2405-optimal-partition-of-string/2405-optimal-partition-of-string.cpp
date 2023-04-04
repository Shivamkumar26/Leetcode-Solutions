class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int ans = 0;
        int i = 0;
        
        while(i < n) {
            vector<int> freq(26, 0);
            while(i<n && freq[s[i]-'a']==0) {
                freq[s[i]-'a']++;
                i++;
            }
            ans++;
        }
        
        return ans;
    }
};