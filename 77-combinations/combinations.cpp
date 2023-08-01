class Solution {
    void solve(int c, int n, int k, vector<int>& temp, vector<vector<int>>& ans) {
        if(temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for(int i=c; i<=n; i++) {
            temp.push_back(i);
            solve(i+1, n, k, temp, ans);
            temp.pop_back();
        }
       
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, k, temp, ans);
        return ans;
    }
};

/*
n=4 ,k=3


n=1, k=1 ans = 1
n=4 k=0

123,124,134,234

*/