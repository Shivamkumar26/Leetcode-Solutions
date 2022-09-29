class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0, n = s.size(), cl = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ' && cl!=0) {
                len = cl;
                cl = 0;
            } 
            else if (s[i]==' ') continue;
            else cl++;
        }
        return cl==0 ? len : cl;
    }
};