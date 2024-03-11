class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.size();
        unordered_map<char, int> pref;
        for(int i=0; i<n; i++) pref[order[i]]=i;

        int m = s.size();
        string ans = "";
        unordered_map<char, int> freq;
        for(int i=0; i<m; i++) {
            if(pref.count(s[i])) freq[s[i]]++;
            else ans+=s[i];
        }

        for(int i=0; i<n; i++) {
            int occ = freq[order[i]];
            while(occ--) {
                ans+=order[i];
            }
        }
        return ans;
    }
};