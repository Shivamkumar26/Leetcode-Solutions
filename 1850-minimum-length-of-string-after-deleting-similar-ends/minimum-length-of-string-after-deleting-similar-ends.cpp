class Solution {
public:
    int minimumLength(string s) {
        int n = s.size(), l = 0, r = n-1, del = 0;
        char prev = '.';
        while(l < r) {
            if(s[l] == s[r]) {
                prev = s[l];
                l++, r--;
                del += 2;
            }
            else {
                if(prev == s[l]) l++, del++;
                else if(prev == s[r]) r--, del++;
                else break;
            }
        }
        if(l<n && l==r && prev == s[l]) del++;
        return n-del;
    }
};

/*

"ca"
"cabaabac"
"aabccabba"
"aaa"
"a"
"aacbccabbcca"
"aabccabbcccca"
"aacccbccabbca"

*/