class Solution {
    void solve(vector<string>& ans, int o, int c, string str) {
        if(o > c) return;
        if(o<0 || c<0) return;
        if(o==0 && c==0) {
            ans.push_back(str);
            return;
        }
        solve(ans, o-1, c, str+"(");
        solve(ans, o, c-1, str+")");
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n, n, "");
        return ans;
    }
};

/*


n=3

1. open <= close (always)
2. open > 0 || close > 0


"", 3,3
"(",2,3 
"((",1,3   "()",2,2
""

*/