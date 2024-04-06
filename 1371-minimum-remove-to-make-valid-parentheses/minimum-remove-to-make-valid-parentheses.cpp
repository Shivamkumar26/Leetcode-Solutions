class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size(), op = 0, cl = 0;
        string ans = "";
        for(int i=0; i<n; i++) {
            if(s[i]==')') cl++;
            else if(s[i]=='(') op++;
            if(cl > op) {
                cl--;
            }
            else {
                ans += s[i];
            }
        }
        n = ans.size();
        op = 0, cl = 0;

        cout << ans << " \n";
        s="";
        for(int i=n-1; i>=0; i--) {
            if(ans[i]=='(') cl--;
            else if(ans[i]==')') cl++;
            if(cl >= 0) s += ans[i];
            else cl=0;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};