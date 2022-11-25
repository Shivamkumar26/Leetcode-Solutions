class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), ans = 0, mod = 1000000007;
        stack<int> s;
        vector<int> dp(n);
        
        for(int i = 0; i < n; i++) {
            while(s.size() && arr[s.top()] >= arr[i])
                s.pop();
            if(s.size()) dp[i] = dp[s.top()] + arr[i]*(i-s.top());
            else dp[i] = arr[i]*(i+1);
            ans = (ans + dp[i]) % mod;
            s.push(i);
        }
        return ans;
    }
};