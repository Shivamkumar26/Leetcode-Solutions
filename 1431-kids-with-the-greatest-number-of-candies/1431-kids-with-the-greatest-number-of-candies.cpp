class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& c, int ec) {
        vector<bool> ans;
        int n = c.size(), mx = -1;
        for(int i=0; i<n; i++) {
            mx= max(mx, c[i]);
        } 
        for(int i=0; i<n; i++) {
            if(c[i]+ec>=mx) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};