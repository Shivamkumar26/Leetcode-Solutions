class Solution {
    void solve(int i, int j, int count, int& ans, vector<vector<int>>& nums) {
        if(i<0 || j<0 || i>=nums.size() || j>=nums[0].size() || nums[i][j]==-1) return;
        if(nums[i][j]==2) {
            if((count-1)==0) ans++;
            return;
        }
        
        nums[i][j] = -1;
        solve(i+1, j, count-1, ans, nums);
        solve(i, j+1, count-1, ans, nums);
        solve(i-1, j, count-1, ans, nums);
        solve(i, j-1, count-1, ans, nums);
        nums[i][j] = 1;
    }
public:
    int uniquePathsIII(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums[0].size();
        int count = 0, si = -1, sj = -1;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(nums[i][j]==0 || nums[i][j]==2)
                    count++;
                else if(nums[i][j]==1) {
                    si = i;
                    sj = j;
                    count++;
                }
            }
        }
        int ans = 0;
        solve(si, sj, count, ans, nums);
        return ans;
    }
};