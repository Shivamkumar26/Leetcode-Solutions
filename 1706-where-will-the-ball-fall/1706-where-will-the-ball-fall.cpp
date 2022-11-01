class Solution {
public:
    int solve(int r, int c, vector<vector<int>>& nums) {
        if(r == nums.size()) return c;
        
        if(nums[r][c] == 1) {
            if(c+1 >= nums[0].size() || nums[r][c+1] == -1)
                return -1;
            return solve(r+1, c+1, nums);
        }
        else {
            if(c-1 < 0 || nums[r][c-1] == 1) 
                return -1;
            return solve(r+1, c-1, nums);
        }
    }
    vector<int> findBall(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        vector<int> ans(m);
        for(int j=0; j<m; j++) {
            ans[j] = solve(0, j, nums);
        }
        return ans;
    }
};