class Solution {
public:
    string getSmallestString(string s, int kk) {
        int k = kk, n = s.size();
        string ans = "";
        for(int i=0; i<n; i++) {
            if(s[i]=='a') ans+=s[i];
            else if(k>0){
                char ch = s[i], ch2 = s[i];
                while(k && ch!='a' && ch2!='a') {
                    ch += 1;
                    ch2 -= 1;
                    if(ch=='z'+1) ch='a';
                    if(ch2=='a'-1) ch2='z';
                    k--;
                }
                ans+=min(ch, ch2);
            }
            else ans+=s[i];
        }
        return ans;
    }
};
/*

zbbz

zbbz
aaaz


k=4
xaxcd
aaxcd
3


lol
lol

*/