class Solution {
    int startIndex = -1, maxLen = 0;
    void formString(int l, int r, string s) {
        while(l>=0 && r<s.size() && s[l]==s[r]) {
            l--; r++;
        }
        if(maxLen < r-l-1) {
            maxLen = r-l-1;
            startIndex = l+1;
        }
        return;
    }
public:
    string longestPalindrome(string s) {
        string ans = "";
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            formString(i, i, s);
            formString(i, i+1, s);
        }
        ans = ans + s.substr(startIndex, maxLen);
        return ans;
    }
};