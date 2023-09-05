class Solution {
    int si = 0, maxLen = 0;
    void solve(string& s, int li, int ri) {
        while(li>=0 && ri<s.size() && s[li]==s[ri]) {
            li--;
            ri++;
        }
        if(maxLen < ri-li-1) {
            maxLen = ri-li-1;
            si = li+1;
        }
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            solve(s, i, i); //for a
            solve(s, i, i+1);//for aa
        }
        // cout << si << " - " << maxLen ;
        return s.substr(si, maxLen);
    }
};