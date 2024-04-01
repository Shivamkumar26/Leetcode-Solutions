class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int p = n-1, len=0;
        while(s[p]==' ') p--;
        while(p>=0 && s[p]!=' ') p--, len++;
        return len;
    }
};