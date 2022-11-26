class Solution {
    int find_lowerbound(int s, int e, int i, vector<vector<int>>& data) {
        int pos = -1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            (data[mid][0] >= data[i][1]) ? pos = mid, e = mid-1 : s = mid + 1;
        }
        return pos;
    }
    
    int solve(vector<vector<int>>& data, int i, vector<int>& dp) {
        if(i >= data.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int pos = find_lowerbound(i+1, data.size()-1, i, data);
        return dp[i] = max(solve(data, i + 1, dp), data[i][2] + solve(data, pos, dp));
    }
    
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        vector<vector<int>> data(n);
        vector<int> dp(n+1, -1);
        
        for(int i = 0; i < n; i++) data[i] = {st[i], et[i], profit[i]};
        sort(data.begin(), data.end());
        return solve(data, 0, dp);
    }
};