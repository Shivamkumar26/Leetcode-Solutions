class Solution {
public:
    bool detectCapitalUse(string s) {
        int n = s.size();
        int l = 0, u = 0;

        for(int i=0; i<n; i++) {
            if(s[i]>='A' && s[i]<='Z') {
                u++; 
                if(l>0) return false;
            }
            else l++;
        }
        return (u==0 || l==0 || u==1) ? true : false;
    }
};