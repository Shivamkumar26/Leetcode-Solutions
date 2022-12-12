class Solution {
    int steps(int i, vector<int>& dp, int& n) {
        if(i==n) return 1;
        if(i > n) return 0;
        if(dp[i]!=-1) return dp[i];
        
        int oneJump = steps(i+1, dp, n);
        int twoJump = steps(i+2, dp, n);
        
        return dp[i] = oneJump + twoJump;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return steps(0, dp, n);
    }
};
/***

4
1 1 1 1 

*/