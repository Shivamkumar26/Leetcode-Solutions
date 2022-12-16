class Solution {
    int path(int r, int c, vector<vector<int>>& nums){
        if(r==nums.size()) return c;
        if(c<0 || c==nums[0].size()) return -1;
        
        if(nums[r][c]==1 && (c+1>=nums[0].size() || nums[r][c+1]==-1))
            return -1;
        if(nums[r][c]==-1 && (c-1<0 || nums[r][c-1]==1))
            return -1;
        
        return nums[r][c] == 1 ? path(r+1, c+1, nums) : path(r+1, c-1, nums);
    }
public:
    vector<int> findBall(vector<vector<int>>& nums) {
        int r=nums.size(), c=nums[0].size();
        vector<int>dp(c);
        for(int i=0; i<c; i++){
            dp[i] = path(0, i, nums);
        }
        return dp;
    }
};