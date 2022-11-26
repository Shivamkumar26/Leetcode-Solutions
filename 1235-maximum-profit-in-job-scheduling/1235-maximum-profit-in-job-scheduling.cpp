class Solution {
    int find_lowerbound(int s, int e, int i, vector<vector<int>>& data) {
        int pos = -1;
        while(s <= e) {
            int mid = s+(e-s)/2;
            if(data[mid][0] >= data[i][1]) {
                pos = mid;
                e = mid-1;
            }
            else s = mid + 1;
        }
        return pos;
    }
    
    int solve(vector<vector<int>>& data, int i, vector<int>& dp) {
        if(i >= data.size()) return 0;
        if(dp[i] != -1) return dp[i];
        
        int pos = find_lowerbound(i+1, data.size()-1, i, data);
        
        int p = data[i][2] + solve(data, pos, dp);
        int np = solve(data, i+1, dp);
        return dp[i] = max(p, np);
    }
    
public:
    int jobScheduling(vector<int>& st, vector<int>& et, vector<int>& profit) {
        int n = st.size();
        vector<vector<int>> data;
        vector<int> dp(n+1, -1);
        for(int i=0; i<n; i++) {
            data.push_back({st[i], et[i], profit[i]});
        }
        sort(data.begin(), data.end());
        return solve( data, 0, dp);
    }
};